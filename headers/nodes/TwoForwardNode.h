#include"OneForwardNode.h"


namespace structures
{
    template<class T>
    class TwoForwardNode: public OneForwardNode<T>
    {
        private:
            TwoForwardNode* previous;
        public:
            TwoForwardNode(const T &data): this.data(data), next(nullptr), previous(nullptr) {}
            void SetPrevious(TwoForwardNode<T>* previous): this->previous(previous) {};
            TwoForwardNode* GetPrevious() { return previous; }

    };
}