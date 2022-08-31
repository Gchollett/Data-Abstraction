#include <iostream>
using namespace std;

int main() {
    long int j = 0;
    for(int i = 0; i < 1000000; i++){
        if(i%5==0 || i%7 == 0) j += i;
    }
    cout << j << "\n";
    return 0;
}