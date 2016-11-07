CC = clang
CXX = clang++

CFLAGS = -std=c++11 -g -Iinclude
CXXFLAGS = $(CFLAGS)

MAIN := main
OBJS := main.o
OBJS += Quote.o Bulk_quote.o
OBJS += Basket.o
OBJS += functions.o

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
