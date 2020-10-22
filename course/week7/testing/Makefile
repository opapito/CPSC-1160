SANFLAGS = -fsanitize=address -static-libasan
CXXFLAGS += -Wall -Wextra -Wpedantic -g -std=c++14 $(SANFLAGS)
LDFLAGS += $(SANFLAGS)
main: main.o social_distancingv3.o
	$(CXX) -o $@ $^ $(LDFLAGS)
.phony: clean
clean:
	$(RM)  *.o