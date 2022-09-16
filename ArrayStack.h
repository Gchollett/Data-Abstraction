#include "Stack.h"
#include <iostream>
using namespace std;

template<typename T>
class ArrayStack: public Stack<T> {
    private:
        T* data = nullptr;
        int size = 0;
        int capacity = 0;
    public:
        ArrayStack() {ReAlloc(5);}
        ArrayStack(const ArrayStack &object){
            data = new T[object.capacity];
            capacity = object.capacity;
            size = object.size;
            for(int i = 0; i < size; i++){
                data[i] = object.data[i];
            }
        }
        ~ArrayStack() {delete[] data;}

        void push(const T &t) {
            if(size >= capacity){
                ReAlloc(capacity * 2);
            };
            data[size] = t;
            size ++;
            //cout << "size " << size << endl;
        }
        T pop() {
            T ret = data[size-1];
            size--;
            return ret;
        }
        T peek() const {return data[size-1];}
        bool isEmpty() const {return size == 0;}

        void ReAlloc(int newCapacity) {
            T* newBlock = new T[newCapacity];
            if(newCapacity < size)
                size = newCapacity;

            for(int i = 0; i < size; i++)
                newBlock[i] = data[i];
                
            delete[] data;
            data = newBlock;
            capacity = newCapacity;
        }

        int Size() const {return size;}
};

