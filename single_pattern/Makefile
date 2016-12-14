CC			= g++
CFLAGS			= -c -Wall -std=c++0x
LDFLAGS			= -lpthread
SOURCES			= main.cpp Singleton.cpp Singleton1.cpp Singleton2.cpp 
INCLUDES		= -I.
OBJECTS			= $(SOURCES:.cpp=.o)
TARGET			= Singleton

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
