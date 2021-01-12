.SUFFIXES:
.PHONY: all clean

CXX := g++
CXXFLAGS := -std=c++11 -Wall -g
INCLUDES := -Iinclude
LIBS := -lm
TARGET := eight_puzzle_solver.out 
# Use the line below instead if you are using Windows
# TARGET := eight_puzzle_solver.exe

SRCDIR := src
SRCOBJS := $(patsubst %.cpp, %.o, $(wildcard $(SRCDIR)/*.cpp))
OBJS := $(SRCOBJS) 

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) $^ -o $@

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< -c -o $@

clean:
	-@rm -f $(TARGET)
	-@rm -f $(OBJS)