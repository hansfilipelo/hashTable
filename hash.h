#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

class Hash{
public:
    Hash(int);
    int hash(std::string key);
    void put(std::string inName, std::string inCPU);
    std::string get(std::string name);
    void remove(std::string name);
    
protected:
    int tableSize;
    
    struct item{
        std::string name;
        std::string cpu;
        item* next = nullptr;
        item* parent = nullptr;
    };
    
    std::vector<item*> hashTable;
};