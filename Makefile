TARGET_EXEC := monopolish.out

# Commands
RM := rm -r

# Directories
BUILD_DIR := ./build
SRC_DIR := ./src
PROJECT_BINARY_DIR := ./bin
DOCS_DIR := ./docs

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

.PHONY: all
all: clean $(PROJECT_BINARY_DIR)/$(TARGET_EXEC)

# Final Target
$(PROJECT_BINARY_DIR)/$(TARGET_EXEC): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build C++ Object Files
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Docs
.PHONY: $(DOCS_DIR)
$(DOCS_DIR):
	$(RM) $(DOCS_DIR)
	doxygen Doxyfile

# Clean
.PHONY: clean
clean:
	$(RM) $(BUILD_DIR)
