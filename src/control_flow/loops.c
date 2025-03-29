/**
 * 檔案名稱: loops.c
 * 描述: 演示C語言中的循環結構，包括for、while和do-while循環
 * 
 * 編譯指令: gcc -o loops loops.c
 * 執行指令: ./loops
 */

 #include <stdio.h>

 int main() {
     int i, j;
     
     // for循環
     printf("===== 使用for循環打印1到10 =====\n");
     for (i = 1; i <= 10; i++) {
         printf("%d ", i);
     }
     printf("\n\n");
     
     // while循環
     printf("===== 使用while循環計算5的階乘 =====\n");
     i = 1;
     int factorial = 1;
     while (i <= 5) {
         factorial *= i;
         printf("%d! = %d\n", i, factorial);
         i++;
     }
     printf("\n");
     
     // do-while循環
     printf("===== 使用do-while循環打印倒計時 =====\n");
     i = 5;
     do {
         printf("%d... ", i);
         i--;
     } while (i > 0);
     printf("發射！\n\n");
     
     // 嵌套循環：打印三角形
     printf("===== 使用嵌套循環打印三角形 =====\n");
     for (i = 1; i <= 5; i++) {
         // 打印空格
         for (j = 1; j <= 5 - i; j++) {
             printf(" ");
         }
         // 打印星號
         for (j = 1; j <= 2 * i - 1; j++) {
             printf("*");
         }
         printf("\n");
     }
     printf("\n");
     
     // 嵌套循環：打印乘法表
     printf("===== 使用嵌套循環打印9x9乘法表 =====\n");
     for (i = 1; i <= 9; i++) {
         for (j = 1; j <= i; j++) {
             printf("%d×%d=%-2d ", j, i, i * j);
         }
         printf("\n");
     }
     printf("\n");
     
     // break和continue示例
     printf("===== break示例：找到第一個能被123整除的數 =====\n");
     for (i = 100; i <= 1000; i++) {
         if (i % 123 == 0) {
             printf("找到了：%d\n", i);
             break;  // 找到後立即跳出循環
         }
     }
     printf("\n");
     
     printf("===== continue示例：打印1到10中除了3和7的所有數 =====\n");
     for (i = 1; i <= 10; i++) {
         if (i == 3 || i == 7) {
             continue;  // 跳過當前迭代
         }
         printf("%d ", i);
     }
     printf("\n\n");
     
     // 無限循環與條件退出
     printf("===== 使用break退出無限循環 =====\n");
     i = 1;
     while (1) {  // 無限循環
         printf("%d ", i);
         if (i >= 5) {
             break;  // 當i達到5時退出循環
         }
         i++;
     }
     printf("\n程式正常結束\n");
     
     return 0;
 }