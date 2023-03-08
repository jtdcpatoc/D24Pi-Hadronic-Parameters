CC=g++

CFLAGS = -std=c++17 -c -g -Wall `root-config --cflags` 
LDFLAGS=`root-config --glibs`
INCS = -Iinclude

all: BinningScheme

BinningScheme: src/Binning.cpp src/Utilities.cpp
	$(CC) $(CFLAGS) $(INCS) -o Binning.o src/Binning.cpp
	$(CC) $(CFLAGS) $(INCS) -o Utilities.o src/Utilities.cpp
	$(CC) $(LDFLAGS) -o BinningScheme Binning.o Utilities.o

clean:
	rm -f ./*~ ./*.o ./BinningScheme