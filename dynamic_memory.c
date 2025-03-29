/**
 * 檔案名稱: dynamic_memory.c
 * 描述: 演示C語言中動態記憶體分配和管理
 * 
 * 編譯指令: gcc -o dynamic_memory dynamic_memory.c
 * 執行指令: ./dynamic_memory
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 // 學生結構體
 typedef struct {
     int id;
     char *name;
     float *scores;
     int numScores;
 } Student;
 
 // 函數宣告
 void basicMemoryAllocation();
 void arrayMemoryAllocation();
 void reallocExample();
 void structMemoryAllocation();
 Student *createStudent(int id, const char *name, float *scores, int numScores);
 void printStudent(Student *student);
 void freeStudent(Student *student);
 void dynamicMatrix();
 void memoryLeakExample();
 void memoryAccessError();
 
 int main() {
     int choice;
     
     printf("===== 動態記憶體分配示例 =====\n\n");
     printf("1. 基本記憶體分配 (malloc, free)\n");
     printf("2. 數組記憶體分配\n");
     printf("3. 記憶體重新分配 (realloc)\n");
     printf("4. 結構體記憶體分配\n");
     printf("5. 動態矩陣分配\n");
     printf("6. 記憶體洩漏示例 (不推薦)\n");
     printf("7. 記憶體訪問錯誤示例 (可能導致崩潰)\n");
     printf("0. 退出\n\n");
     
     printf("請選擇操作 (0-7): ");
     scanf("%d", &choice);
     
     switch (choice) {
         case 1:
             basicMemoryAllocation();
             break;
         case 2:
             arrayMemoryAllocation();
             break;
         case 3:
             reallocExample();
             break;
         case 4:
             structMemoryAllocation();
             break;
         case 5:
             dynamicMatrix();
             break;
         case 6:
             memoryLeakExample();
             break;
         case 7:
             memoryAccessError();
             break;
         case 0:
             printf("程式結束。\n");
             break;
         default:
             printf("無效的選擇！\n");
     }
     
     return 0;
 }
 
 // 基本記憶體分配
 void basicMemoryAllocation() {
     printf("\n===== 基本記憶體分配 =====\n");
     
     // 分配一個整數的記憶體
     int *ptr = (int *)malloc(sizeof(int));
     
     if (ptr == NULL) {
         printf("記憶體分配失敗\n");
         return;
     }
     
     // 使用分配的記憶體
     *ptr = 42;
     printf("分配的記憶體值: %d\n", *ptr);
     
     // 釋放記憶體
     free(ptr);
     printf("記憶體已釋放\n");
     
     // 防止懸垂指針 (dangling pointer)
     ptr = NULL;
     
     // 使用calloc分配並初始化為0
     int *ptr2 = (int *)calloc(1, sizeof(int));
     
     if (ptr2 == NULL) {
         printf("記憶體分配失敗\n");
         return;
     }
     
     printf("calloc分配的記憶體初始值: %d\n", *ptr2);
     
     // 釋放記憶體
     free(ptr2);
 }
 
 // 數組記憶體分配
 void arrayMemoryAllocation() {
     printf("\n===== 數組記憶體分配 =====\n");
     
     int size;
     printf("請輸入數組大小: ");
     scanf("%d", &size);
     
     // 分配數組記憶體
     int *array = (int *)malloc(size * sizeof(int));
     
     if (array == NULL) {
         printf("記憶體分配失敗\n");
         return;
     }
     
     // 初始化數組
     for (int i = 0; i < size; i++) {
         array[i] = i * 10;
     }
     
     // 顯示數組內容
     printf("數組內容:\n");
     for (int i = 0; i < size; i++) {
         printf("array[%d] = %d\n", i, array[i]);
     }
     
     // 釋放記憶體
     free(array);
     printf("記憶體已釋放\n");
 }
 
 // 記憶體重新分配
 void reallocExample() {
     printf("\n===== 記憶體重新分配 =====\n");
     
     // 初始分配5個整數的空間
     int *numbers = (int *)malloc(5 * sizeof(int));
     
     if (numbers == NULL) {
         printf("記憶體分配失敗\n");
         return;
     }
     
     // 初始化前5個元素
     for (int i = 0; i < 5; i++) {
         numbers[i] = i + 1;
     }
     
     printf("初始數組 (大小 5):\n");
     for (int i = 0; i < 5; i++) {
         printf("%d ", numbers[i]);
     }
     printf("\n");
     
     // 擴展數組到10個元素
     int *new_numbers = (int *)realloc(numbers, 10 * sizeof(int));
     
     if (new_numbers == NULL) {
         printf("記憶體重新分配失敗\n");
         free(numbers);  // 釋放原來的記憶體
         return;
     }
     
     numbers = new_numbers;  // 更新指針
     
     // 初始化新增的5個元素
     for (int i = 5; i < 10; i++) {
         numbers[i] = i + 1;
     }
     
     printf("擴展後的數組 (大小 10):\n");
     for (int i = 0; i < 10; i++) {
         printf("%d ", numbers[i]);
     }
     printf("\n");
     
     // 縮減數組到3個元素
     new_numbers = (int *)realloc(numbers, 3 * sizeof(int));
     
     if (new_numbers == NULL) {
         printf("記憶體重新分配失敗\n");
         free(numbers);
         return;
     }
     
     numbers = new_numbers;
     
     printf("縮減後的數組 (大小 3):\n");
     for (int i = 0; i < 3; i++) {
         printf("%d ", numbers[i]);
     }
     printf("\n");
     
     // 釋放記憶體
     free(numbers);
     printf("記憶體已釋放\n");
 }
 
 // 結構體記憶體分配
 void structMemoryAllocation() {
     printf("\n===== 結構體記憶體分配 =====\n");
     
     // 準備學生資料
     float scores[] = {92.5, 88.0, 95.5};
     
     // 創建學生
     Student *student = createStudent(1001, "張小明", scores, 3);
     
     // 顯示學生資訊
     if (student != NULL) {
         printStudent(student);
         
         // 釋放學生所佔用的記憶體
         freeStudent(student);
         printf("學生記憶體已釋放\n");
     }
 }
 
 // 創建學生
 Student *createStudent(int id, const char *name, float *scores, int numScores) {
     // 分配學生結構體記憶體
     Student *student = (Student *)malloc(sizeof(Student));
     
     if (student == NULL) {
         printf("無法分配學生結構體記憶體\n");
         return NULL;
     }
     
     // 設置學生ID
     student->id = id;
     
     // 分配並複製學生姓名
     student->name = (char *)malloc(strlen(name) + 1);
     
     if (student->name == NULL) {
         printf("無法分配學生姓名記憶體\n");
         free(student);
         return NULL;
     }
     
     strcpy(student->name, name);
     
     // 分配並複製學生成績
     student->numScores = numScores;
     student->scores = (float *)malloc(numScores * sizeof(float));
     
     if (student->scores == NULL) {
         printf("無法分配學生成績記憶體\n");
         free(student->name);
         free(student);
         return NULL;
     }
     
     for (int i = 0; i < numScores; i++) {
         student->scores[i] = scores[i];
     }
     
     return student;
 }
 
 // 列印學生資訊
 void printStudent(Student *student) {
     printf("學生ID: %d\n", student->id);
     printf("學生姓名: %s\n", student->name);
     
     printf("學生成績: ");
     for (int i = 0; i < student->numScores; i++) {
         printf("%.1f ", student->scores[i]);
     }
     printf("\n");
     
     // 計算平均成績
     float sum = 0;
     for (int i = 0; i < student->numScores; i++) {
         sum += student->scores[i];
     }
     
     float average = sum / student->numScores;
     printf("平均成績: %.2f\n", average);
 }
 
 // 釋放學生所佔用的記憶體
 void freeStudent(Student *student) {
     if (student == NULL) {
         return;
     }
     
     // 釋放姓名記憶體
     if (student->name != NULL) {
         free(student->name);
     }
     
     // 釋放成績記憶體
     if (student->scores != NULL) {
         free(student->scores);
     }
     
     // 釋放結構體記憶體
     free(student);
 }
 
 // 動態矩陣分配
 void dynamicMatrix() {
     printf("\n===== 動態矩陣分配 =====\n");
     
     int rows, cols;
     printf("請輸入矩陣的行數: ");
     scanf("%d", &rows);
     printf("請輸入矩陣的列數: ");
     scanf("%d", &cols);
     
     // 分配矩陣記憶體 (二維數組)
     int **matrix = (int **)malloc(rows * sizeof(int *));
     
     if (matrix == NULL) {
         printf("記憶體分配失敗\n");
         return;
     }
     
     for (int i = 0; i < rows; i++) {
         matrix[i] = (int *)malloc(cols * sizeof(int));
         
         if (matrix[i] == NULL) {
             printf("行 %d 記憶體分配失敗\n", i);
             
             // 釋放之前分配的記憶體
             for (int j = 0; j < i; j++) {
                 free(matrix[j]);
             }
             free(matrix);
             
             return;
         }
     }
     
     // 初始化矩陣
     for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
             matrix[i][j] = i * cols + j + 1;
         }
     }
     
     // 顯示矩陣內容
     printf("矩陣內容:\n");
     for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++) {
             printf("%3d ", matrix[i][j]);
         }
         printf("\n");
     }
     
     // 釋放矩陣記憶體
     for (int i = 0; i < rows; i++) {
         free(matrix[i]);
     }
     free(matrix);
     
     printf("矩陣記憶體已釋放\n");
 }
 
 // 記憶體洩漏示例 (不推薦)
 void memoryLeakExample() {
     printf("\n===== 記憶體洩漏示例 (示範不良習慣) =====\n");
     printf("注意: 這個函數故意不釋放分配的記憶體，僅用於示範!\n");
     
     // 分配記憶體但不釋放
     int *ptr = (int *)malloc(1000 * sizeof(int));
     
     if (ptr == NULL) {
         printf("記憶體分配失敗\n");
         return;
     }
     
     printf("已分配 %ld 位元組的記憶體，但故意不釋放它\n", 1000 * sizeof(int));
     printf("這會導致記憶體洩漏，在實際程式中應避免這種情況!\n");
     
     // 正確的做法是: free(ptr);
 }
 
 // 記憶體訪問錯誤示例 (可能導致崩潰)
 void memoryAccessError() {
     printf("\n===== 記憶體訪問錯誤示例 (示範不良習慣) =====\n");
     printf("注意: 這個函數故意製造記憶體錯誤，僅用於示範!\n");
     
     // 分配一個10個整數的數組
     int *arr = (int *)malloc(10 * sizeof(int));
     
     if (arr == NULL) {
         printf("記憶體分配失敗\n");
         return;
     }
     
     printf("已分配大小為10的整數數組\n");
     
     // 初始化數組
     for (int i = 0; i < 10; i++) {
         arr[i] = i;
     }
     
     // 1. 使用已釋放的記憶體 (use after free)
     printf("\n1. 使用已釋放的記憶體 (use after free):\n");
     free(arr);
     printf("記憶體已釋放，但仍嘗試訪問第一個元素: ");
     // 這是不正確的，可能導致未定義行為
     // printf("arr[0] = %d\n", arr[0]);  // 注釋掉以避免程式崩潰
     printf("(已注釋掉危險操作，實際程式會導致未定義行為)\n");
     
     // 2. 訪問超出邊界的記憶體
     printf("\n2. 訪問超出邊界的記憶體:\n");
     arr = (int *)malloc(10 * sizeof(int));
     if (arr != NULL) {
         printf("嘗試訪問超出數組範圍的元素: ");
         // 這是不正確的，可能導致未定義行為
         // printf("arr[15] = %d\n", arr[15]);  // 注釋掉以避免程式崩潰
         printf("(已注釋掉危險操作，實際程式會導致未定義行為)\n");
         free(arr);
     }
     
     // 3. 重複釋放記憶體
     printf("\n3. 重複釋放記憶體:\n");
     arr = (int *)malloc(10 * sizeof(int));
     if (arr != NULL) {
         printf("第一次釋放記憶體\n");
         free(arr);
         printf("嘗試第二次釋放同一塊記憶體: ");
         // 這是不正確的，會導致雙重釋放錯誤
         // free(arr);  // 注釋掉以避免程式崩潰
         printf("(已注釋掉危險操作，實際程式會導致雙重釋放錯誤)\n");
     }
     
     printf("\n記住：良好的記憶體管理實踐包括：\n");
     printf("1. 每次使用malloc/calloc分配的記憶體最終都要使用free釋放\n");
     printf("2. 不要訪問已釋放的記憶體\n");
     printf("3. 不要訪問超出分配範圍的記憶體\n");
     printf("4. 不要重複釋放同一塊記憶體\n");
     printf("5. 釋放記憶體後將指針設為NULL\n");
 }