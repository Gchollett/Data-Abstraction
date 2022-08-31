#include <iostream>
using namespace std;

/*void swap(int *x, int *y){ // pass by pointer
    int z = *x;
    *x = *y;
    *y = z;
}*/

void swap(int &x, int &y){ // pass by reference
    int z = x;
    x = y;
    y = z;
}

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << a << ", " << b << endl;
    swap(a,b);
    cout << a << ", " << b << endl;
}