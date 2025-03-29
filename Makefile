CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# 目標可執行文件
TARGETS = hello_world data_types conditions loops basic_functions \
          recursion arrays pointers string_basics structure_basics \
          file_operations dynamic_memory preprocessor \
          multi_file_program

# 默認目標
all: $(TARGETS)

# 基本程式
hello_world: hello_world.c
	$(CC) $(CFLAGS) -o $@ $<

data_types: data_types.c
	$(CC) $(CFLAGS) -o $@ $<

# 控制流程
conditions: conditions.c
	$(CC) $(CFLAGS) -o $@ $<

loops: loops.c
	$(CC) $(CFLAGS) -o $@ $<

# 函數
basic_functions: basic_functions.c
	$(CC) $(CFLAGS) -o $@ $<

recursion: recursion.c
	$(CC) $(CFLAGS) -o $@ $<

# 陣列與指標
arrays: arrays.c
	$(CC) $(CFLAGS) -o $@ $<

pointers: pointers.c
	$(CC) $(CFLAGS) -o $@ $<

# 字串處理
string_basics: string_basics.c
	$(CC) $(CFLAGS) -o $@ $<

# 結構體
structure_basics: structure_basics.c
	$(CC) $(CFLAGS) -o $@ $< -lm

# 檔案操作
file_operations: file_operations.c
	$(CC) $(CFLAGS) -o $@ $<

# 動態記憶體
dynamic_memory: dynamic_memory.c
	$(CC) $(CFLAGS) -o $@ $< -lm

# 預處理器
preprocessor: preprocessor.c
	$(CC) $(CFLAGS) -o $@ $<

# 多文件程式 (特殊處理)
multi_file_program: multi_file_main.c calculator.c utils.c
	$(CC) $(CFLAGS) -o $@ $^

# 選單程式
run_menu: run_menu.c
	$(CC) $(CFLAGS) -o $@ $<

# 執行選單程式
menu: run_menu
	./run_menu

# 清理編譯產物
clean:
	rm -f $(TARGETS) run_menu

# 特定目標幫助
help:
	@echo "使用方法:"
	@echo "  make          - 編譯所有程式"
	@echo "  make hello_world - 編譯特定程式"
	@echo "  make clean    - 清理所有編譯產物"
	@echo "  make menu     - 編譯並執行選單程式"
	@echo "  make help     - 顯示此幫助訊息"
	@echo ""
	@echo "可用的目標:"
	@echo "  $(TARGETS) run_menu"

.PHONY: all clean help menu