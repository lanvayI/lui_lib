CC = gcc

TARGET = app.exe

SRC_DIR = ../src
INC_DIR = ../include
LIB_DIR = ../lib

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I$(INC_DIR)
LDFLAGS = -L$(LIB_DIR)
RFLAG = -lraylib -lopengl32 -lgdi32 -lwinmm -luser32 -mconsole

.PHONY: all clean run

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS) $(RFLAG) -mwindows

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)