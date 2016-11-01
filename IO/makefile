CC = gcc
CXX = g++

CFLAGS = -std=c++11 -g -Wall -Iinclude
CXXFLAGS = $(CFLAGS)

MAIN = main

OBJS := main.o functions.o
OBJS += Sales_data.o
OBJS += PersonInfo.o


VPATH = include src

.SUFFIXES:%.cc
%.o:%.cc
	$(CXX) $(CXXFLAGS) -c $<	

$(MAIN):$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY:clean exec

clean:
	rm -r $(OBJS)

exec:
	./$(MAIN)
