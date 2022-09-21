#include <vector>
#include <iostream>
using namespace std;

bool binary_search(vector<int> v, int x){
    bool isFound = false;
    bool isDone = false;
    int curr = v.size()/2;
    while(!isFound && !isDone){
        if(x == v[curr]) {
            isFound = true;
        }else{
            if(x < v[curr]){
                 if(curr != 0) curr /= 2;
                 else isDone = true;
            }
            else {
                if(curr != v.size()-1) curr += curr/2;
                else isDone = true;
            }
        }
    }
    return isFound;
}

int main() {
    vector<int> v = {1,2,3,4,5,7,9,10};
    int x;
    cin >> x;
    if(binary_search(v,x)){
        cout << "found it" << endl;
    } else {
        cout << "nah B" << endl;
    }
}