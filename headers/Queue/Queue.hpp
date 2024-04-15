#include "..\Stack\Stack.hpp"
#include<cstddef>
namespace structures
{

template<class T>
class Queue
{
    private:
        Stack<T>* input_stack;
        Stack<T>* output_stack;
        size_t size;
    public:
        Queue();
        Queue(const T&);
        ~Queue();
        void PushFront(const T&);
        T PopBack();
        size_t GetSize();
};
}

template<class T>
structures::Queue<T>::Queue(const T& data)
{
    input_stack = new Stack<T>(data);
    output_stack = new Stack<T>();
    size = 0;
}

template<class T>
structures::Queue<T>::Queue()
{
    input_stack = new Stack<T>();
    output_stack = new Stack<T>();
    size = 0;
}

template<class T>
structures::Queue<T>::~Queue()
{
    delete input_stack;
    delete output_stack;
}

template<class T>
void structures::Queue<T>::PushFront(const T& data)
{
    input_stack->Push(data);
    size++;
}

template<class T>
T structures::Queue<T>::PopBack()
{
    if(output_stack->IsEmpty())
    {
        while(!input_stack->IsEmpty())
        {
            output_stack->Push(input_stack->Pop());
        }
    }
    size--;
    return output_stack->Pop();
}


template<class T>
size_t structures::Queue<T>::GetSize()
{
    return size;
}