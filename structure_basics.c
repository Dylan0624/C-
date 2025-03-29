/**
 * 檔案名稱: structure_basics.c
 * 描述: 演示C語言中結構體的基本使用
 * 
 * 編譯指令: gcc -o structure_basics structure_basics.c
 * 執行指令: ./structure_basics
 */

 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 
 // 定義學生結構體
 struct Student {
     int id;
     char name[50];
     float gpa;
 };
 
 // 定義點結構體
 struct Point {
     int x;
     int y;
 };
 
 // 定義日期結構體
 struct Date {
     int day;
     int month;
     int year;
 };
 
 // 定義包含結構體的結構體
 struct Person {
     char name[50];
     int age;
     struct Date birthdate;
 };
 
 // 定義用於聯合示例的結構體
 struct DataValue {
     char type;  // 'i' for int, 'f' for float, 'c' for char
     union {
         int i_val;
         float f_val;
         char c_val;
     } data;
 };
 
 // 函數聲明
 void printStudent(struct Student s);
 void modifyStudent(struct Student *s, int id, const char *name, float gpa);
 float calculateDistance(struct Point p1, struct Point p2);
 void printDate(struct Date date);
 int compareDate(struct Date d1, struct Date d2);
 void printPerson(struct Person p);
 void printDataValue(struct DataValue dv);
 
 int main() {
     // 基本結構體使用
     printf("===== 基本結構體使用 =====\n");
     struct Student student1;
     
     // 初始化結構體
     student1.id = 1001;
     strcpy(student1.name, "張小明");
     student1.gpa = 3.75;
     
     // 顯示結構體內容
     printf("學生ID: %d\n", student1.id);
     printf("學生姓名: %s\n", student1.name);
     printf("學生GPA: %.2f\n", student1.gpa);
     
     // 結構體初始化語法
     printf("\n===== 結構體初始化語法 =====\n");
     struct Student student2 = {1002, "李小華", 3.85};
     printStudent(student2);
     
     // 使用指定符初始化（C99起支援）
     struct Student student3 = {
         .id = 1003,
         .name = "王大明",
         .gpa = 3.92
     };
     printStudent(student3);
     
     // 結構體指標
     printf("\n===== 結構體指標 =====\n");
     struct Student *pStudent = &student1;
     printf("通過指標訪問：\n");
     printf("學生ID: %d\n", pStudent->id);
     printf("學生姓名: %s\n", pStudent->name);
     printf("學生GPA: %.2f\n", pStudent->gpa);
     
     // 修改結構體內容
     modifyStudent(pStudent, 1001, "張小明（已修改）", 3.80);
     printf("\n修改後的結構體內容：\n");
     printStudent(student1);
     
     // 結構體數組
     printf("\n===== 結構體數組 =====\n");
     struct Student class[3] = {
         {1001, "學生A", 3.5},
         {1002, "學生B", 3.7},
         {1003, "學生C", 3.9}
     };
     
     printf("班級學生列表：\n");
     for (int i = 0; i < 3; i++) {
         printStudent(class[i]);
     }
     
     // 計算兩點之間的距離
     printf("\n===== 結構體計算示例 =====\n");
     struct Point p1 = {10, 20};
     struct Point p2 = {30, 40};
     printf("點1: (%d, %d)\n", p1.x, p1.y);
     printf("點2: (%d, %d)\n", p2.x, p2.y);
     printf("兩點間距離: %.2f\n", calculateDistance(p1, p2));
     
     // 嵌套結構體
     printf("\n===== 嵌套結構體 =====\n");
     struct Person person1 = {
         .name = "陳大文",
         .age = 30,
         .birthdate = {1, 5, 1995}
     };
     printPerson(person1);
     
     // 日期比較
     printf("\n===== 結構體比較 =====\n");
     struct Date d1 = {15, 3, 2023};
     struct Date d2 = {20, 3, 2023};
     
     printf("日期1: ");
     printDate(d1);
     printf("日期2: ");
     printDate(d2);
     
     int comp = compareDate(d1, d2);
     if (comp < 0) {
         printf("日期1早於日期2\n");
     } else if (comp > 0) {
         printf("日期1晚於日期2\n");
     } else {
         printf("兩個日期相同\n");
     }
     
     // 使用聯合
     printf("\n===== 聯合使用示例 =====\n");
     struct DataValue value1 = {'i', {.i_val = 42}};
     struct DataValue value2 = {'f', {.f_val = 3.14}};
     struct DataValue value3 = {'c', {.c_val = 'A'}};
     
     printDataValue(value1);
     printDataValue(value2);
     printDataValue(value3);
     
     // 結構體動態分配
     printf("\n===== 結構體動態分配 =====\n");
     struct Student *dynamicStudent = (struct Student *)malloc(sizeof(struct Student));
     
     if (dynamicStudent == NULL) {
         printf("記憶體分配失敗\n");
         return 1;
     }
     
     dynamicStudent->id = 2001;
     strcpy(dynamicStudent->name, "動態分配學生");
     dynamicStudent->gpa = 3.95;
     
     printf("動態分配的結構體：\n");
     printStudent(*dynamicStudent);
     
     // 釋放動態分配的記憶體
     free(dynamicStudent);
     printf("釋放動態分配的結構體記憶體\n");
     
     return 0;
 }
 
 // 列印學生信息
 void printStudent(struct Student s) {
     printf("學生ID: %d, 姓名: %s, GPA: %.2f\n", s.id, s.name, s.gpa);
 }
 
 // 修改學生信息
 void modifyStudent(struct Student *s, int id, const char *name, float gpa) {
     s->id = id;
     strcpy(s->name, name);
     s->gpa = gpa;
 }
 
 // 計算兩點間距離
 float calculateDistance(struct Point p1, struct Point p2) {
     int dx = p2.x - p1.x;
     int dy = p2.y - p1.y;
     return sqrt(dx * dx + dy * dy);
 }
 
 // 列印日期
 void printDate(struct Date date) {
     printf("%d/%d/%d\n", date.day, date.month, date.year);
 }
 
 // 比較兩個日期
 int compareDate(struct Date d1, struct Date d2) {
     if (d1.year != d2.year) {
         return d1.year - d2.year;
     }
     if (d1.month != d2.month) {
         return d1.month - d2.month;
     }
     return d1.day - d2.day;
 }
 
 // 列印人物信息
 void printPerson(struct Person p) {
     printf("姓名: %s\n", p.name);
     printf("年齡: %d\n", p.age);
     printf("出生日期: ");
     printDate(p.birthdate);
 }
 
 // 列印DataValue聯合體的值
 void printDataValue(struct DataValue dv) {
     switch (dv.type) {
         case 'i':
             printf("整數值: %d\n", dv.data.i_val);
             break;
         case 'f':
             printf("浮點值: %.2f\n", dv.data.f_val);
             break;
         case 'c':
             printf("字符值: %c\n", dv.data.c_val);
             break;
         default:
             printf("未知類型值\n");
     }
 }