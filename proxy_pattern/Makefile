CC=g++
CFLAGS=-Wall -g
#LIBS=-lcrypt
PROJ=Proxy
OBJ=main.o Proxy.o
$(PROJ):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(PROJ) $(OBJ)
