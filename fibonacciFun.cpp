#include <iostream>
using namespace std;

int main() {
    int i = 2;
    int j = 1;
    int sum = 0;
    while(i < 4000000){
        if(i%2 == 0) sum += i;
        int temp = i;
        i += j;
        j = temp;
    }
    cout << sum << endl;
}