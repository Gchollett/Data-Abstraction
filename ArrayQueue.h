#include "Queue.h"

template<typename T>
class ArrayQueue: public Queue<T>{
    private:
        T* data = nullptr;
        int size = 0;
        int capacity = 0;
        int head = 0;
    public:
        ArrayQueue() {ReAlloc(5);}
        ArrayQueue(const ArrayQueue &object){
            data = new T[object.capacity];
            capacity = object.capacity;
            size = object.size;
            head = object.head;
            for(int i = 0; i < size; i++){
                data[i] = object.data[i];
            }
        }
        ~ArrayQueue() {delete[] data;}
        
        void enqueue(const T &t) {
            if(size >= capacity){
                ReAlloc(capacity * 2);
            }
            if(head >= capacity) head = 0;
            if(head > 0) data[(size + head)%capacity] = t;
            else data[size] = t;
            size++;
        }
        T dequeue() {
            if(size != 0){
                T ret = data[head];
                head = (head + 1) % capacity;
                size--;
                return ret;
            } else {
                cout << "Queue Underflow" << endl;
                return 0;
            }
        }
        T peek() const {return data[head];}
        bool isEmpty() const {return size == 0;}

        void ReAlloc(int newCapacity) {
            T* newBlock = new T[newCapacity];
            if(newCapacity < size)
                size = newCapacity;
            
            if(head == 0){
                for(int i = 0; i < size; i++)
                    newBlock[i] = data[i];
            }
            else {
                for(int i = 0; i < size; i++)
                    newBlock[i] = data[(i+head)%size];
            }
            delete[] data;
            data = newBlock;
            capacity = newCapacity;
            head = 0;
        }

        int Size() const {return size;}
};