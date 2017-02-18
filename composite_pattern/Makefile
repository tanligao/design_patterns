CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Composite
OBJ=main.o Composite.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
