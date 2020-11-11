CC 		 	:= clang
CFLAGS	:= -fsanitize=address -fno-omit-frame-pointer -Wall -Wextra -O3 -g
SRC			:= src
BIN     := driver
LIBS		:= -lm
OBJS		:=
OBJDIR	:= obj

OBJS :=$(addprefix $(OBJDIR)/,graph.o heap.o djkstra.o driver.o)

$(BIN): directories $(OBJS) $(SRC)/$(BIN).c
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

$(OBJDIR) $(OBJDIR)/%.o: $(SRC)/%.c $(SRC)/%.h $(ENTITIES)
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p $(OBJDIR)

clean:
	rm -f *~ *.o $(TARGET)
	rm -rf obj

all: clean $(BIN)
