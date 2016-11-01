CC = gcc
CXX = g++

CFLAGS = -std=c++11 -g -Wall -Iinclude
CXXFLAGS = $(CFLAGS)

vpath %.cpp src
vpath %.h include

MAIN = main
OBJS = main.o
OBJS += functions.o
OBJS += StrBlobPtr.o
OBJS += StrBlob.o

.SUFFIXES:.cpp
%.o:%.cpp
	@echo ------------------------------------------------------------------------------------------------
	$(CXX) $(CXXFLAGS) -c $<

$(MAIN):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean exec
clean:
	rm -rf *.o
exec:
	./$(MAIN)
