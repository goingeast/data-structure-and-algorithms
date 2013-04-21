CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=linkedlist

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o
