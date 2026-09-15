TARGET_EXEC := main

CXX := g++
CPPFLAGS := -MMD -MP
CXXFLAGS := -std=c++17 -pedantic-errors -fdiagnostics-color=always -g

SRCS := $(shell find . -name "*.cpp")
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET_EXEC)
