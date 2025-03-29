/**
 * 檔案名稱: conditions.c
 * 描述: 演示C語言中的條件語句，包括if-else、switch和三元運算符
 * 
 * 編譯指令: gcc -o conditions conditions.c
 * 執行指令: ./conditions
 */

 #include <stdio.h>

 int main() {
     int age;
     
     printf("請輸入您的年齡: ");
     scanf("%d", &age);
     
     // if-else語句
     printf("\n--- 使用if-else語句判斷 ---\n");
     if (age < 0) {
         printf("錯誤：年齡不能為負數！\n");
     } else if (age < 18) {
         printf("您是未成年人。\n");
     } else if (age < 65) {
         printf("您是成年人。\n");
     } else {
         printf("您是老年人。\n");
     }
     
     // 巢狀if語句示例
     printf("\n--- 使用巢狀if語句判斷 ---\n");
     if (age >= 0) {
         if (age <= 12) {
             printf("您是兒童。\n");
         } else if (age <= 19) {
             printf("您是青少年。\n");
         } else if (age <= 59) {
             printf("您是成年人。\n");
         } else {
             printf("您是老年人。\n");
         }
     } else {
         printf("年齡輸入有誤！\n");
     }
     
     // switch語句示例
     printf("\n--- 使用switch語句判斷年齡段 ---\n");
     switch (age / 10) {
         case 0:
             printf("您還是個孩子。\n");
             break;
         case 1:
             printf("您是青少年。\n");
             break;
         case 2:
         case 3:
             printf("您正值青壯年。\n");
             break;
         case 4:
         case 5:
             printf("您正值壯年。\n");
             break;
         default:
             if (age < 0) {
                 printf("年齡輸入有誤！\n");
             } else {
                 printf("您已步入晚年。\n");
             }
             break;
     }
     
     // 邏輯運算符示例
     printf("\n--- 使用邏輯運算符 ---\n");
     if (age >= 18 && age <= 60) {
         printf("您處於工作年齡段。\n");
     }
     
     if (age < 13 || age > 65) {
         printf("您可能需要特別關注。\n");
     }
     
     if (!(age >= 18)) {
         printf("您不是成年人。\n");
     }
     
     // 三元運算符
     printf("\n--- 使用三元運算符 ---\n");
     printf("您%s投票權。\n", (age >= 20) ? "有" : "沒有");
     
     return 0;
 }