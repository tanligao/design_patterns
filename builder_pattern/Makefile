CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Builder
OBJ=main.o Builder.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
