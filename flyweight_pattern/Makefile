CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=FlyWeight
OBJ=main.o FlyWeight.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
