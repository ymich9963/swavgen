TARGET := swavgen
BUILD_DIR := ./build
OBJECTS := main.o $(TARGET).o
CFLAGS := -Wextra -Wall -Wno-unused-parameter -O3
CC := clang
LIB := -lm
.DELETE_ON_ERROR:
.SILENT:

.PHONY: all clean tests coverage

all: $(OBJECTS)
	$(CC) -o $(BUILD_DIR)/$(TARGET) $(foreach obj, $(OBJECTS), $(BUILD_DIR)/$(obj)) $(CFLAGS) $(LIB);
	echo "Executable compiled with $(CC) $(CFLAGS)"

$(OBJECTS): %.o: %.c build
	$(CC) -c $< -o $(BUILD_DIR)/$@ -I. $(CFLAGS);
	echo "$@ compiled with $<"

build:
	mkdir $(BUILD_DIR)
	echo "Created /build in" `pwd` 

clean:
	rm -rf $(BUILD_DIR)
	echo "Project /build cleaned."

tests:: 
	echo "Running tests..."
	cd ./tests; \
	$(MAKE) tests;

coverage: 
	echo "Running coverage..."
	$(MAKE) coverage -C ./tests
