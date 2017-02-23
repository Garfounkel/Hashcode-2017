CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic
CFLAGS += -I src
VPATH = src include tests

SRC = src/main.cc

BIN = hash.out

.PHONY: all debug

all:
	${CXX} ${CXXFLAGS} $(SRC) -o ${BIN}

clean:
	rm -rf ${BIN}

debug:CXXFLAGS+=-g
debug:$(BIN)
