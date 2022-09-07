#include <iostream>
using namespace std;

template<typename T>

void mySwap(T &x, T &y){
    T z = x;
    x = y;
    y = z;
}

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << a << ", " << b << endl;
    mySwap(a,b);
    cout << a << ", " << b << endl;
}