#include <cstdio>
#include <iostream>
#include "ArrayList.h"

using namespace std;


int main (){
    ArrayList<int> lst;
    for(int i =1; i <11; i++){
        lst.push_back(i);
    }
    
    return 0;
}
