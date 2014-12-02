#include "hash.h"

using namespace std;

// ---- Constructor -----

Hash::Hash(int startSize){
    tableSize = startSize;
    
    for (int i = 0; i < tableSize; i++) {
        hashTable.push_back(nullptr);
    }
}

// -----------------

int Hash::hash(string key){
    
    int hashVal = 0;
    int index;
    
    for (unsigned long int i = 0; i < key.size(); i++) {
        hashVal += (int)key.at(i);
    }
    
    index = hashVal % tableSize;
    
    return index;
}

// ----------------

void Hash::put(string inName, string inCPU){
    
    int index = this->hash(inName);
    
    if (hashTable.at(index) == nullptr) {
        hashTable.at(index) = new item;
        hashTable.at(index)->name = inName;
        hashTable.at(index)->cpu = inCPU;
    }
    else{
        item* current = hashTable.at(index);
        
        while (current->next != nullptr) {
            current = current->next;
        }
        
        current->next = new item;
        current->next->name = inName;
        current->next->cpu = inCPU;
        current->next->parent = current;
    }
}

// ------------------

string Hash::get(string name){
    
    int index = this->hash(name);
    
    item* node = hashTable.at(index);
    
    if (node != nullptr) {
        
        while (node->next != nullptr) {
            if (node->name == name) {
                break;
            }
            node = node->next;
        }
        
        if (node->name != name) {
            string returnString = name;
            returnString += " not in dictionary.";
            return returnString;
        }
        else{
            return node->cpu;
        }
    }
    else{
        string returnString = name;
        returnString += " not in dictionary.";
        return returnString;
    }
}

// -----------------

void Hash::remove(string name){
    
    int index = this->hash(name);
    
    item* node = hashTable.at(index);
    
    if (node != nullptr) {
        if (node->name == name && node->next != nullptr) {
            hashTable.at(index) = node->next;
            hashTable.at(index)->parent = nullptr;
        }
        else if (node->name == name){
            hashTable.at(index) = nullptr;
        }
        else{
            while (node->next != nullptr) {
                if (node->name == name) {
                    node->next->parent = node->parent;
                }
                node = node->next;
            }
        }
        
        if (node->name == name) {
            delete node;
        }
    }
}


