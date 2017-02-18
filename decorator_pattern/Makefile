CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Decorator
OBJ=main.o Decorator.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
