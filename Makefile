CXXFLAGS=
LDFLAGS=

SRC=\
     Quash.o \
     quash.o

all: quash

.PHONY: all clean

quash: $(SRC)
	$(CXX) $(LDFLAGS) $^ -o $@

test: all
	test/run_all.sh

clean:
	rm -f *.o 
	rm -f quash

