#ifndef NODE_H
#define NODE_h

namespace structures
{
    template<class T>
    class Node
    {
        private:
        T data;
        public:
        Node(const T& data){this->data = data;};
        virtual ~Node() {} ;
        virtual T GetData() {return data; };
    };
}

#endif