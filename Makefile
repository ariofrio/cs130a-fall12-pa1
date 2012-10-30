CXXFLAGS=
LDFLAGS=

SRC=\
     Quash.o \
     quash.o

all: prog1

.PHONY: all clean

prog1: $(SRC)
	$(CXX) $(LDFLAGS) $^ -o $@

test: all
	test/run_all.sh

clean:
	rm -f *.o 
	rm -f prog1

