/**
 * 檔案名稱: arrays.c
 * 描述: 展示C語言中陣列的基本操作，包括一維和二維陣列的使用
 * 
 * 編譯指令: gcc -o arrays arrays.c
 * 執行指令: ./arrays
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 #define SIZE 10
 
 // 函數聲明
 void printArray(int arr[], int size);
 void reverseArray(int arr[], int size);
 int findMax(int arr[], int size);
 int findMin(int arr[], int size);
 float calculateAverage(int arr[], int size);
 void bubbleSort(int arr[], int size);
 void generateRandomArray(int arr[], int size, int min, int max);
 
 int main() {
     int numbers[SIZE];
     int i, j;
     
     // 初始化隨機數生成器
     srand(time(NULL));
     
     // 生成隨機數填充陣列
     printf("===== 隨機生成的數組 =====\n");
     generateRandomArray(numbers, SIZE, 1, 100);
     printArray(numbers, SIZE);
     
     // 陣列統計信息
     printf("\n===== 數組統計信息 =====\n");
     printf("最大值：%d\n", findMax(numbers, SIZE));
     printf("最小值：%d\n", findMin(numbers, SIZE));
     printf("平均值：%.2f\n", calculateAverage(numbers, SIZE));
     
     // 陣列排序
     printf("\n===== 排序後的數組 =====\n");
     bubbleSort(numbers, SIZE);
     printArray(numbers, SIZE);
     
     // 陣列反轉
     printf("\n===== 反轉後的數組 =====\n");
     reverseArray(numbers, SIZE);
     printArray(numbers, SIZE);
     
     // 手動初始化陣列
     printf("\n===== 手動初始化的數組 =====\n");
     int manualArray[5] = {10, 20, 30, 40, 50};
     printArray(manualArray, 5);
     
     // 二維陣列示例
     printf("\n===== 二維數組示例 =====\n");
     int matrix[3][4] = {
         {1, 2, 3, 4},
         {5, 6, 7, 8},
         {9, 10, 11, 12}
     };
     
     printf("3x4矩陣：\n");
     for (i = 0; i < 3; i++) {
         for (j = 0; j < 4; j++) {
             printf("%3d ", matrix[i][j]);
         }
         printf("\n");
     }
     
     // 陣列的部分初始化
     printf("\n===== 部分初始化的數組 =====\n");
     int partialArray[10] = {1, 2, 3};  // 只初始化前三個元素，其餘為0
     printArray(partialArray, 10);
     
     // 使用陣列作為計數器
     printf("\n===== 使用數組作為計數器 =====\n");
     int dice[6] = {0};  // 初始化為全0
     
     // 模擬擲骰子100次
     for (i = 0; i < 100; i++) {
         int roll = rand() % 6;  // 0-5的隨機數
         dice[roll]++;
     }
     
     printf("擲骰子100次的結果：\n");
     for (i = 0; i < 6; i++) {
         printf("數字%d出現了%d次\n", i + 1, dice[i]);
     }
     
     return 0;
 }
 
 // 生成指定範圍內的隨機數陣列
 void generateRandomArray(int arr[], int size, int min, int max) {
     for (int i = 0; i < size; i++) {
         arr[i] = min + rand() % (max - min + 1);
     }
 }
 
 // 打印陣列
 void printArray(int arr[], int size) {
     for (int i = 0; i < size; i++) {
         printf("%d ", arr[i]);
     }
     printf("\n");
 }
 
 // 反轉陣列
 void reverseArray(int arr[], int size) {
     int temp;
     for (int i = 0; i < size / 2; i++) {
         temp = arr[i];
         arr[i] = arr[size - 1 - i];
         arr[size - 1 - i] = temp;
     }
 }
 
 // 查找最大值
 int findMax(int arr[], int size) {
     int max = arr[0];
     for (int i = 1; i < size; i++) {
         if (arr[i] > max) {
             max = arr[i];
         }
     }
     return max;
 }
 
 // 查找最小值
 int findMin(int arr[], int size) {
     int min = arr[0];
     for (int i = 1; i < size; i++) {
         if (arr[i] < min) {
             min = arr[i];
         }
     }
     return min;
 }
 
 // 計算平均值
 float calculateAverage(int arr[], int size) {
     int sum = 0;
     for (int i = 0; i < size; i++) {
         sum += arr[i];
     }
     return (float)sum / size;
 }
 
 // 冒泡排序
 void bubbleSort(int arr[], int size) {
     int temp;
     for (int i = 0; i < size - 1; i++) {
         for (int j = 0; j < size - i - 1; j++) {
             if (arr[j] > arr[j + 1]) {
                 temp = arr[j];
                 arr[j] = arr[j + 1];
                 arr[j + 1] = temp;
             }
         }
     }
 }