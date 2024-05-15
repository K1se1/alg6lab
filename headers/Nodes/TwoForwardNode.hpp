#include"Node.hpp"


namespace structures
{
    template<class T>
    class TwoForwardNode: public Node<T>
    {
        private:
            TwoForwardNode<T>* previous;
            TwoForwardNode<T>* next;
        public:
            TwoForwardNode(const T &data): Node<T>(data) {previous = nullptr; next = nullptr;}
            void SetPrevious(TwoForwardNode<T>* previous) { this->previous = previous; }
            TwoForwardNode* GetPrevious() { return previous; }
            TwoForwardNode* GetNext() { return next; }
            void SetNext(TwoForwardNode<T>* next) { this->next = next; }

    };
}