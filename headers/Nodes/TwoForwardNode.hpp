#include"OneForwardNode.hpp"


namespace structures
{
    template<class T>
    class TwoForwardNode: public OneForwardNode<T>
    {
        private:
            TwoForwardNode* previous;
        public:
            TwoForwardNode(const T &data): OneForwardNode(data) {}
            void SetPrevious(TwoForwardNode<T>* previous) { this->previous(previous) };
            TwoForwardNode* GetPrevious() { return previous; }

    };
}