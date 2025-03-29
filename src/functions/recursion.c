/**
 * 檔案名稱: recursion.c
 * 描述: 演示C語言中遞迴函數的使用，包括階乘、斐波那契數列、最大公約數等
 * 
 * 編譯指令: gcc -o recursion recursion.c
 * 執行指令: ./recursion
 */

 #include <stdio.h>

 // 函數聲明
 unsigned long factorial(int n);
 unsigned long fibonacci(int n);
 int gcd(int a, int b);
 void hanoiTower(int n, char from, char to, char aux);
 int sum(int n);
 int power(int base, int exponent);
 
 int main() {
     int choice, n, a, b;
     
     printf("===== 遞迴函數示例 =====\n\n");
     printf("1. 計算階乘 (n!)\n");
     printf("2. 計算斐波那契數列的第n項\n");
     printf("3. 計算最大公約數\n");
     printf("4. 解決漢諾塔問題\n");
     printf("5. 計算從1到n的和\n");
     printf("6. 計算冪次\n");
     printf("請選擇功能 (1-6): ");
     scanf("%d", &choice);
     
     switch (choice) {
         case 1:
             printf("\n===== 計算階乘 =====\n");
             printf("請輸入一個非負整數: ");
             scanf("%d", &n);
             
             if (n < 0) {
                 printf("錯誤：階乘不能用於負數！\n");
             } else {
                 printf("%d! = %lu\n", n, factorial(n));
             }
             break;
             
         case 2:
             printf("\n===== 計算斐波那契數列 =====\n");
             printf("請輸入項數 (從0開始): ");
             scanf("%d", &n);
             
             if (n < 0) {
                 printf("錯誤：項數不能為負數！\n");
             } else {
                 printf("斐波那契數列的第%d項是: %lu\n", n, fibonacci(n));
                 
                 printf("前%d項斐波那契數列: ", n + 1);
                 for (int i = 0; i <= n; i++) {
                     printf("%lu ", fibonacci(i));
                 }
                 printf("\n");
             }
             break;
             
         case 3:
             printf("\n===== 計算最大公約數 =====\n");
             printf("請輸入第一個正整數: ");
             scanf("%d", &a);
             printf("請輸入第二個正整數: ");
             scanf("%d", &b);
             
             if (a <= 0 || b <= 0) {
                 printf("錯誤：請輸入正整數！\n");
             } else {
                 printf("%d和%d的最大公約數是: %d\n", a, b, gcd(a, b));
             }
             break;
             
         case 4:
             printf("\n===== 漢諾塔問題 =====\n");
             printf("請輸入盤子數量: ");
             scanf("%d", &n);
             
             if (n <= 0) {
                 printf("錯誤：盤子數量必須為正整數！\n");
             } else {
                 printf("解決%d個盤子的漢諾塔問題的步驟：\n", n);
                 hanoiTower(n, 'A', 'C', 'B');
                 printf("總共需要%d步\n", (1 << n) - 1); // 2^n - 1
             }
             break;
             
         case 5:
             printf("\n===== 計算從1到n的和 =====\n");
             printf("請輸入一個正整數n: ");
             scanf("%d", &n);
             
             if (n <= 0) {
                 printf("錯誤：請輸入正整數！\n");
             } else {
                 printf("從1到%d的和是: %d\n", n, sum(n));
             }
             break;
             
         case 6:
             printf("\n===== 計算冪次 =====\n");
             printf("請輸入底數: ");
             scanf("%d", &a);
             printf("請輸入指數（非負整數）: ");
             scanf("%d", &b);
             
             if (b < 0) {
                 printf("錯誤：指數不能為負數！\n");
             } else {
                 printf("%d的%d次方是: %d\n", a, b, power(a, b));
             }
             break;
             
         default:
             printf("無效的選擇！\n");
     }
     
     return 0;
 }
 
 // 計算階乘: n!
 unsigned long factorial(int n) {
     // 基本情況：0! = 1
     if (n <= 1) {
         return 1;
     }
     // 遞迴情況：n! = n * (n-1)!
     return n * factorial(n - 1);
 }
 
 // 計算斐波那契數列的第n項
 unsigned long fibonacci(int n) {
     // 基本情況：F(0) = 0, F(1) = 1
     if (n <= 0) {
         return 0;
     }
     if (n == 1) {
         return 1;
     }
     // 遞迴情況：F(n) = F(n-1) + F(n-2)
     return fibonacci(n - 1) + fibonacci(n - 2);
 }
 
 // 計算最大公約數（歐幾里得算法）
 int gcd(int a, int b) {
     // 基本情況：如果b為0，則a是最大公約數
     if (b == 0) {
         return a;
     }
     // 遞迴情況：gcd(a, b) = gcd(b, a % b)
     return gcd(b, a % b);
 }
 
 // 解決漢諾塔問題
 void hanoiTower(int n, char from, char to, char aux) {
     // 基本情況：只有一個盤子時，直接從起始柱移動到目標柱
     if (n == 1) {
         printf("移動盤子1從%c柱到%c柱\n", from, to);
         return;
     }
     
     // 遞迴情況：
     // 1. 將n-1個盤子從起始柱移動到輔助柱
     hanoiTower(n - 1, from, aux, to);
     
     // 2. 將第n個盤子從起始柱移動到目標柱
     printf("移動盤子%d從%c柱到%c柱\n", n, from, to);
     
     // 3. 將n-1個盤子從輔助柱移動到目標柱
     hanoiTower(n - 1, aux, to, from);
 }
 
 // 使用遞迴計算從1到n的和
 int sum(int n) {
     // 基本情況：sum(1) = 1
     if (n == 1) {
         return 1;
     }
     // 遞迴情況：sum(n) = n + sum(n-1)
     return n + sum(n - 1);
 }
 
 // 使用遞迴計算冪次
 int power(int base, int exponent) {
     // 基本情況：任何數的0次方都是1
     if (exponent == 0) {
         return 1;
     }
     // 遞迴情況：base^exp = base * base^(exp-1)
     return base * power(base, exponent - 1);
 }