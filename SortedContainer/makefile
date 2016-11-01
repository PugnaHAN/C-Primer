CC = gcc
CXX = g++

CFLAGS = -std=c++11 -g -Wall -Iinclude
CXXFLAGS = $(CFLAGS)

VPATH += include src

MAIN := main
OBJS := main.o

.SUFFIXES:.cpp
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $<

$(MAIN):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean exec
clean:
	rm -f %.o $(MAIN)
exec:
	./$(MAIN)
