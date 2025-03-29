/**
 * 檔案名稱: preprocessor.c
 * 描述: 展示C語言預處理器的使用
 * 
 * 編譯指令: gcc -o preprocessor preprocessor.c
 * 執行指令: ./preprocessor
 */

 #include <stdio.h>

 // 基本的宏定義
 #define PI 3.14159
 #define MAX_STUDENTS 100
 #define SQUARE(x) ((x) * (x))
 #define MAX(a, b) ((a) > (b) ? (a) : (b))
 
 // 多行宏定義
 #define DEBUG_PRINT(msg, val) do { \
     printf("DEBUG - %s: %d\n", msg, val); \
 } while(0)
 
 // 條件編譯
 #define DEBUG_MODE 1
 #define RELEASE_MODE 0
 
 // 預定義的宏
 void printPredefinedMacros() {
     printf("\n===== 預定義的宏 =====\n");
     printf("檔案名: %s\n", __FILE__);
     printf("行號: %d\n", __LINE__);
     printf("編譯日期: %s\n", __DATE__);
     printf("編譯時間: %s\n", __TIME__);
     printf("符合ANSI標準: %d\n", __STDC__);
 }
 
 // 簡單的條件編譯示例
 void conditionalCompilation() {
     printf("\n===== 條件編譯 =====\n");
     
 #if DEBUG_MODE
     printf("DEBUG模式已啟用\n");
 #else
     printf("RELEASE模式已啟用\n");
 #endif
 
 #ifdef DEBUG_MODE
     printf("DEBUG_MODE已定義\n");
 #endif
 
 #ifndef UNUSED_MACRO
     printf("UNUSED_MACRO未定義\n");
 #endif
 }
 
 // 使用#pragma指令
 void pragmaDirectives() {
     printf("\n===== #pragma指令 =====\n");
     
     // #pragma message
     #pragma message("這是一個編譯期間的訊息")
     
     // 其他常見的#pragma
     printf("常見的#pragma指令包括:\n");
     printf("1. #pragma once - 防止頭文件被多次包含\n");
     printf("2. #pragma pack - 控制結構體成員的對齊方式\n");
     printf("3. #pragma warning - 控制編譯器警告\n");
     
     // 使用GCC特定的#pragma
     #ifdef __GNUC__
     printf("這是GCC編譯器特有的#pragma示例\n");
     #endif
 }
 
 // 宏運算符示例
 void macroOperators() {
     printf("\n===== 宏運算符 =====\n");
     
     // 字符串化運算符 (#)
     #define STRINGIFY(x) #x
     printf("STRINGIFY(hello): %s\n", STRINGIFY(hello));
     
     // 連接運算符 (##)
     #define CONCAT(a, b) a##b
     int xy = 42;
     printf("CONCAT(x, y): %d\n", CONCAT(x, y));
     
     // 可變參數宏
     #define LOG_ERROR(format, ...) printf("ERROR: " format "\n", ##__VA_ARGS__)
     LOG_ERROR("發生錯誤，錯誤碼: %d", 404);
     LOG_ERROR("未知錯誤");
 }
 
 // 預處理器命令示例
 void preprocessorCommands() {
     printf("\n===== 預處理器命令 =====\n");
     
     // 預處理器範例
     printf("編譯此程式時可以使用以下選項：\n");
     printf("gcc -o preprocessor preprocessor.c -DDEBUG_LEVEL=2\n");
     
     // 根據命令行定義的宏進行編譯
     #ifndef DEBUG_LEVEL
     #define DEBUG_LEVEL 0
     #endif
     
     printf("當前DEBUG_LEVEL: %d\n", DEBUG_LEVEL);
     
     #if DEBUG_LEVEL >= 2
     printf("詳細除錯訊息已啟用\n");
     #elif DEBUG_LEVEL >= 1
     printf("基本除錯訊息已啟用\n");
     #else
     printf("除錯訊息已禁用\n");
     #endif
 }
 
 // 展示宏的使用和可能的問題
 void macroUsageExamples() {
     printf("\n===== 宏使用示例 =====\n");
     
     // 基本宏用法
     printf("PI = %.5f\n", PI);
     printf("MAX_STUDENTS = %d\n", MAX_STUDENTS);
     
     // 帶參數的宏
     int a = 5;
     printf("SQUARE(5) = %d\n", SQUARE(5));
     printf("SQUARE(a) = %d\n", SQUARE(a));
     
     // 避免常見宏錯誤
     printf("SQUARE(2+3) = %d\n", SQUARE(2+3));  // 正確：((2+3) * (2+3))
     
     // MAX宏使用
     printf("MAX(10, 5) = %d\n", MAX(10, 5));
     printf("MAX(a, 7) = %d\n", MAX(a, 7));
     
     // 帶副作用的宏可能導致問題
     int i = 5;
     printf("i = %d\n", i);
     printf("MAX(i++, 5) = %d\n", MAX(i++, 5));  // 注意：i++會被計算兩次
     printf("i = %d\n", i);  // i增加了兩次
 }
 
 // 條件編譯的實際應用
 void conditionalCompilationExamples() {
     printf("\n===== 條件編譯實際應用 =====\n");
     
     // 平台特定代碼
     #ifdef _WIN32
     printf("Windows平台特定代碼\n");
     #elif defined(__APPLE__)
     printf("macOS平台特定代碼\n");
     #elif defined(__linux__)
     printf("Linux平台特定代碼\n");
     #else
     printf("其他平台代碼\n");
     #endif
     
     // 根據編譯器版本選擇代碼
     #ifdef __GNUC__
     printf("GCC編譯器版本: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
     #endif
     
     // 功能開關
     #define ENABLE_FEATURE_X 1
     
     #if ENABLE_FEATURE_X
     printf("功能X已啟用\n");
     #else
     printf("功能X已禁用\n");
     #endif
 }
 
 // 預處理器的高級應用
 void advancedPreprocessor() {
     printf("\n===== 預處理器高級應用 =====\n");
     
     // 巨集遞迴
     #define REPEAT_TWICE(x) x x
     #define REPEAT_FOUR_TIMES(x) REPEAT_TWICE(REPEAT_TWICE(x))
     
     printf("REPEAT_FOUR_TIMES(A): %s\n", REPEAT_FOUR_TIMES("A"));
     
     // 條件表達式
     #if defined(DEBUG_MODE) && DEBUG_MODE == 1
     printf("DEBUG_MODE已啟用並設為1\n");
     #endif
     
     // 使用#undef取消宏定義
     #undef PI
     #define PI 3.14  // 重新定義為不同的值
     
     printf("重新定義後的PI = %.2f\n", PI);
 }
 
 int main() {
     printf("===== C預處理器示例 =====\n");
     
     // 調用各個演示函數
     printPredefinedMacros();
     conditionalCompilation();
     pragmaDirectives();
     macroOperators();
     preprocessorCommands();
     macroUsageExamples();
     conditionalCompilationExamples();
     advancedPreprocessor();
     
     // 使用DEBUG_PRINT宏
     int test_value = 42;
     DEBUG_PRINT("test_value", test_value);
     
     printf("\n===== 預處理器注意事項 =====\n");
     printf("1. 宏不遵循作用域規則，定義後在整個文件中都有效\n");
     printf("2. 宏只是文本替換，可能導致意外行為\n");
     printf("3. 複雜的宏難以調試\n");
     printf("4. 現代C語言中，很多宏功能可以用inline函數代替\n");
     printf("5. 條件編譯對於跨平台代碼非常有用\n");
     
     return 0;
 }