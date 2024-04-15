#include"Node.hpp"
#ifndef ONEFORWARD_NODE
#define ONEFORWARD_NODE

namespace structures
{
    template<class T>
    class OneForwardNode  : public Node<T> 
    {
        private:
            OneForwardNode<T>* next;
        public:
            OneForwardNode();
            OneForwardNode(const T &data): Node<T>(data) { next = nullptr;} 
            ~OneForwardNode() {};
            void SetNext(OneForwardNode<T>* next) { this->next = next; }
            OneForwardNode* GetNext() { return next; }

    };
}

#endif