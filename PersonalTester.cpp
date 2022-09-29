#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "ArrayList.h"
#include <iostream>
//#include "stuff.cpp"

using namespace std;

int main() {
    ArrayList<int> t;
    for(int i = 0; i<10; i++){
        t.push_back(i);
    }
    for(int i = 0; i<10; i++){
        cout << t[i] << endl;
    }
    for(int i = 0; i<10; i++){
        t.pop_back();
    }
    cout << "Array size: " << t.size() << endl;

    for(int i = 10; i>0; i--){
        t.push_back(i);
    }
    for(int i = 0; i<10; i++){
        cout << t[i] << endl;
    }
    for(int i = 0; i<10; i++){
        t.pop_back();
    }
    cout << "Array size: " << t.size() << endl;

    for(int i = 0; i<10; i++){
        t[i] = 9-i;
    }
    for(int i = 0; i<10; i++){
        cout << t[i] << endl;
    }
    // ArrayQueue<int> t;
    // for(int i = 0; i < 10; i++){
    //     t.enqueue(i);
    // }
    // ArrayStack<int> r;
    // for(int i = 9; i >= 0; i--){
    //     r.push(i);
    // }
    // while(!t.isEmpty()) {
	// 	if(r.pop()!=t.dequeue()){
    //         cout << "it failed you bitch" << endl;
    //         return 2;
    //     };
	// }




    // ArrayQueue<int> x;
    // if(!x.isEmpty()){
    //     cout << "Empty queue says it isn't" << endl;
    //     return 2;
    // }
    // for(int i = 0; i < 10; i++){
    //     x.enqueue(i);
    // }
    // ArrayQueue<int> y = x;
    // if(x.isEmpty()){
    //     cout << "Filled queue says it's empty" << endl;
    //     return 2;
    // }
    // if(x.Size() != 10){
    //     cout << "Queue has the wrong size" << endl;
    //     return 2;
    // }
    // if(y.Size() != 10){
    //     cout << "Copy queue has the wrong size" << endl;
    //     return 2;
    // }
    // if(x.peek() != 0){
    //     cout << "peeked the wrong value" << endl;
    //     return 2;
    // }  
    // int blonk = x.Size();
    // for(int i = 0; i < blonk/2; i++){
    //     if(y.dequeue() != i){
    //         cout << "Dequeing the wrong value (round 1)" << endl;
    //         return 2;
    //     }
    // }
    // for(int i = 0; i < blonk; i++){
    //     y.enqueue(i);
    // }
    // int tim [15] = {5,6,7,8,9,0,1,2,3,4,5,6,7,8,9};
    // for(int i = 0; i < blonk + blonk/2; i++){
    //     //cout << y.dequeue() << endl;
    //     if(y.dequeue() != tim[i]){
    //         cout << "Dequeing the wrong value (round 2)" << endl;
    //         return 2;
    //     }
    // }
    
    // if(x.isEmpty()){
    //     cout << "copy got dequeued" << endl;
    //     return 2;
    // }
    // cout << "passed" << endl;

    // ArrayStack<int> z;
    // cout <<"is z empty: " << z.isEmpty() << endl;
    // for(int i = 0; i < 10; i++){
    //     z.push(i);
    //     cout << "pushed " << i << endl;
    // }
    // ArrayStack<int> w = z;
    // cout <<"is z empty: " <<  z.isEmpty() << endl;
    // cout << "z size = " << z.Size() << endl;
    // cout << "w size = " << w.Size() << endl;
    // cout << "peeked: " << z.peek() << endl;  
    // int blank = z.Size();
    // for(int i = 0; i < blank/2; i++){cout << "popped: " << w.pop() << endl;}
    // for(int i = 0; i < blank; i++){
    //     w.push(i);
    //     cout << "pushed " << i << endl;
    // }
    // for(int i = 0; i < blank + blank/2; i++){cout << "popped: " << w.pop() << endl;}
    
    // cout <<"is z empty: " <<  z.isEmpty() << endl;

    
}