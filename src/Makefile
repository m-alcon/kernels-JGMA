CXX  = g++ -std=c++11
OBJ_FOLDER = ../obj/
BIN_FOLDER = ../bin/

SRC = $(wildcard *.cc)
TAR = $(SRC:.cc=.o)
OBJS = $(patsubst %.cpp, $(OBJ_FOLDER)%.o,$(SRC))

.PHONY: all

all: $(TAR) test

test: $(OBJS) | $(BIN_FOLDER)
	$(CXX) -o $(BIN_FOLDER)test $^
    
%.o: %.cc | $(OBJ_FOLDER)
	$(CXX) -c $^ -o $(OBJ_FOLDER)$@

$(BIN_FOLDER):
	mkdir -p $@

$(OBJ_FOLDER):
	mkdir -p $@

clean:
	rm -rf $(OBJ_FOLDER) $(BIN_FOLDER)
