CC = clang
CXX = g++

CFLAGS = -std=c++11 -g -Iinclude
CXXFLAGS = $(CFLAGS)

MAIN := main
OBJS := main.o

vpath %.cpp src
vpath %.h include

.SUFFIXES:.cpp
%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $^

$(MAIN):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY:clean exec
clean:
	rm -f *.o
exec:
	./$(MAIN)
