/**
 * 檔案名稱: utils.c
 * 描述: 工具函數的實現
 */

 #include <stdio.h>
 #include <time.h>
 #include "utils.h"
 
 // 靜態變數（僅在此文件中可見）
 static int calculation_count = 0;
 static time_t start_time;
 
 // 列印程式信息
 void printProgramInfo() {
     // 記錄開始時間
     start_time = time(NULL);
     
     printf("簡易計算器程式\n");
     printf("版本: 1.0\n");
     printf("編譯日期: %s\n", __DATE__);
     printf("編譯時間: %s\n", __TIME__);
     printf("---------------------------\n\n");
 }
 
 // 記錄計算歷史
 void logCalculation(const char *calculation) {
     calculation_count++;
     
     // 獲取當前時間
     time_t now = time(NULL);
     struct tm *local_time = localtime(&now);
     char time_str[20];
     strftime(time_str, sizeof(time_str), "%H:%M:%S", local_time);
     
     printf("\n[%s] 計算記錄 #%d: %s\n", time_str, calculation_count, calculation);
 }
 
 // 列印統計信息
 void printStats() {
     // 計算執行時間
     time_t end_time = time(NULL);
     double elapsed_time = difftime(end_time, start_time);
     
     printf("\n---------------------------\n");
     printf("程式統計:\n");
     printf("計算次數: %d\n", calculation_count);
     printf("執行時間: %.0f 秒\n", elapsed_time);
     printf("---------------------------\n");
 }