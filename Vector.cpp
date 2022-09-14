template<typename T>

class Vector {
    private:
    int size;
    int capacity;
    T* data;

    public:
    Vector(){
        ReAlloc(2);
    }

    void ReAlloc(int newCapacity){
        T* newBlock = new T[newCapacity];
        if(newCapacity < size)
            size = newCapacity;
        
        for(int i = 0; i<size; i++)
            newBlock[i] = data[i];
        
        delete[] data;
        data = newBlock;
        capacity = newCapacity;
    }

    void PushBack(const T& input){
        if(size >= capacity) {
            ReAlloc(capacity*2);
        }
        data[size] = input;
        size ++;
    }

    int Size() const {return size;}
    int Capacity() const {return capacity;}
};