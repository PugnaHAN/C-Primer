CC = gcc -std=c++11
CXX = g++ -std=c++11
CFLAGS = -g -Iinclude

OBJECTS = ch12.o
OBJECTS += Screen.o Sales_item.o
OBJECTS += Sales_data.o Account.o

MAIN = main

vpath %.cpp src
vpath %.h include

.SUFFIXES:.cpp
%.o:%.cpp
	$(CXX) $(CFLAGS) -c $<

${MAIN}:${OBJECTS}
	$(CXX) $(CFLAGS) -o ${MAIN} $(OBJECTS)

.PHONY:clean exec
clean:
	rm *.o ${MAIN}

exec:
	./${MAIN}
