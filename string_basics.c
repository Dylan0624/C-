/**
 * 檔案名稱: string_basics.c
 * 描述: 演示C語言中字串的基本操作，包括字串的宣告、操作與處理
 * 
 * 編譯指令: gcc -o string_basics string_basics.c
 * 執行指令: ./string_basics
 */

 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 
 #define MAX_LENGTH 100
 
 // 函數聲明
 int stringLength(const char *str);
 void reverseString(char *str);
 int countChar(const char *str, char c);
 void toUpperCase(char *str);
 void toLowerCase(char *str);
 int isPalindrome(const char *str);
 void removeSpaces(char *str);
 
 int main() {
     char str1[MAX_LENGTH];
     char str2[MAX_LENGTH];
     
     printf("===== 字串基本操作示例 =====\n\n");
     
     // 獲取用戶輸入
     printf("請輸入一個字串: ");
     fgets(str1, MAX_LENGTH, stdin);
     
     // 移除換行符
     if (str1[strlen(str1) - 1] == '\n') {
         str1[strlen(str1) - 1] = '\0';
     }
     
     // 字串長度
     printf("\n===== 字串長度 =====\n");
     printf("使用庫函數strlen(): %lu\n", strlen(str1));
     printf("使用自定義函數: %d\n", stringLength(str1));
     
     // 字串複製
     printf("\n===== 字串複製 =====\n");
     strcpy(str2, str1);
     printf("複製後的字串: %s\n", str2);
     
     // 字串連接
     printf("\n===== 字串連接 =====\n");
     char greeting[MAX_LENGTH] = "Hello, ";
     strncat(greeting, str1, MAX_LENGTH - strlen(greeting) - 1);
     printf("連接後的字串: %s\n", greeting);
     
     // 字串比較
     printf("\n===== 字串比較 =====\n");
     if (strcmp(str1, str2) == 0) {
         printf("str1和str2相同\n");
     } else {
         printf("str1和str2不同\n");
     }
     
     // 搜尋字符
     printf("\n===== 搜尋字符 =====\n");
     char searchChar;
     printf("請輸入要搜尋的字符: ");
     scanf(" %c", &searchChar);
     printf("字符'%c'在字串中出現了%d次\n", searchChar, countChar(str1, searchChar));
     
     // 字串搜尋
     printf("\n===== 字串搜尋 =====\n");
     char searchStr[MAX_LENGTH];
     printf("請輸入要搜尋的子字串: ");
     scanf("%s", searchStr);
     
     char *result = strstr(str1, searchStr);
     if (result != NULL) {
         printf("找到子字串'%s'，位置: %ld\n", searchStr, result - str1);
     } else {
         printf("未找到子字串'%s'\n", searchStr);
     }
     
     // 字串反轉
     printf("\n===== 字串反轉 =====\n");
     printf("原始字串: %s\n", str1);
     reverseString(str1);
     printf("反轉後的字串: %s\n", str1);
     reverseString(str1);  // 再次反轉回來
     
     // 大小寫轉換
     printf("\n===== 大小寫轉換 =====\n");
     printf("原始字串: %s\n", str1);
     toUpperCase(str1);
     printf("轉換為大寫: %s\n", str1);
     toLowerCase(str1);
     printf("轉換為小寫: %s\n", str1);
     
     // 檢查回文
     printf("\n===== 回文檢查 =====\n");
     if (isPalindrome(str1)) {
         printf("'%s'是回文\n", str1);
     } else {
         printf("'%s'不是回文\n", str1);
     }
     
     // 移除空格
     printf("\n===== 移除空格 =====\n");
     printf("原始字串: %s\n", str1);
     removeSpaces(str1);
     printf("移除空格後: %s\n", str1);
     
     // 字元處理函數示例
     printf("\n===== 字元處理函數示例 =====\n");
     char c;
     printf("請輸入一個字元: ");
     scanf(" %c", &c);
     
     printf("isalpha(%c): %d\n", c, isalpha(c));
     printf("isdigit(%c): %d\n", c, isdigit(c));
     printf("isalnum(%c): %d\n", c, isalnum(c));
     printf("islower(%c): %d\n", c, islower(c));
     printf("isupper(%c): %d\n", c, isupper(c));
     printf("tolower(%c): %c\n", c, tolower(c));
     printf("toupper(%c): %c\n", c, toupper(c));
     
     return 0;
 }
 
 // 自定義函數計算字串長度
 int stringLength(const char *str) {
     int length = 0;
     while (str[length] != '\0') {
         length++;
     }
     return length;
 }
 
 // 反轉字串
 void reverseString(char *str) {
     int length = strlen(str);
     int i, j;
     char temp;
     
     for (i = 0, j = length - 1; i < j; i++, j--) {
         temp = str[i];
         str[i] = str[j];
         str[j] = temp;
     }
 }
 
 // 統計字符出現次數
 int countChar(const char *str, char c) {
     int count = 0;
     for (int i = 0; str[i] != '\0'; i++) {
         if (str[i] == c) {
             count++;
         }
     }
     return count;
 }
 
 // 轉換為大寫
 void toUpperCase(char *str) {
     for (int i = 0; str[i] != '\0'; i++) {
         str[i] = toupper(str[i]);
     }
 }
 
 // 轉換為小寫
 void toLowerCase(char *str) {
     for (int i = 0; str[i] != '\0'; i++) {
         str[i] = tolower(str[i]);
     }
 }
 
 // 檢查是否是回文
 int isPalindrome(const char *str) {
     int length = strlen(str);
     int i, j;
     
     for (i = 0, j = length - 1; i < j; i++, j--) {
         // 忽略大小寫
         if (tolower(str[i]) != tolower(str[j])) {
             return 0;  // 不是回文
         }
     }
     return 1;  // 是回文
 }
 
 // 移除字串中的所有空格
 void removeSpaces(char *str) {
     int i, j;
     for (i = 0, j = 0; str[i] != '\0'; i++) {
         if (str[i] != ' ') {
             str[j++] = str[i];
         }
     }
     str[j] = '\0';
 }