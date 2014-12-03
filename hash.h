#ifndef hash_h
#define hash_h

#include <string>
#include <vector>
#include <utility>


class Hash{
public:
    Hash(int size = 100);
    int hash(std::string key);
    void put(std::string key, std::string value);
    std::string get(std::string key);
    void remove(std::string key);
    
protected:
    std::vector<std::vector<std::pair<std::string,std::string>*>*> hashTable;
    int tableSize;
};



#endif