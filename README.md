# C語言程式設計練習集

這個專案包含從基礎到進階的C語言程式設計練習，按類別分類在不同的目錄中，每個練習都是獨立的C檔案，可以單獨編譯執行並查看結果。適合C語言學習者參考使用。

## 專案結構

```
C-Programming-Exercise/
├── README.md               # 專案說明文件
├── LICENSE                 # MIT許可證
├── Makefile                # 主Makefile
├── run_menu.c              # 選單程式（便於編譯執行）
├── src/                    # 源碼目錄
│   ├── basics/             # 基礎部分
│   ├── control_flow/       # 控制流程
│   ├── functions/          # 函數
│   ├── arrays_pointers/    # 陣列與指標
│   ├── strings/            # 字串處理
│   ├── structures/         # 結構體
│   ├── file_io/            # 檔案輸入輸出
│   ├── memory/             # 記憶體管理
│   ├── preprocessor/       # 預處理器
│   └── multi_file/         # 多檔案程式設計
└── bin/                    # 編譯產物目錄
```

## 快速開始

您可以使用以下任一方式開始使用此專案：

### 使用選單系統（推薦）

1. 編譯選單程式：
   ```
   gcc -o run_menu run_menu.c
   ```

2. 執行選單程式：
   ```
   ./run_menu
   ```

3. 從選單中選擇您想執行的C程式。選單系統會自動編譯、執行程式。

### 使用Makefile

專案提供了完整的Makefile來簡化編譯過程：

1. 編譯所有程式：
   ```
   make
   ```

2. 編譯並執行選單程式：
   ```
   make menu
   ```

3. 清理編譯產物：
   ```
   make clean
   ```

4. 列出所有可執行文件：
   ```
   make list
   ```

## 專案內容

本專案包含以下類別的練習：

### 基礎部分 (basics)
- `hello_world.c` - 最基本的C程式，演示如何輸出文字到屏幕
- `data_types.c` - 展示C語言中的基本數據類型、變數和運算

### 控制流程 (control_flow)
- `conditions.c` - 演示C語言中的條件語句，包括if-else、switch和三元運算符
- `loops.c` - 演示C語言中的循環結構，包括for、while和do-while循環

### 函數 (functions)
- `basic_functions.c` - 演示C語言中函數的基本用法，包括函數聲明、定義和調用
- `recursion.c` - 演示C語言中遞迴函數的使用，包括階乘、斐波那契數列、最大公約數等

### 陣列與指標 (arrays_pointers)
- `arrays.c` - 展示C語言中陣列的基本操作，包括一維和二維陣列的使用
- `pointers.c` - 演示C語言中指標的基本概念和操作

### 字串處理 (strings)
- `string_basics.c` - 演示C語言中字串的基本操作，包括字串的宣告、操作與處理

### 結構體與聯合 (structures)
- `structure_basics.c` - 演示C語言中結構體的基本使用

### 檔案操作 (file_io)
- `file_operations.c` - 演示C語言中檔案的基本輸入輸出操作

### 動態記憶體管理 (memory)
- `dynamic_memory.c` - 演示C語言中動態記憶體分配和管理

### 預處理器 (preprocessor)
- `preprocessor.c` - 展示C語言預處理器的使用

### 多檔案程式設計 (multi_file)
- `multi_file_main.c` - 多檔案程式設計主程式
- `calculator.h` / `calculator.c` - 計算器功能模組
- `utils.h` / `utils.c` - 工具函數模組

## 學習路徑建議

1. **基礎學習**：先從`basics`目錄開始，理解C語言的基本語法和數據類型。

2. **控制流程**：學習`control_flow`目錄中的檔案，掌握條件判斷和循環結構。

3. **函數與遞迴**：通過`functions`目錄學習函數的定義和使用，以及遞迴的概念。

4. **陣列與指標**：`arrays_pointers`目錄將幫助您理解C語言中非常重要的陣列和指標概念。

5. **字串處理**：使用`strings`目錄學習C語言中字串的處理方法。

6. **結構體與檔案**：透過`structures`和`file_io`目錄學習更複雜的數據結構和檔案操作。

7. **進階主題**：最後探索`memory`和`preprocessor`等進階主題。

8. **多檔案程式設計**：學習如何組織較大的程式專案，將程式碼分割到多個檔案中。

## 手動編譯和執行

如果您想手動編譯和執行某個特定的C程式，可以使用以下命令：

### 在Linux/macOS系統:
```
gcc -o bin/程式名稱 src/目錄/源檔案.c
./bin/程式名稱
```

### 在Windows系統:
```
gcc -o bin\程式名稱.exe src\目錄\源檔案.c
bin\程式名稱.exe
```

## 注意事項

- 某些程式可能需要用戶輸入，請按提示操作
- 某些程式使用了隨機數生成，因此每次運行結果可能不同
- 編譯時如出現警告或錯誤，請檢查程式碼或環境設置
- 使用選單系統或Makefile可以大大簡化編譯和執行過程
- 本專案中的所有程式均為學習參考用途，代碼風格遵循常見的C語言規範