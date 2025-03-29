/**
 * 檔案名稱: file_operations.c
 * 描述: 演示C語言中檔案的基本輸入輸出操作
 * 
 * 編譯指令: gcc -o file_operations file_operations.c
 * 執行指令: ./file_operations
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define MAX_LINE 1000
 #define FILENAME_TEXT "test_file.txt"
 #define FILENAME_BIN "test_file.bin"
 #define FILENAME_CSV "test_file.csv"
 
 // 結構體用於二進位檔案讀寫
 struct Person {
     int id;
     char name[50];
     int age;
 };
 
 // 函數宣告
 void writeTextFile();
 void readTextFile();
 void appendToTextFile();
 void writeBinaryFile();
 void readBinaryFile();
 void randomAccessFile();
 void writeCSVFile();
 void readCSVFile();
 void fileExists(const char *filename);
 void copyFile(const char *source, const char *destination);
 
 int main() {
     int choice;
     
     printf("===== 檔案操作示例 =====\n\n");
     printf("1. 寫入文字檔案\n");
     printf("2. 讀取文字檔案\n");
     printf("3. 追加到文字檔案\n");
     printf("4. 寫入二進位檔案\n");
     printf("5. 讀取二進位檔案\n");
     printf("6. 隨機存取檔案\n");
     printf("7. 寫入CSV檔案\n");
     printf("8. 讀取CSV檔案\n");
     printf("9. 檢查檔案是否存在\n");
     printf("10. 複製檔案\n");
     printf("0. 退出\n\n");
     
     printf("請選擇操作 (0-10): ");
     scanf("%d", &choice);
     
     switch (choice) {
         case 1:
             writeTextFile();
             break;
         case 2:
             readTextFile();
             break;
         case 3:
             appendToTextFile();
             break;
         case 4:
             writeBinaryFile();
             break;
         case 5:
             readBinaryFile();
             break;
         case 6:
             randomAccessFile();
             break;
         case 7:
             writeCSVFile();
             break;
         case 8:
             readCSVFile();
             break;
         case 9:
             printf("請輸入要檢查的檔案名: ");
             char filename[100];
             scanf("%99s", filename);
             fileExists(filename);
             break;
         case 10:
             copyFile(FILENAME_TEXT, "test_file_copy.txt");
             break;
         case 0:
             printf("程式結束。\n");
             break;
         default:
             printf("無效的選擇！\n");
     }
     
     return 0;
 }
 
 // 寫入文字檔案
 void writeTextFile() {
     FILE *file = fopen(FILENAME_TEXT, "w");
     
     if (file == NULL) {
         printf("無法創建檔案 %s\n", FILENAME_TEXT);
         return;
     }
     
     fprintf(file, "這是第一行文字。\n");
     fprintf(file, "這是第二行文字。\n");
     fprintf(file, "這是第三行文字，包含數字 %d 和 %f。\n", 42, 3.14);
     
     fclose(file);
     printf("成功寫入文字檔案 %s\n", FILENAME_TEXT);
 }
 
 // 讀取文字檔案
 void readTextFile() {
     FILE *file = fopen(FILENAME_TEXT, "r");
     
     if (file == NULL) {
         printf("無法開啟檔案 %s\n", FILENAME_TEXT);
         return;
     }
     
     char line[MAX_LINE];
     printf("\n檔案 %s 的內容：\n", FILENAME_TEXT);
     printf("------------------\n");
     
     while (fgets(line, MAX_LINE, file) != NULL) {
         printf("%s", line);
     }
     
     printf("------------------\n");
     fclose(file);
 }
 
 // 追加到文字檔案
 void appendToTextFile() {
     FILE *file = fopen(FILENAME_TEXT, "a");
     
     if (file == NULL) {
         printf("無法開啟檔案 %s\n", FILENAME_TEXT);
         return;
     }
     
     fprintf(file, "這是追加的文字。\n");
     fprintf(file, "追加時間: %s %s\n", __DATE__, __TIME__);
     
     fclose(file);
     printf("成功追加到檔案 %s\n", FILENAME_TEXT);
 }
 
 // 寫入二進位檔案
 void writeBinaryFile() {
     FILE *file = fopen(FILENAME_BIN, "wb");
     
     if (file == NULL) {
         printf("無法創建檔案 %s\n", FILENAME_BIN);
         return;
     }
     
     struct Person persons[] = {
         {1, "張三", 25},
         {2, "李四", 30},
         {3, "王五", 22}
     };
     
     size_t num_persons = sizeof(persons) / sizeof(struct Person);
     size_t written = fwrite(persons, sizeof(struct Person), num_persons, file);
     
     if (written != num_persons) {
         printf("寫入錯誤！\n");
     } else {
         printf("成功寫入 %zu 筆資料到二進位檔案 %s\n", written, FILENAME_BIN);
     }
     
     fclose(file);
 }
 
 // 讀取二進位檔案
 void readBinaryFile() {
     FILE *file = fopen(FILENAME_BIN, "rb");
     
     if (file == NULL) {
         printf("無法開啟檔案 %s\n", FILENAME_BIN);
         return;
     }
     
     struct Person person;
     printf("\n檔案 %s 的內容：\n", FILENAME_BIN);
     printf("------------------\n");
     printf("ID\t姓名\t年齡\n");
     
     while (fread(&person, sizeof(struct Person), 1, file) == 1) {
         printf("%d\t%s\t%d\n", person.id, person.name, person.age);
     }
     
     printf("------------------\n");
     fclose(file);
 }
 
 // 隨機存取檔案
 void randomAccessFile() {
     // 先確保檔案存在，如果不存在則建立它
     writeBinaryFile();
     
     FILE *file = fopen(FILENAME_BIN, "r+b");
     
     if (file == NULL) {
         printf("無法開啟檔案 %s\n", FILENAME_BIN);
         return;
     }
     
     // 讀取第二個記錄 (索引從0開始)
     struct Person person;
     fseek(file, sizeof(struct Person), SEEK_SET);
     fread(&person, sizeof(struct Person), 1, file);
     
     printf("\n讀取第二個記錄：\n");
     printf("ID: %d, 姓名: %s, 年齡: %d\n", person.id, person.name, person.age);
     
     // 修改第二個記錄並寫回
     strcpy(person.name, "李四（已修改）");
     person.age = 31;
     
     fseek(file, sizeof(struct Person), SEEK_SET);
     fwrite(&person, sizeof(struct Person), 1, file);
     
     printf("已修改第二個記錄\n");
     
     // 回到檔案開頭，重新讀取所有記錄
     rewind(file);
     
     printf("\n修改後的檔案內容：\n");
     printf("------------------\n");
     printf("ID\t姓名\t年齡\n");
     
     while (fread(&person, sizeof(struct Person), 1, file) == 1) {
         printf("%d\t%s\t%d\n", person.id, person.name, person.age);
     }
     
     printf("------------------\n");
     fclose(file);
 }
 
 // 寫入CSV檔案
 void writeCSVFile() {
     FILE *file = fopen(FILENAME_CSV, "w");
     
     if (file == NULL) {
         printf("無法創建檔案 %s\n", FILENAME_CSV);
         return;
     }
     
     // 寫入標題行
     fprintf(file, "ID,姓名,年齡\n");
     
     // 寫入數據行
     fprintf(file, "1,張三,25\n");
     fprintf(file, "2,李四,30\n");
     fprintf(file, "3,王五,22\n");
     fprintf(file, "4,\"趙六,Junior\",28\n"); // 包含逗號的字段用引號括起來
     
     fclose(file);
     printf("成功寫入CSV檔案 %s\n", FILENAME_CSV);
 }
 
 // 讀取CSV檔案
 void readCSVFile() {
     FILE *file = fopen(FILENAME_CSV, "r");
     
     if (file == NULL) {
         printf("無法開啟檔案 %s\n", FILENAME_CSV);
         return;
     }
     
     char line[MAX_LINE];
     printf("\n檔案 %s 的內容：\n", FILENAME_CSV);
     printf("------------------\n");
     
     // 讀取並顯示標題行
     if (fgets(line, MAX_LINE, file) != NULL) {
         printf("%s", line);
     }
     
     // 讀取並解析數據行
     while (fgets(line, MAX_LINE, file) != NULL) {
         printf("%s", line);
         
         // 手動解析CSV（簡化版，不處理引號中的逗號）
         char *token = strtok(line, ",");
         int id = atoi(token);
         
         token = strtok(NULL, ",");
         char name[50];
         strncpy(name, token, sizeof(name) - 1);
         name[sizeof(name) - 1] = '\0';
         
         token = strtok(NULL, ",");
         int age = atoi(token);
         
         // 這裡可以使用解析出的字段進行其他操作
     }
     
     printf("------------------\n");
     fclose(file);
 }
 
 // 檢查檔案是否存在
 void fileExists(const char *filename) {
     FILE *file = fopen(filename, "r");
     
     if (file != NULL) {
         printf("檔案 %s 存在\n", filename);
         fclose(file);
     } else {
         printf("檔案 %s 不存在\n", filename);
     }
 }
 
 // 複製檔案
 void copyFile(const char *source, const char *destination) {
     FILE *sourceFile = fopen(source, "rb");
     
     if (sourceFile == NULL) {
         printf("無法開啟來源檔案 %s\n", source);
         return;
     }
     
     FILE *destFile = fopen(destination, "wb");
     
     if (destFile == NULL) {
         printf("無法創建目標檔案 %s\n", destination);
         fclose(sourceFile);
         return;
     }
     
     char buffer[1024];
     size_t bytesRead;
     
     while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
         fwrite(buffer, 1, bytesRead, destFile);
     }
     
     fclose(sourceFile);
     fclose(destFile);
     
     printf("成功將 %s 複製到 %s\n", source, destination);
 }