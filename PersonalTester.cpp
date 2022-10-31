#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include <list>
#include <iostream>
//#include "stuff.cpp"

using namespace std;

int main() {
    LinkedList<string> lst1;
    LinkedList<string> lst2;
    lst1.push_back("5");
	lst1.push_back("6");
	lst1.push_back("7");
	lst1.push_back("8");
	lst1.push_back("9");
	lst1[2] = "99";
	if(lst1[2]!="99") {
		cout << "[] error." << endl;
		return false;
	}
	lst2 = lst1;
	lst1.erase(lst1.begin()++++);
    for(int i = 0; i < 4; i++){
        cout << lst1[i] << endl;
    }
}