CC=gcc
CXX=g++
CFLAGS=-Wall -g
CXXFLAGS=

SRC=src
OBJ=objs

CSRCS=$(wildcard $(SRC)/*.c)
CPPSRCS=$(wildcard $(SRC)/*.cpp)

COBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(CSRCS)) 
CPPOBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(CPPSRCS))

BIN=bin
OUT=vm

$(BIN)/$(OUT): $(COBJS) $(CPPOBJS)
	$(CC) -o $@ $(SRC)/main.c 

$(COBJS): $(CSRCS)
	$(CC) $(CFLAGS) -c -o %@ $<

$(CPPOBJS): $(CPPSRCS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run:
	@$(BIN)/./$(OUT)

clean:
	$(RM) $(OBJ)/* $(BIN)/*