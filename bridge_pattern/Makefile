CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Bridge
OBJ=main.o Bridge.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
