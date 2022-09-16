template<typename T>
class Vector
{
    private:
        T* data = nullptr;
        int size = 0;
        int capacity = 0;
        
    public:
        Vector()
        {
            // allocate inital elements
            ReAlloc(2);
        };
        
        void ReAlloc(int newCapacity) {
            // allocate a new block of memory
            // copy/move old elements into new block
            // release old memory space
            T* newBlock = new T[newCapacity];
            
            
            // check if the capacity is smaller than size
            if(newCapacity < size)
                size = newCapacity;
            
            for(int i = 0; i < size; i++)
                newBlock[i] = data[i];
                
            delete[] data;
            data = newBlock;
            capacity = newCapacity;
        };
        
        void PushBack(const T& value) 
        {
            if(size >= capacity) {
                ReAlloc(capacity + capacity/2);
            }
            
            data[size] = value;
            size++;
        };
        
        const T& operator[](int index) const {
            return data[index];
        };
        
        int Size() const { return size; };
		int Capacity() const {return capacity; };
        

};