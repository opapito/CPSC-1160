SANFLAGS = -fsanitize=address -static-libasan
CXXFLAGS += -Wall -Wextra -Wpedantic -g -std=c++14 $(SANFLAGS)
LDFLAGS += $(SANFLAGS)
main: q07.o
	$(CXX) -o $@ $^ $(LDFLAGS)
.phony: clean
clean:
	$(RM)  *.o