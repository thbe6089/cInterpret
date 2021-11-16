TARGET := ./bin/cinterpret

SDIR := ./src
IDIR := ./include
ODIR := ./build

CC := gcc
CFLAGS := -Wall -Wextra -I$(IDIR)

SRC := $(shell find $(SDIR) -name *.c)
OBJ := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

$(TARGET): $(OBJ)
	@$(CC) -o$@ $^

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) -c -o$@ $< $(CFLAGS)

.PHONY: clean

clean:
	@rm $(ODIR)/*.o $(TARGET)