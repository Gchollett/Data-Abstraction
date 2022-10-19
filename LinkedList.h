template<typename T>
class LinkedList{
    struct Node{
        T data;
        Node *next;
        Node *prev;
        Node() : next(nullptr), prev(nullptr) {}
        Node(T t, Node *n, Node *p) : data(t),next(n),prev(p) {}
    };

    private:
        Node *sentinal = new Node;
        unsigned int sz = 0;

    public:
        LinkedList() {
            sentinal->next = sentinal;
            sentinal->prev = sentinal;
        }
        LinkedList(const LinkedList & l) {
            sentinal->next = sentinal;
            sentinal->prev = sentinal;
            for(iterator it = l.begin(); it != l.end(); it++){
                push_back(*it);
            }
        }
        ~LinkedList() {
            clear();
            delete sentinal;
        }

        LinkedList &operator=(const LinkedList &l){
            sentinal->next = sentinal;
            sentinal->prev = sentinal;
            for(iterator it = l.begin(); it != l.end(); it++){
                push_back(*it);
            }
            return *this;
        }
        class iterator{
            private:
                Node* ptr;
            public:
                iterator() : ptr(nullptr) {}
                iterator(Node *p) : ptr(p) {}
                iterator(const iterator &src) : ptr(src.ptr) {}
                T &operator*() {return ptr->data;}
                bool operator==(const iterator &it) {return ptr == it.ptr;}
                bool operator!=(const iterator &it) {return ptr != it.ptr;}
                iterator &operator=(const iterator &src) {
                    ptr = src.ptr;
                    return *this;
                }
                iterator &operator++(){
                    ptr = ptr->next;
                    return *this;
                }
                iterator &operator--(){
                    ptr = ptr->prev;
                    return *this;
                }
                iterator operator++(int){
                    iterator it = *this;
                    ptr=ptr->next;
                    return it;
                }
                iterator operator--(int){
                    iterator it = *this;
                    ptr=ptr->prev;
                    return it;
                }
                friend class LinkedList;
        };
        typedef iterator const_iterator;
        void push_back(const T &t) {
            Node *n = new Node;
            n->data = t;
            n->next = sentinal;
            sentinal->prev->next = n;
            n->prev = sentinal->prev;
            sentinal->prev = n;
            sz++;
        }
        void pop_back(){
            sentinal->prev = sentinal->prev->prev;
            sentinal->prev->next = sentinal;
            sz--;
        }
        int size() const {return sz;}

        void clear() {
            while (sentinal->next != sentinal){
                Node * temp = sentinal->next;
                sentinal->next = sentinal->next->next;
                delete temp;
            }
            sentinal->next = sentinal->prev = sentinal;
            sz = 0;
        }
        iterator insert(iterator pos,const T &t){
            Node *n = new Node(t,pos.ptr,pos.ptr->prev);
            pos.ptr->prev->next = n;
            pos.ptr->prev = n;
            sz++;
            pos.ptr = n;
            return pos;
        }
        const T &operator[](int index) const {
            if(index < sz/2){
                iterator i = begin();
                int cnt = 0;
                while(cnt < index){
                    i++;
                    cnt++;
                }
                return *i;
            } else {
                iterator i = end();
                int cnt = sz-1;
                while(cnt > index){
                    i--;
                    cnt--;
                }
                return *i;
            }
        }
        T &operator[](int index) {
           if(index < sz/2){
                iterator i = begin();
                int cnt = 0;
                while(cnt < index){
                    i++;
                    cnt++;
                }
                return *i;
            } else {
                iterator i = --end();
                int cnt = sz-1;
                while(cnt > index){
                    i--;
                    cnt--;
                }
                return *i;
            }
        }
        iterator erase(iterator pos){
            if (pos == sentinal) return ++pos;
            if (pos == --end()){
                pop_back();
            } else {
                pos.ptr->next->prev = pos.ptr->prev;
                pos.ptr->prev->next = pos.ptr->next;
                --sz;
            }
            return ++pos;
        }
        iterator begin() {return iterator(sentinal->next);}
        iterator end() {return iterator(sentinal);}
        const_iterator begin() const {return const_iterator(sentinal->next);}
        const_iterator end() const {return const_iterator(sentinal);}
        const_iterator cbegin() const {return const_iterator(sentinal->next);}
        const_iterator cend() const {return const_iterator(sentinal);}
};