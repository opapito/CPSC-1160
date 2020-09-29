SANFLAGS = -fsanitize=address -static-libasan
CXXFLAGS += -Wall -g -std=c++14 $(SANFLAGS)
LDFLAGS += $(SANFLAGS)
main: strings.o palindrome.o
	$(CXX) -o $@ $^ $(LDFLAGS)
.phony: clean
clean:
	$(RM) main *.o