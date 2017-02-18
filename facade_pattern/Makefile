CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Facade
OBJ=main.o Facade.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
