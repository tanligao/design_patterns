CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Prototype
OBJ=main.o Prototype.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
