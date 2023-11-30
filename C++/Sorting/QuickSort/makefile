#build:
#	g++ -g -std=c++17 -Wall -Isrc/include -o main  src/main.cc
#make run:
#	./main
#clean:
#	rm main





# Makefile for C++ project

CXX := g++
CXXFLAGS := -std=c++14 -Wall
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
SRC := $(wildcard $(SRC_DIR)/*.cc)
HEADERS := $(wildcard $(INCLUDE_DIR)/*.hh)
OBJ := $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRC))
TARGET := myprogram

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*  $(BUILD_DIR) $(TARGET)

run:
	./$(TARGET)

.PHONY: all clean