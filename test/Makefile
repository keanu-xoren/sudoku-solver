# -----------------------------------------------
#	Sudoku Solver Makefile
#
#	Author	: Keanu X. Richardson
#	Date	: 21 Aug 2021
#	GitHub	: https://github.com/keanu-xoren
#
#
# -----------------------------------------------

# directories
ROOT_DIR	:= ..
ROOT_SRC_DIR:= $(ROOT_DIR)/src
ROOT_INC_DIR:= $(ROOT_DIR)/include

# targets
EXE			:= $(BIN_DIR)/sudokusolver
DBG_EXE		:= $(BIN_DIR)/sudokudebugger

# source files
ROOT_SRC	:= $(wildcard $(ROOT_SRC_DIR)/*.cpp)
ROOT_SRC	:= $(filter-out $(ROOT_SRC_DIR)/main.cpp, $(ROOT_SRC))
ROOT_INC	:= $(wildcard $(ROOT_INC_DIR)/*.h)

# all test files
ALL_TESTS	:= $(wildcard *)
TEST_SRC 	:= $(wildcard */main.cpp)
BUILD_ROOT	:= build
ROOT_OBJ_DIR:= $(BUILD_ROOT)/common

ALL_TESTS	:= $(filter-out Makefile build README.md, $(ALL_TESTS))

TEST_SRC	:= $(addsuffix /main.cpp, $(ALL_TESTS))
TEST_BUILD	:= $(addprefix $(BUILD_ROOT)/, $(ALL_TESTS))
TEST_BIN_DIR:= $(addsuffix bin/, $(ALL_TESTS))
TEST_OBJ_DIR:= $(addsuffix /build, $(TEST_OBJ_DIR))


# common object files
ROOT_OBJ 	:= $(ROOT_SRC:$(ROOT_SRC_DIR)/%.cpp=$(ROOT_OBJ_DIR)/%.o)
#TEST_OBJ	:= $(TEST_SRC:%/main.cpp=build/%/build/main.o)

# flag settings
CPPFLAGS	:= -I$(ROOT_INC_DIR) -DDEBUG -DTEST_CONFIG
CXXFLAGS	:= -std=c++14 -Wall -Werror -Wno-missing-braces -O0 -g 
LDFLAGS		:= -L$(ROOT_INC_DIR)
LDLIBS		:=

.PHONY: *

all: $(ALL_TESTS)

$(ALL_TESTS): $(ROOT_OBJ)
	mkdir -p build/$@/build
	mkdir -p build/$@/bin
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $@/main.cpp -o build/$@/build/main.o
	$(CXX) $(LDFLAGS) $^ build/$@/build/main.o $(LDLIBS) -o build/$@/bin/test
	
$(ROOT_OBJ_DIR)/%.o: $(ROOT_SRC_DIR)/%.cpp | $(ROOT_OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

build/%/build:
	mkdir -p $@

$(ROOT_OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BUILD_ROOT)

-include $(ROOT_OBJ:.o=.d)
