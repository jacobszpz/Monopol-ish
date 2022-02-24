# Output
TARGET_EXEC := monopolish.out
TEST_TARGET_EXEC := test.out

# Commands
RM := rm -rf

# Directories
BUILD_DIR := ./build
SRC_DIR := ./src
TEST_DIR := ./test
PROJECT_BINARY_DIR := ./bin
DOCS_DIR := ./docs
DOXYGEN_DIRS := ./html ./latex
DOXYGEN_DIRS := $(DOXYGEN_DIRS:%=$(DOCS_DIR)/%)

# googletest
GTEST_DIR := /usr/src/gtest
GTEST_MAIN := $(GTEST_DIR)/src/gtest_main.cc
GTEST_ALL:= $(GTEST_DIR)/src/gtest-all.cc

# Source Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
HEADERS := $(wildcard $(SRC_DIR)/*.h)
TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)

# Object Files
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)

# Include Directories
INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CPPFLAGS := $(INC_FLAGS)

# Default Target
.PHONY: all
all: clean $(PROJECT_BINARY_DIR)/$(TARGET_EXEC)

# Final Target
$(PROJECT_BINARY_DIR)/$(TARGET_EXEC): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Test
$(TEST_DIR): $(TEST_OBJS) $(OBJS)
	mkdir -p $(PROJECT_BINARY_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $(PROJECT_BINARY_DIR)/$(TEST_TARGET_EXEC) \
		$(GTEST_ALL) $(GTEST_MAIN) -I $(GTEST_DIR) -I /usr/include \
		-L /usr/local/lib -lpthread

# Build C++ Object Files
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Documentation
.PHONY: $(DOCS_DIR)
$(DOCS_DIR): $(SRCS) $(HEADERS)
	$(RM) $(DOXYGEN_DIRS)
	doxygen Doxyfile

# Clean
.PHONY: clean
clean:
	$(RM) $(PROJECT_BINARY_DIR)
	$(RM) $(BUILD_DIR)
	$(RM) $(DOXYGEN_DIRS)
