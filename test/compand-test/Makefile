OBJECTS := main.o g711.o
BUILD_DIR := ./build
TARGET := test 
CFLAGS := -Wall -O3
CC := clang

ifndef VERBOSE
.SILENT:
endif

.DELETE_ON_ERROR:

.PHONY: all
all: $(OBJECTS)
	cd $(BUILD_DIR); \
	$(CC) $^ -o $(TARGET) $(CFLAGS);
	echo "Executable compiled with $(CC) $(CFLAGS)"

$(OBJECTS): %.o: %.c build
	cd $(BUILD_DIR); \
	$(CC) ../$< -c -I. $(CFLAGS);
	echo "$@ compiled with $<"

build:
	mkdir $(BUILD_DIR)
	echo "Created /build in" `pwd` 

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)
	echo "Project /build cleaned."
