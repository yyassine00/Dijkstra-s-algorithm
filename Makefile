CXX=g++

CXXFLAGS=-Wall

TARGET=Prog_lab2_YounesYassine

SRCS=main.cpp 


OBJS=$(SRCS:.cpp=.o)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)