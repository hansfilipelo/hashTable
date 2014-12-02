#include "hash.h"
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    
    Hash table(100);
    
    table.put("Tobias", "Phenom II 960BE");
    table.put("Jens", "Core i5 4690K");
    table.put("Erik","Core i7 920@extraGay");
    table.put("Hans-Filip", "Core i5 4288U");
    table.put("David","Core i3 2370M");
    table.put("Erhl","Celeron J1900");
    
    string input;
    bool loop = true;
    
    while (loop) {
        string name;
        string cpu;
        
        cout << "Please enter a name to add dictionary" << endl;
        getline(cin,name);
        
        if (name.size() == 0) {
            loop = false;
            break;
        }
        cout << "Please enter a CPU for " << name << endl;
        getline(cin,cpu);
        
        table.put(name,cpu);
    }
    
    loop = true;
    
    while (loop) {
        
        
        cout << "Please enter a name to find out which CPU they're using" << endl;
        getline(cin,input);
        
        if (input.size() == 0) {
            loop = false;
            break;
        }
        cout << table.get(input) << endl;
    }
}