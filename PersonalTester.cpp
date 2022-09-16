#include "ArrayStack.h"
#include "ArrayQueue.h"
#include <iostream>
//#include "stuff.cpp"

using namespace std;

int main() {
    ArrayQueue<int> x;
    cout << "is x empty: " << x.isEmpty() << endl;
    for(int i = 0; i < 10; i++){
        x.enqueue(i);
        cout << "enqueued " << i << endl;
    }
    ArrayQueue<int> y = x;
    cout << "is x empty: " << x.isEmpty() << endl;
    cout << "x size = " << x.Size() << endl;
    cout << "y size = " << y.Size() << endl;
    cout << "peeked: " << x.peek() << endl;  
    int blonk = x.Size();
    for(int i = 0; i < blonk/2; i++){cout << "dequeued: " << y.dequeue() << endl;}
    for(int i = 0; i < blonk; i++){
        y.enqueue(i);
        cout << "enqueued " << i << endl;
    }
    for(int i = 0; i < blonk + blonk/2; i++){cout << "dequeued: " << y.dequeue() << endl;}
    
    cout << "is x empty: " << x.isEmpty() << endl;


    ArrayStack<int> z;
    cout <<"is z empty: " << z.isEmpty() << endl;
    for(int i = 0; i < 10; i++){
        z.push(i);
        cout << "pushed " << i << endl;
    }
    ArrayStack<int> w = z;
    cout <<"is z empty: " <<  z.isEmpty() << endl;
    cout << "z size = " << z.Size() << endl;
    cout << "w size = " << w.Size() << endl;
    cout << "peeked: " << z.peek() << endl;  
    int blank = z.Size();
    for(int i = 0; i < blank/2; i++){cout << "popped: " << w.pop() << endl;}
    for(int i = 0; i < blank; i++){
        w.push(i);
        cout << "pushed " << i << endl;
    }
    for(int i = 0; i < blank + blank/2; i++){cout << "popped: " << w.pop() << endl;}
    
    cout <<"is z empty: " <<  z.isEmpty() << endl;

    
}