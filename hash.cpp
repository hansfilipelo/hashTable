#include "hash.h"

using namespace std;

Hash::Hash(int size){
    tableSize = size;
    
    for (int i = 0; i < tableSize; i++) {
        hashTable.push_back(new vector<pair<string,string>*>);
    }
}

// ----------------------

int Hash::hash(string key){
    
    int hashVal = 0;
    
    for (int i = 0; i < key.size(); i++) {
        hashVal += (int)key.at(i);
    }
    
    return hashVal % tableSize;
}

// ----------------------

void Hash::put(string key, string value){
    
    vector<pair<string,string>*>* bucket = hashTable.at(this->hash(key));
    
    
    bucket->push_back(new pair<string,string>);
    bucket->back()->first = key;
    bucket->back()->second = value;
}

// -----------------------

string Hash::get(string key){
    
    vector<pair<string,string>*>* bucket = hashTable.at(this->hash(key));
    
    int i = 0;
    while (i < bucket->size() && bucket->at(i)->first != key) {
        i++;
    }
    
    if ( i >= bucket->size() ) {
        string returnString = "No entry for key ";
        returnString += key;
        return returnString;
    }
    else{
        return bucket->at(i)->second;
    }
}

// ------------------------

void Hash::remove(string key){
    
    vector<pair<string,string>*>* bucket = hashTable.at(this->hash(key));
    
    int i = 0;
    while (i < bucket->size() && bucket->at(i)->first != key) {
        i++;
    }
    
    if ( i >= bucket->size() ) {
        return;
    }
    else{
        delete bucket->at(i);
        bucket->erase(bucket->begin()+i);
    }
}




