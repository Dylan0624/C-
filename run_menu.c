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
 
 #define MAX_FILES 100
 #define MAX_FILENAME 256
 #define MAX_COMMAND 512
 
 // 數組以保存檔案名稱
 char files[MAX_FILES][MAX_FILENAME];
 int file_count = 0;
 
 // 函數宣告
 void scan_directory();
 void display_menu();
 void compile_and_run(int choice);
 void clear_screen();
 void cleanup_executable(const char *executable);
 
 int main() {
     int choice;
     
     // 掃描目錄尋找C檔案
     scan_directory();
     
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
 
 // 掃描當前目錄尋找C檔案
 void scan_directory() {
     DIR *d;
     struct dirent *dir;
     
     d = opendir(".");
     if (d) {
         while ((dir = readdir(d)) != NULL) {
             // 檢查檔案是否以.c結尾
             char *ext = strrchr(dir->d_name, '.');
             if (ext && strcmp(ext, ".c") == 0) {
                 // 排除此菜單程式本身
                 if (strcmp(dir->d_name, "run_menu.c") != 0) {
                     strncpy(files[file_count], dir->d_name, MAX_FILENAME - 1);
                     files[file_count][MAX_FILENAME - 1] = '\0'; // 確保字串結尾
                     file_count++;
                     
                     if (file_count >= MAX_FILES) {
                         break; // 防止溢出
                     }
                 }
             }
         }
         closedir(d);
     }
 }
 
 // 顯示選單
 void display_menu() {
     printf("===== C程式執行選單 =====\n\n");
     
     for (int i = 0; i < file_count; i++) {
         printf("%d. %s\n", i + 1, files[i]);
     }
     
     printf("0. 退出\n\n");
 }
 
 // 編譯並執行所選的程式
 void compile_and_run(int choice) {
     char command[MAX_COMMAND];
     char executable[MAX_FILENAME];
     
     // 建立可執行檔名稱 (移除.c擴展名)
     strncpy(executable, files[choice - 1], MAX_FILENAME - 1);
     executable[MAX_FILENAME - 1] = '\0';
     
     char *dot = strrchr(executable, '.');
     if (dot) {
         *dot = '\0';
     }
     
     // 建立編譯指令
     snprintf(command, MAX_COMMAND, "gcc -Wall -o %s %s", executable, files[choice - 1]);
     
     printf("正在編譯 %s...\n", files[choice - 1]);
     int compile_result = system(command);
     
     if (compile_result == 0) {
         printf("編譯成功！正在執行...\n\n");
         printf("===== 程式輸出 =====\n");
         
         // 建立執行指令
         #ifdef _WIN32
             snprintf(command, MAX_COMMAND, "%s", executable);
         #else
             snprintf(command, MAX_COMMAND, "./%s", executable);
         #endif
         
         system(command);
         
         // 清理編譯產生的執行檔
         cleanup_executable(executable);
     } else {
         printf("編譯失敗！\n");
     }
 }
 
 // 清理編譯產生的執行檔
 void cleanup_executable(const char *executable) {
     char command[MAX_COMMAND];
     
     #ifdef _WIN32
         snprintf(command, MAX_COMMAND, "del %s.exe", executable);
     #else
         snprintf(command, MAX_COMMAND, "rm -f %s", executable);
     #endif
     
     printf("\n正在清理編譯產物...");
     system(command);
     printf("完成！\n");
 }
 
 // 清除屏幕
 void clear_screen() {
     #ifdef _WIN32
         system("cls");
     #else
         system("clear");
     #endif
 }