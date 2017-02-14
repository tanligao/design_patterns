CC			= g++
CFLAGS			= -c -Wall -std=c++11
#LDFLAGS			= -lpthread
SOURCES			= main.cpp Factory.h 
INCLUDES		= -I.
OBJECTS			= $(SOURCES:.cpp=.o)
TARGET			= Factory

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
