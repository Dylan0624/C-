/**
 * 檔案名稱: pointers.c
 * 描述: 演示C語言中指標的基本概念和操作
 * 
 * 編譯指令: gcc -o pointers pointers.c
 * 執行指令: ./pointers
 */

 #include <stdio.h>
 #include <stdlib.h>
 
 // 函數聲明
 void swap(int *a, int *b);
 void modifyValue(int *value);
 void printArray(int *arr, int size);
 int *findMiddle(int *arr, int size);
 void incrementAll(int *arr, int size);
 
 int main() {
     // 基本指標操作
     int number = 42;
     int *ptr = &number;  // 指標初始化
     
     printf("===== 基本指標操作 =====\n");
     printf("變數 number 的值: %d\n", number);
     printf("變數 number 的記憶體位址: %p\n", &number);
     printf("指標 ptr 的值 (即number的位址): %p\n", ptr);
     printf("指標 ptr 所指向的值: %d\n", *ptr);
     
     // 通過指標修改值
     *ptr = 100;
     printf("\n透過指標修改後，number的值: %d\n", number);
     
     // 指標算術運算
     int arr[5] = {10, 20, 30, 40, 50};
     int *arrPtr = arr;  // 陣列名是指向其第一個元素的指標
     
     printf("\n===== 指標和陣列 =====\n");
     printf("使用陣列名訪問: ");
     for (int i = 0; i < 5; i++) {
         printf("%d ", arr[i]);
     }
     
     printf("\n使用指標訪問: ");
     for (int i = 0; i < 5; i++) {
         printf("%d ", *(arrPtr + i));  // 指標算術
     }
     
     printf("\n使用指標算術和解引用: ");
     for (int i = 0; i < 5; i++) {
         printf("%d ", *arrPtr);
         arrPtr++;  // 移動指標
     }
     printf("\n");
     
     // 重置arrPtr
     arrPtr = arr;
     
     // 指標作為函數參數 - 交換兩個值
     int a = 5, b = 10;
     printf("\n===== 使用指標交換值 =====\n");
     printf("交換前: a = %d, b = %d\n", a, b);
     swap(&a, &b);
     printf("交換後: a = %d, b = %d\n", a, b);
     
     // 通過指標修改值
     int value = 20;
     printf("\n===== 通過函數修改值 =====\n");
     printf("修改前: value = %d\n", value);
     modifyValue(&value);
     printf("修改後: value = %d\n", value);
     
     // 尋找陣列中間元素
     printf("\n===== 尋找陣列中間元素 =====\n");
     int *middle = findMiddle(arr, 5);
     printf("陣列中間元素: %d\n", *middle);
     
     // 使用指標增加陣列中的所有元素
     printf("\n===== 增加陣列中的所有元素 =====\n");
     printf("修改前的陣列: ");
     printArray(arr, 5);
     
     incrementAll(arr, 5);
     
     printf("修改後的陣列: ");
     printArray(arr, 5);
     
     // 指標與動態記憶體分配
     printf("\n===== 動態記憶體分配 =====\n");
     int size;
     printf("請輸入要動態分配的陣列大小: ");
     scanf("%d", &size);
     
     // 使用malloc分配記憶體
     int *dynamicArray = (int *)malloc(size * sizeof(int));
     
     // 檢查是否分配成功
     if (dynamicArray == NULL) {
         printf("記憶體分配失敗!\n");
         return 1;
     }
     
     // 初始化動態陣列
     for (int i = 0; i < size; i++) {
         dynamicArray[i] = i * 10;
     }
     
     // 顯示動態陣列內容
     printf("動態分配的陣列內容: ");
     printArray(dynamicArray, size);
     
     // 釋放動態分配的記憶體
     free(dynamicArray);
     printf("已釋放動態分配的記憶體\n");
     
     // 指標與多級間接引用
     printf("\n===== 多級間接引用 =====\n");
     int x = 42;
     int *p1 = &x;     // 一級指標
     int **p2 = &p1;   // 二級指標
     int ***p3 = &p2;  // 三級指標
     
     printf("x = %d\n", x);
     printf("*p1 = %d\n", *p1);
     printf("**p2 = %d\n", **p2);
     printf("***p3 = %d\n", ***p3);
     
     ***p3 = 100;  // 通過三級指標修改x的值
     printf("修改後的x = %d\n", x);
     
     return 0;
 }
 
 // 交換兩個整數的值
 void swap(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
 }
 
 // 修改指標指向的值
 void modifyValue(int *value) {
     *value = *value * 2;  // 將值翻倍
 }
 
 // 列印陣列
 void printArray(int *arr, int size) {
     for (int i = 0; i < size; i++) {
         printf("%d ", arr[i]);
     }
     printf("\n");
 }
 
 // 返回陣列中間元素的指標
 int *findMiddle(int *arr, int size) {
     return arr + size / 2;
 }
 
 // 增加陣列中的所有元素
 void incrementAll(int *arr, int size) {
     for (int i = 0; i < size; i++) {
         arr[i]++;  // 或者 (*(arr + i))++;
     }
 }