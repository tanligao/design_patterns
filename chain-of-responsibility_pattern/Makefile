CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Chain_of_responsibility
OBJ=main.o ChainRes.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
