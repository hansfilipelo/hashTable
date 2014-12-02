CCC = g++
	CCFLAGS = -g -std=c++11 -pedantic -Wall -Wextra 
	OBJECTS = main.o hash.o

hashTable: $(OBJECTS)
	$(CCC) $(CCFLAGS) $(OBJECTS) -o hashTable

main.o: main.cpp hash.h
	$(CCC) $(CCFLAGS) -c main.cpp

hash.o: hash.cpp hash.h
	$(CCC) $(CCFLAGS) -c hash.cpp

clean:
	@ \rm -f ./*.o
	@ \rm -f ./Styr_m

