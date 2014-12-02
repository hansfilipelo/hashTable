#include "hash.h"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    
    Hash table(100);
    
    table.put("Tobias", "Phenom II 960BE");
    table.put("Erik","Core i7 920@EXTRAGAY");
    
    
    cout << table.get("Erik") << endl;
    
    
    
}