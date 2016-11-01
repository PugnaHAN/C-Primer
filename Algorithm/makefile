CC = gcc
CXX = g++

CFLAGS = -std=c++11 -g -Wall -Iinclude
CXXFLAGS = $(CFLAGS)

MAIN := main
OBJS := main.o
OBJS += functions.o

vpath %.cpp src
vpath %.h include

.SUFFIXES:.cpp
%.o:%cpp
	$(CXX) $(CXXFLAGS) -c $<

$(MAIN):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean exec
clean:
	rm -f *.o

exec:
	./$(MAIN)
