/**
 * 檔案名稱: calculator.c
 * 描述: 計算器函數的實現
 */

 #include "calculator.h"

 // 加法函數實現
 int add(int a, int b) {
     return a + b;
 }
 
 // 減法函數實現
 int subtract(int a, int b) {
     return a - b;
 }
 
 // 乘法函數實現
 int multiply(int a, int b) {
     return a * b;
 }
 
 // 除法函數實現
 float divide(int a, int b) {
     // 注意：調用者應該檢查b是否為0
     return (float)a / b;
 }