#include <iostream>
#include<string>
#include "Vector.cpp"

using namespace std;


template<typename T>
void PrintVector(const Vector<T>& vector){
    for(int i = 0; i < vector.Size(); i++)
        cout << vector[i] << endl; 
}

int main()
{

    Vector<string> v;
    v.PushBack("c++");
    v.PushBack("data abstraction");
    v.PushBack("example");
    v.PushBack("example");
    v.PushBack("example");
    v.PushBack("example");
    
    cout<< v.Size() << endl;
	cout<< v.Capacity() << endl;

    PrintVector(v);
    
    return 0;
    
}