CXX = g++
CXXFLAGS = -std=c++11 -Wall
SRC = ../SRC
BUILD = ../BUILD

SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = timetable

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/$(TARGET) $(SRCS)

clean:
	rm -f $(BUILD)/$(TARGET)
