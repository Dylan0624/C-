/**
 * 檔案名稱: data_types.c
 * 描述: 展示C語言中的基本數據類型、變數和運算
 * 
 * 編譯指令: gcc -o data_types data_types.c
 * 執行指令: ./data_types
 */

 #include <stdio.h>
 #include <limits.h>
 #include <float.h>
 
 int main() {
     // 整數類型
     int integer = 42;
     short shortInteger = 3265;
     long longInteger = 2147483647L;
     unsigned int unsignedInt = 4294967295U;
     
     // 浮點類型
     float floatNumber = 3.14159f;
     double doubleNumber = 2.71828182845;
     
     // 字符類型
     char character = 'A';
     
     // 布林類型 (C99標準)
     _Bool booleanTrue = 1;
     _Bool booleanFalse = 0;
     
     // 打印各種類型的值和大小
     printf("===== 整數類型 =====\n");
     printf("int: %d (大小: %lu 位元組, 範圍: %d 到 %d)\n", 
            integer, sizeof(integer), INT_MIN, INT_MAX);
     printf("short: %hd (大小: %lu 位元組, 範圍: %d 到 %d)\n", 
            shortInteger, sizeof(shortInteger), SHRT_MIN, SHRT_MAX);
     printf("long: %ld (大小: %lu 位元組, 範圍: %ld 到 %ld)\n", 
            longInteger, sizeof(longInteger), LONG_MIN, LONG_MAX);
     printf("unsigned int: %u (大小: %lu 位元組, 範圍: 0 到 %u)\n", 
            unsignedInt, sizeof(unsignedInt), UINT_MAX);
     
     printf("\n===== 浮點類型 =====\n");
     printf("float: %f (大小: %lu 位元組, 精度: 約6位數字)\n", 
            floatNumber, sizeof(floatNumber));
     printf("double: %.10f (大小: %lu 位元組, 精度: 約15位數字)\n", 
            doubleNumber, sizeof(doubleNumber));
     
     printf("\n===== 字符類型 =====\n");
     printf("char: '%c' (ASCII: %d, 大小: %lu 位元組)\n", 
            character, character, sizeof(character));
     
     printf("\n===== 布林類型 =====\n");
     printf("_Bool (真): %d (大小: %lu 位元組)\n", 
            booleanTrue, sizeof(booleanTrue));
     printf("_Bool (假): %d (大小: %lu 位元組)\n", 
            booleanFalse, sizeof(booleanFalse));
     
     // 算數運算
     printf("\n===== 基本運算 =====\n");
     printf("加法: %d + %d = %d\n", 10, 5, 10 + 5);
     printf("減法: %d - %d = %d\n", 10, 5, 10 - 5);
     printf("乘法: %d * %d = %d\n", 10, 5, 10 * 5);
     printf("除法: %d / %d = %d\n", 10, 5, 10 / 5);
     printf("整數除法: %d / %d = %d (注意: 結果被截斷)\n", 10, 3, 10 / 3);
     printf("取餘數: %d %% %d = %d\n", 10, 3, 10 % 3);
     
     // 類型轉換
     printf("\n===== 類型轉換 =====\n");
     printf("浮點數到整數: (int)%.2f = %d (小數部分被截斷)\n", 
            9.99, (int)9.99);
     printf("整數到浮點數: (float)%d = %.1f\n", 
            9, (float)9);
     printf("字符到整數: (int)'%c' = %d\n", 
            'A', (int)'A');
     printf("整數到字符: (char)%d = '%c'\n", 
            65, (char)65);
     
     return 0;
 }