/**
 * 檔案名稱: multi_file_main.c
 * 描述: 多文件程式設計示例 - 主程式
 * 
 * 編譯指令: gcc -o multi_file_program multi_file_main.c calculator.c utils.c
 * 執行指令: ./multi_file_program
 */

 #include <stdio.h>
 #include "calculator.h"  // 包含計算器函數聲明
 #include "utils.h"       // 包含工具函數聲明
 
 // 主程式
 int main() {
     printf("===== 多文件程式設計示例 =====\n\n");
     
     // 顯示程式資訊
     printProgramInfo();
     
     // 計算器變數
     int a, b;
     char op;
     
     // 獲取用戶輸入
     printf("請輸入一個簡單的算式（例如：5 + 3）: ");
     scanf("%d %c %d", &a, &op, &b);
     
     // 執行計算
     int result = 0;
     float div_result = 0.0f;
     bool success = true;
     
     switch (op) {
         case '+':
             result = add(a, b);
             printf("%d %c %d = %d\n", a, op, b, result);
             break;
         case '-':
             result = subtract(a, b);
             printf("%d %c %d = %d\n", a, op, b, result);
             break;
         case '*':
             result = multiply(a, b);
             printf("%d %c %d = %d\n", a, op, b, result);
             break;
         case '/':
             if (b != 0) {
                 div_result = divide(a, b);
                 printf("%d %c %d = %.2f\n", a, op, b, div_result);
             } else {
                 printf("錯誤：除數不能為零！\n");
                 success = false;
             }
             break;
         default:
             printf("不支持的運算符: %c\n", op);
             success = false;
     }
     
     // 記錄計算歷史
     if (success) {
         char history[100];
         sprintf(history, "%d %c %d", a, op, b);
         logCalculation(history);
     }
     
     // 顯示程式執行統計
     printStats();
     
     return 0;
 }