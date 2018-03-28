CXX=g++
CXXFLAGS=-g -c -Wall
SOURCES=$(wildcard *.cpp)
H_FILES=$(wildcard *.h)
OBJECTS=$(SOURCES:.cpp=.o)
END_NAME=ltest
TAR_NAME=lab05.tar
MAKEFILE=Makefile

all: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(END_NAME)

%.o: %.cpp
	$(CXX) $^ $(CXXFLAGS) -o $@

clean:
	rm $(OBJECTS) $(END_NAME)

run:
	./$(END_NAME)

val: $(END_NAME)
	valgrind -v ./$(END_NAME)

tar:
	tar cvf $(TAR_NAME) $(SOURCES) $(H_FILES) $(MAKEFILE)
