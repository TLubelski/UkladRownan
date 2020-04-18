################
#   Makefile   # 
################

#Name, headers, sources
TARGET=UklRow
_DEPS=common.hh Wektor.hh MacierzKw.hh UklRowL.hh
_OBJ=common.o main.o Wektor.o MacierzKw.o UklRowL.o

####DIRS###
TRG_DIR=./
OBJ_DIR=./obj
INC_DIR=./inc
SRC_DIR=./src

###COMPILER###
CC = g++
CFLAGS = -Wall -pedantic -std=c++14 -iquote $(INC_DIR)
LFLAGS = -Wall -pedantic -std=c++14 -iquote $(INC_DIR)

###FORMULA###
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))
OBJ = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LFLAGS)

.PHONY: clean

clean:
	rm -f ${TRGDIR}$(TARGET) ${OBJ_DIR}/*

