SANFLAGS = -fsanitize=address -static-libasan
CXXFLAGS += -Wall -Wextra -Wpedantic -g -std=c++14 $(SANFLAGS)
LDFLAGS += $(SANFLAGS)
main: fiddling_bases.o 
	$(CXX) -o $@ $^ $(LDFLAGS)
.phony: clean
clean:
	$(RM) main *.o