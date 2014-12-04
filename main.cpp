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
    dict.put("Erik","SlowCPU");
    
    string input;
    
    cout << "Enter name: " << endl;
    getline(cin,input);
    
    cout << dict.get(input) << endl;
    
    return 0;
}

