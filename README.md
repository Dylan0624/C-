# C語言程式設計練習集

這個專案包含從基礎到進階的C語言程式設計練習，每個練習都是獨立的C檔案，可以單獨編譯執行並查看結果。適合C語言學習者參考使用。

## 目錄結構

```
c-programming-exercises/
├── 01-basics/
│   ├── hello_world.c          # 基本的Hello World程式
│   └── data_types.c           # 基本數據類型與變數
├── 02-control-flow/
│   ├── conditions.c           # 條件語句
│   └── loops.c                # 循環結構
├── 03-functions/
│   ├── basic_functions.c      # 函數基礎
│   └── recursion.c            # 遞迴函數
├── 04-arrays-pointers/
│   ├── arrays.c               # 陣列基礎
│   └── pointers.c             # 指標基礎
├── 05-strings/
│   └── string_basics.c        # 字串處理基礎
├── 06-structures/
│   └── structure_basics.c     # 結構體基礎
├── 07-file-io/
│   └── file_operations.c      # 檔案操作
└── 08-advanced/
    └── dynamic_memory.c       # 動態記憶體管理
```

## 編譯與執行

### 在Linux/macOS系統:

1. 開啟終端機
2. 進入到包含C檔案的目錄
   ```
   cd c-programming-exercises/01-basics
   ```
3. 使用gcc編譯程式
   ```
   gcc -o hello_world hello_world.c
   ```
4. 執行編譯後的程式
   ```
   ./hello_world
   ```

### 在Windows系統:

1. 開啟命令提示字元或PowerShell
2. 進入到包含C檔案的目錄
   ```
   cd c-programming-exercises\01-basics
   ```
3. 使用gcc編譯程式
   ```
   gcc -o hello_world.exe hello_world.c
   ```
4. 執行編譯後的程式
   ```
   hello_world.exe
   ```

## 練習說明

每個C檔案頂部都包含註釋，說明了該練習的目的和內容。運行程式後，將顯示相應的輸出結果，幫助理解C語言的相關概念。

## 學習進度建議

1. 從基礎部分開始，理解C語言的基本語法和數據類型
2. 學習控制流程，包括條件語句和循環結構
3. 理解函數的定義和使用，包括遞迴
4. 掌握陣列和指標的概念和應用
5. 學習字串處理技巧
6. 理解結構體和聯合體
7. 學習檔案輸入輸出操作
8. 探索進階主題，如動態記憶體管理、多檔案程式設計等

## 注意事項

- 某些程式可能需要用戶輸入，請按提示操作
- 某些程式使用了隨機數生成，因此每次運行結果可能不同
- 編譯時如出現警告或錯誤，請檢查程式碼或環境設置