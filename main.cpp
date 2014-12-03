#include "hash.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    
    Hash dict;
    
    dict.put("Erik","+46 73-682 43 06");
    dict.put("Erhl","Pooo");
    dict.put("David","076-017 71 15");
    
    string input;
    
    cout << "Enter name: " << endl;
    getline(cin,input);
    
    dict.remove(input);
    
    cout << dict.get(input) << endl;
    
}