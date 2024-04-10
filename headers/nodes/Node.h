#ifndef NODE_H
#define NODE_H

namespace structures
{
    template<class T>
    class Node
    {
        private:
        T* data;
        public:
        Node(const T& data){this->data = new T;
                            *(this->data) = data;};
        virtual ~Node() {delete data;};
        virtual void SetData(const T& data) {*(this->data) = data;}
        virtual T GetData() {return *data; };
    };
}

#endif