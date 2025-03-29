/**
 * 檔案名稱: basic_functions.c
 * 描述: 演示C語言中函數的基本用法，包括函數聲明、定義和調用
 * 
 * 編譯指令: gcc -o basic_functions basic_functions.c
 * 執行指令: ./basic_functions
 */

 #include <stdio.h>

 // 函數聲明（原型）
 int add(int a, int b);
 int subtract(int a, int b);
 int multiply(int a, int b);
 float divide(int a, int b);
 void printLine(char c, int length);
 void printInfo(char *message);
 int power(int base, int exponent);
 int max(int a, int b);
 int min(int a, int b);
 
 int main() {
     int num1, num2;
     
     // 列印分隔線
     printLine('=', 50);
     printInfo("歡迎使用函數示例程式");
     printLine('=', 50);
     
     // 從用戶獲取輸入
     printf("請輸入第一個整數: ");
     scanf("%d", &num1);
     
     printf("請輸入第二個整數: ");
     scanf("%d", &num2);
     
     // 使用函數並列印結果
     printLine('-', 50);
     printf("計算結果:\n");
     printf("%d + %d = %d\n", num1, num2, add(num1, num2));
     printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
     printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
     
     // 除法需要特殊處理防止除以零
     if (num2 != 0) {
         printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
     } else {
         printf("%d / %d = 錯誤：除數不能為零\n", num1, num2);
     }
     
     printf("%d 的 %d 次方 = %d\n", num1, num2, power(num1, num2));
     printf("%d 和 %d 中的最大值是 %d\n", num1, num2, max(num1, num2));
     printf("%d 和 %d 中的最小值是 %d\n", num1, num2, min(num1, num2));
     
     printLine('=', 50);
     printInfo("程式執行完畢，感謝使用！");
     
     return 0;
 }
 
 // 函數定義
 
 // 加法函數
 int add(int a, int b) {
     return a + b;
 }
 
 // 減法函數
 int subtract(int a, int b) {
     return a - b;
 }
 
 // 乘法函數
 int multiply(int a, int b) {
     return a * b;
 }
 
 // 除法函數
 float divide(int a, int b) {
     // 函數內部也應該檢查除數是否為零
     if (b == 0) {
         printf("錯誤：除數不能為零\n");
         return 0;
     }
     return (float)a / b;
 }
 
 // 列印分隔線函數
 void printLine(char c, int length) {
     for (int i = 0; i < length; i++) {
         printf("%c", c);
     }
     printf("\n");
 }
 
 // 列印信息函數
 void printInfo(char *message) {
     printf("%s\n", message);
 }
 
 // 計算冪次函數
 int power(int base, int exponent) {
     int result = 1;
     for (int i = 0; i < exponent; i++) {
         result *= base;
     }
     return result;
 }
 
 // 求最大值函數
 int max(int a, int b) {
     return (a > b) ? a : b;
 }
 
 // 求最小值函數
 int min(int a, int b) {
     return (a < b) ? a : b;
 }