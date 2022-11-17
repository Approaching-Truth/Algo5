CXX=g++
CXXFLAGS=-g
LDFLAGS=-g
LDLIBS=
#LDLIBS= -lgtest_main -lgtest -lpthread

BIN = test
SRC = test_graph.cpp graph_class.cpp disjoint_sets.cpp

OBJ = $(SRC:%.cpp=%.o)
DEP = $(OBJ:%.o=%.d)

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

-include $(DEP)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -MMD -c $< -o $@

.PHONY: clean

clean:
	-rm test  $(OBJ) $(DEP)

