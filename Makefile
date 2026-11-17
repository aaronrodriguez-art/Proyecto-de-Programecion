CXX = g++
CXXFLAGS = -Wall
SRC = $(wildcard *.cpp)

planilla: $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o planilla
