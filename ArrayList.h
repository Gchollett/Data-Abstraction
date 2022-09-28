template<typename T>
class ArrayList {
    private:
        T* data = nullptr;
        int capacity = 0;
        int sz = 0;
    public:
        ArrayList() {ReAlloc(100);}
        ArrayList(int i) {ReAlloc(i);}
        ArrayList(const ArrayList &other){
            data(other.data);
            capacity(other.capacity);
            size(other.size);
            for(int i = 0; i < sz; i++){
                data[i] = other.data[i];
            }
            
        }
        //ArrayList<T> &operator=(const Array<T> &al);
        ~ArrayList() {delete[] data;}
        void push_back(const T &t) {
            if(sz >= capacity) ReAlloc(capacity*2);
            data[sz] = t;
            sz++;
        };
        void pop_back() {--sz;}
        int size() const {return sz;}
        void clear() {sz = 0;}
        void insert(const T &t, int index){
            if(size >= capacity) ReAlloc(capacity*2);
            for(int i = index; i < sz; i++){
                data[i+1] = data[i];
            }
            data[index] = t;
        };
        const T &operator[](int index) const {return data[index];}
        T &operator[](int index) {return data[index];}
        void remove(int index){for(int i = index; i < sz; i++) data[i] = data[i+1];}

        class iterator {
            private:
                T* pointer;
            public:
                iterator(T *i) {pointer(i);};
                iterator() {pointer(nullptr);}
                iterator(const iterator &other){pointer(other.pointer);}
                T &operator*() const {return *pointer;}
                T* operator->() const {return pointer;}
                bool operator==(const iterator &other) const {return pointer == other.pointer;}
                bool operator!=(const iterator &other) const {return pointer != other.pointer;}
                iterator &operator=(const iterator &other){
                    pointer(other.pointer);
                    return *this;
                }
                iterator &operator++(){
                    this->pointer++;
                    return *this;
                }
                iterator &operator--(){
                    this->pointer--;
                    return *this;
                }
                iterator operator++(){
                    iterator temp = *this;
                    this-> pointer++;
                    return temp;
                }
                iterator operator--(){
                    iterator temp = *this;
                    this-> pointer--;
                    return temp;
                }
        };

        iterator begin() {return iterator(data);}
        const_iterator begin() const {return iterator(data);}
        iterator end() {return iterator(data + size);}
        const_iterator end() const {return iterator(data+size);}
        const_iterator cbegin() const {return iterator(data);}
        const_iterator cend() const {return iterator(data+size);}

    void ReAlloc(int newCapacity) {
                T* newBlock = new T[newCapacity];
                if(newCapacity < sz)
                    sz = newCapacity;

                for(int i = 0; i < sz; i++)
                    newBlock[i] = data[i];
                    
                delete[] data;
                data = newBlock;
                capacity = newCapacity;
    } 

};

