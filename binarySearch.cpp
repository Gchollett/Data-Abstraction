#include <vector>
#include <iostream>
using namespace std;

bool binary_search(vector<int> v, int x){
    int high = v.size()-1;
    int low = 0;
    int mid;
    while(low <= high){
        mid = (high + low)/2;
        if(v[mid] == x) return true;
        if(x < v[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    int x;
    cin >> x;
    if(binary_search(v,x)){
        cout << "found it" << endl;
    } else {
        cout << "nah B" << endl;
    }
}