CC 	= gcc
CFLAGS 	= -c -Wall
LDFLAGS = 
ifeq ($(CC), gcc)
	CFLAGS += -std=c99
endif
ifdef DEBUG # add debugging symbols
	CFLAGS += -g -ggdb -O0
	LDFALGS += -g -ggdb -O0
else # performance flags
	CFLAGS += -O3
endif
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)
DEPS 	= sorting.h
EXEC 	= sorts

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

.c.o: $(DEPS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(EXEC) $(OBJECTS)
