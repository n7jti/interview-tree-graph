#Makefile
CC=gcc
CXX=g++
RM=rm -f

CPPUTEST_HOME=./../cpputest

CXXFLAGS=-g -I $(CPPUTEST_HOME)/include -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h 
LDFLAGS=-g 
LDLIBS=-L$(CPPUTEST_HOME)/lib -lCppUTest -lCppUTestExt

SRCS= treegraph.cpp tree.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: treegraph

treegraph: $(OBJS)
	$(CXX) $(LDFLAGS) -o treegraph $(OBJS) $(LDLIBS) 

treegraph.o: treegraph.cpp tree.h

tree.o: tree.cpp tree.h

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) linkedlist
