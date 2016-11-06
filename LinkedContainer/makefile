CC = gcc
CXX = clang++

CFLAGS = -std=c++11 -g -Wall -Iinclude
CXXFLAGS = $(CFLAGS)

vpath %.cpp src
vpath %.h include

MAIN = main
OBJS = main.o
OBJS += linked_container.o

.SUFFIXES:.cpp
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(MAIN):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean exec
clean:
	rm -rf *.o
exec:
	./$(MAIN)
