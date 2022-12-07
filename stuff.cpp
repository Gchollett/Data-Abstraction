#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include "ArrayList.h"
#include "HashMap.h"

using namespace std;


int main (){
    hash<int> stink;
    HashMap<int,char,hash<int>> hashy(stink);
    HashMap<int,char,hash<int>> hash2(stink);
    for(int i=100; i<110; ++i) {
        cout << hash2.size() << endl;
		hash2[i] = 'f';
	}
    cout << hash2.size() << endl;
	for(int i=100; i<110; ++i) {
		hash2.erase(i);
	}
    unsigned int f = 0;
    cout << --f << endl;
    cout << hashy.size() << endl;
    cout << hash2.size() << endl;
    return 0;
}
