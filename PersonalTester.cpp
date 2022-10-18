#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include <list>
#include <iostream>
//#include "stuff.cpp"

using namespace std;

int main() {
    LinkedList<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    for(auto i:lst) cout << i << endl;
}