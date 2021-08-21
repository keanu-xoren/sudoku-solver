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
SRC_DIR := src
INC_DIR := include
OBJ_DIR := build
DBG_DIR := debug
BIN_DIR := bin

# targets
EXE			:= $(BIN_DIR)/sudokusolver
DBG_EXE		:= $(BIN_DIR)/sudokudebugger

# source files
SRC			:= $(wildcard $(SRC_DIR)/*.cpp)
INC			:= $(wildcard $(INC_DIR)/*.h)

# object files
OBJ 		:= $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DBG_OBJ 	:= $(SRC:$(SRC_DIR)/%.cpp=$(DBG_DIR)/%.o)

# flag settings
CPPFLAGS	:= -I$(INC_DIR)
CPPFLAGS_DBG:= -I$(INC_DIR) -DDEBUG
CXXFLAGS	:= -std=c++14 -Wall -Werror -Wno-missing-braces -O3
CXXFLAGS_DBG:= -std=c++14 -Wall -Werror -Wno-missing-braces -O0 -g 
LDFLAGS		:= -L$(INC_DIR)
LDLIBS		:=

.PHONY: all clean debug

all: $(EXE)

dbg: $(DBG_EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(DBG_EXE): $(DBG_OBJ) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(DBG_DIR)/%.o: $(SRC_DIR)/%.cpp | $(DBG_DIR)
	$(CXX) $(CPPFLAGS_DBG) $(CXXFLAGS_DBG) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR) $(DBG_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR) $(DBG_DIR)

-include $(OBJ:.o=.d)