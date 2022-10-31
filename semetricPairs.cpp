#include <iostream>
#include <unordered_map>
using namespace std;

void findSymPairs(int arr[][2], int row)
{
   unordered_map<int,int> check;
   for(int i = 0; i < row; i++){
        if(check.find(arr[i][1]) != check.end()) cout << "(" << arr[i][0] << "," << arr[i][1] << ")" << endl;
        else check[arr[i][0]] = *arr[i][1];
   }
}
 
// Driver method
int main()
{
    int arr[5][2];
    arr[0][0] = 11;
    arr[0][1] = 20;
    arr[1][0] = 30;
    arr[1][1] = 40;
    arr[2][0] = 5;
    arr[2][1] = 10;
    arr[3][0] = 40;
    arr[3][1] = 30;
    arr[4][0] = 10;
    arr[4][1] = 5;
    cout << "Following pairs have symmetric pairs\n";
    findSymPairs(arr, 5);
    //[[11,20],[30,40].[5,10],[40.30],[10,5]]
}