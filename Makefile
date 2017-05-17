CXX=g++
SRC=$(wildcard src/*.cpp)
IDIR=include
EXENAME=bin/ush
LIBS=-ledit


default: $(SRC)
	$(CXX) $(SRC) -o $(EXENAME) -std=c++11 -Wall -march=native -I $(IDIR) $(LIBS)

generic: $(SRC)
	$(CXX) $(SRC) -o $(EXENAME) -std=c++11 -Wall -I $(IDIR) $(LIBS)

debug: $(SRC)
	$(CXX) $(SRC) -o $(EXENAME) -std=c++11 -Wall -march=native -I $(IDIR) $(LIBS) -g

clean:
	rm $(EXENAME)
