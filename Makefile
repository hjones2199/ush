CXX=c++
SRC=$(wildcard src/*.cpp)
IDIR=include
EXENAME=bin/ush
LIBS=-ledit


default: $(SRC)
	$(CXX) $(SRC) -o $(EXENAME) -std=c++11 -Wall -I $(IDIR) $(LIBS)

generic: $(SRC)
	$(CXX) $(SRC) -o $(EXENAME) -std=c++11 -Wall -I $(IDIR) $(LIBS)

native: $(SRC)
	$(CXX) $(SRC) -o $(EXENAME) -std=c++11 -march=native -Wall -I $(IDIR) $(LIBS)

debug: $(SRC)
	$(CXX) $(SRC) -o $(EXENAME) -std=c++11 -Wall -I$(IDIR) $(LIBS) -g

install: $(EXENAME)
	cp $(EXENAME) $(out)/$(EXENAME)

clean:
	rm $(EXENAME)
