CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# 源碼目錄
SRC_DIR = src
BIN_DIR = bin

# 自動尋找所有C文件
C_FILES = $(shell find $(SRC_DIR) -type f -name "*.c")
TARGETS = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(C_FILES))

# 主目標
all: directories $(TARGETS) run_menu

# 創建必要的目錄
directories:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(BIN_DIR)/basics
	@mkdir -p $(BIN_DIR)/control_flow
	@mkdir -p $(BIN_DIR)/functions
	@mkdir -p $(BIN_DIR)/arrays_pointers
	@mkdir -p $(BIN_DIR)/strings
	@mkdir -p $(BIN_DIR)/structures
	@mkdir -p $(BIN_DIR)/file_io
	@mkdir -p $(BIN_DIR)/memory
	@mkdir -p $(BIN_DIR)/preprocessor
	@mkdir -p $(BIN_DIR)/multi_file

# 多文件程式特殊處理
$(BIN_DIR)/multi_file/multi_file_program: $(SRC_DIR)/multi_file/multi_file_main.c $(SRC_DIR)/multi_file/calculator.c $(SRC_DIR)/multi_file/utils.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $^

# 通用編譯規則
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $<

# 選單程式
run_menu: run_menu.c
	$(CC) $(CFLAGS) -o $@ $<

# 執行選單程式
menu: run_menu
	./run_menu

# 清理編譯產物
clean:
	rm -rf $(BIN_DIR)
	rm -f run_menu

# 特定目標幫助
help:
	@echo "使用方法:"
	@echo "  make          - 編譯所有程式"
	@echo "  make menu     - 編譯並執行選單程式"
	@echo "  make clean    - 清理所有編譯產物"
	@echo "  make help     - 顯示此幫助訊息"

# 列出所有可執行文件
list:
	@echo "可執行文件列表:"
	@find $(BIN_DIR) -type f -executable | sort

.PHONY: all clean help menu list directories