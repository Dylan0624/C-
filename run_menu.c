/**
 * 檔案名稱: run_menu.c
 * 描述: 一個簡單的選單系統，用於編譯和執行C程式，並在執行後自動清理編譯產物
 * 
 * 編譯指令: gcc -o run_menu run_menu.c
 * 執行指令: ./run_menu
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <dirent.h>
 #include <sys/stat.h>
 
 #define MAX_FILES 100
 #define MAX_FILENAME 256
 #define MAX_PATH 512
 #define MAX_COMMAND 1024
 
 // 源碼目錄
 #define SRC_DIR "src"
 #define BIN_DIR "bin"
 
 // 結構體以保存檔案信息
 typedef struct {
     char path[MAX_PATH];      // 完整路徑
     char name[MAX_FILENAME];  // 文件名
     char category[MAX_FILENAME]; // 分類目錄
 } FileInfo;
 
 // 資料儲存
 FileInfo files[MAX_FILES];
 int file_count = 0;
 
 // 函數宣告
 void scan_directories();
 void scan_directory(const char *dir_path, const char *category);
 void display_menu();
 void compile_and_run(int choice);
 void clear_screen();
 void cleanup_executable(const char *executable);
 int is_directory(const char *path);
 
 int main() {
     int choice;
     
     // 確保目錄存在
     mkdir(BIN_DIR, 0755);
     
     // 掃描源碼目錄尋找C檔案
     scan_directories();
     
     while (1) {
         clear_screen();
         display_menu();
         
         printf("請選擇 (0-%d): ", file_count);
         scanf("%d", &choice);
         
         if (choice == 0) {
             printf("再見！\n");
             break;
         } else if (choice >= 1 && choice <= file_count) {
             compile_and_run(choice);
             
             printf("\n按Enter鍵繼續...");
             getchar(); // 消耗前一個scanf中的換行符
             getchar(); // 等待用戶按Enter
         } else {
             printf("無效的選擇，請重試！\n");
             printf("按Enter鍵繼續...");
             getchar(); // 消耗前一個scanf中的換行符
             getchar(); // 等待用戶按Enter
         }
     }
     
     return 0;
 }
 
 // 檢查是否為目錄
 int is_directory(const char *path) {
     struct stat statbuf;
     if (stat(path, &statbuf) != 0) {
         return 0;
     }
     return S_ISDIR(statbuf.st_mode);
 }
 
 // 掃描所有源碼目錄
 void scan_directories() {
     // 檢查源碼目錄是否存在
     if (!is_directory(SRC_DIR)) {
         printf("錯誤: 源碼目錄 '%s' 不存在\n", SRC_DIR);
         exit(1);
     }
     
     // 掃描主源碼目錄
     DIR *d;
     struct dirent *dir;
     char path[MAX_PATH];
     
     d = opendir(SRC_DIR);
     if (d) {
         while ((dir = readdir(d)) != NULL) {
             // 跳過 . 和 ..
             if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                 continue;
             }
             
             // 建立完整路徑
             snprintf(path, MAX_PATH, "%s/%s", SRC_DIR, dir->d_name);
             
             // 如果是目錄，掃描其中的C文件
             if (is_directory(path)) {
                 scan_directory(path, dir->d_name);
             }
         }
         closedir(d);
     }
 }
 
 // 掃描指定目錄尋找C檔案
 void scan_directory(const char *dir_path, const char *category) {
     DIR *d;
     struct dirent *dir;
     char path[MAX_PATH];
     
     d = opendir(dir_path);
     if (d) {
         while ((dir = readdir(d)) != NULL && file_count < MAX_FILES) {
             // 檢查檔案是否以.c結尾
             char *ext = strrchr(dir->d_name, '.');
             if (ext && strcmp(ext, ".c") == 0) {
                 // 建立完整路徑
                 snprintf(path, MAX_PATH, "%s/%s", dir_path, dir->d_name);
                 
                 // 記錄檔案信息
                 strncpy(files[file_count].path, path, MAX_PATH - 1);
                 files[file_count].path[MAX_PATH - 1] = '\0';
                 
                 strncpy(files[file_count].name, dir->d_name, MAX_FILENAME - 1);
                 files[file_count].name[MAX_FILENAME - 1] = '\0';
                 
                 strncpy(files[file_count].category, category, MAX_FILENAME - 1);
                 files[file_count].category[MAX_FILENAME - 1] = '\0';
                 
                 file_count++;
             }
         }
         closedir(d);
     }
 }
 
 // 顯示選單
 void display_menu() {
     printf("===== C程式執行選單 =====\n\n");
     
     char current_category[MAX_FILENAME] = "";
     
     for (int i = 0; i < file_count; i++) {
         // 如果是新類別，顯示類別標題
         if (strcmp(current_category, files[i].category) != 0) {
             strcpy(current_category, files[i].category);
             printf("\n--- %s ---\n", current_category);
         }
         
         printf("%d. %s\n", i + 1, files[i].name);
     }
     
     printf("\n0. 退出\n\n");
 }
 
 // 編譯並執行所選的程式
 void compile_and_run(int choice) {
     char command[MAX_COMMAND];
     char executable[MAX_PATH];
     FileInfo *selected = &files[choice - 1];
     
     // 建立可執行檔路徑 (基於源碼路徑)
     snprintf(executable, MAX_PATH, "%s/%s/%s", BIN_DIR, selected->category, selected->name);
     
     // 移除.c擴展名
     char *dot = strrchr(executable, '.');
     if (dot) {
         *dot = '\0';
     }
     
     // 確保bin目錄存在
     char bin_dir[MAX_PATH];
     snprintf(bin_dir, MAX_PATH, "%s/%s", BIN_DIR, selected->category);
     mkdir(bin_dir, 0755);
     
     // 特殊處理多文件程式
     if (strcmp(selected->name, "multi_file_main.c") == 0) {
         // 多文件編譯
         snprintf(command, MAX_COMMAND, "gcc -Wall -o %s/%s/multi_file_program %s/multi_file/*.c", 
                  BIN_DIR, selected->category, SRC_DIR);
         
         printf("正在編譯多文件程式...\n");
         int compile_result = system(command);
         
         if (compile_result == 0) {
             printf("編譯成功！正在執行...\n\n");
             printf("===== 程式輸出 =====\n");
             
             // 執行程式
             snprintf(command, MAX_COMMAND, "%s/%s/multi_file_program", BIN_DIR, selected->category);
             system(command);
         } else {
             printf("編譯失敗！\n");
         }
         
         return;
     }
     
     // 一般C檔案編譯
     snprintf(command, MAX_COMMAND, "gcc -Wall -o %s %s", executable, selected->path);
     
     printf("正在編譯 %s...\n", selected->name);
     int compile_result = system(command);
     
     if (compile_result == 0) {
         printf("編譯成功！正在執行...\n\n");
         printf("===== 程式輸出 =====\n");
         
         // 執行程式
         snprintf(command, MAX_COMMAND, "%s", executable);
         system(command);
     } else {
         printf("編譯失敗！\n");
     }
 }
 
 // 清除屏幕
 void clear_screen() {
     #ifdef _WIN32
         system("cls");
     #else
         system("clear");
     #endif
 }