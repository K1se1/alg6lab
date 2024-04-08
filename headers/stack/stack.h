#include "..\nodes\OneForwardNode.h"
namespace structures
{



template<class T>
class Stack
{
    private:
        Node<T> Top;
    public:
        Stack();
        ~Stack();
        void Push(T&); // помещаем элемент в начало
        T Pop(); // удаляем и возвращаем элемент из конца
};

}