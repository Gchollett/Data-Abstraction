#include <iostream>
#include "add.cpp"
using namespace std;

int main() {
    int a;
    int b;
    cin >> a;
    cin >> b;
    cout << "The sum of " << a << " and " << b << " is " << add(a,b) << "\n";
    return 0;
}