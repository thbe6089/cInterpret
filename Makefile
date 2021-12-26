SDIR := ./src
IDIR := ./include
BDIR := ./bin
ODIR := ./build
LDIR := ./lib

TARGET := $(BDIR)/cinterpret

SRC := $(shell find $(SDIR) -name *.c)
OBJ := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

F_LIBS := $(shell find $(LDIR) -name *.a)
LIB := $(patsubst $(LDIR)/%.a, -l%, $(F_LIBS))

CC := gcc
CFLAGS := -I$(IDIR) -L$(LDIR) $(LIB)

all: $(BDIR) $(ODIR) $(TARGET)

# Add in debugging flags
dev: CFLAGS += -g -Wall -Wextra
dev: all

$(TARGET): $(OBJ)
	@$(CC) -o$@ $^

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) -c -o$@ $< $(CFLAGS)

$(BDIR): 
	@[ ! -d "$(BDIR)" ] && mkdir $(BDIR)

$(ODIR): 
	@[ ! -d "$(ODIR)" ] && mkdir $(ODIR)

# -----------------------------------------------
# CLEAN
# -----------------------------------------------
.PHONY: clean

clean:
	@rm -rf $(BDIR) $(ODIR)