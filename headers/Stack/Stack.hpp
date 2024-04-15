#pragma once 
#include "..\Nodes\OneForwardNode.hpp"
namespace structures
{

template<class T>
class Stack
{
    private:
        OneForwardNode<T>* Top;
    public:
        Stack(const T&);
        Stack();
        ~Stack();
        void Push(const T&); // помещаем элемент в начало
        T Pop(); // удаляем и возвращаем элемент из конца
        bool IsEmpty(); // пуст ли стэк
};


}


template<class T>
structures::Stack<T>::Stack(): Top(nullptr) {}


template<class T>
structures::Stack<T>::Stack(const T& data)
{
    Top = new OneForwardNode<T>(data);
}


template<class T>
structures::Stack<T>::~Stack()
{
    OneForwardNode<T>* next;
    while(Top != nullptr)
    {
        next = Top->GetNext();
        delete Top;
        Top = next;
    }
}

template<class T>
void structures::Stack<T>::Push(const T& data)
{
    OneForwardNode<T>* new_Top = new OneForwardNode<T>(data);
    new_Top->SetNext(Top);
    Top = new_Top;
    return;
}


template<class T>
T structures::Stack<T>::Pop()
{
    if(Top == nullptr)
        throw std::out_of_range("Stack is empty!!!");
    OneForwardNode<T>* next;
    T data;
    data = Top->GetData();
    next = Top->GetNext();
    delete Top;
    Top = next;
    return data;
    
}


template<class T>
bool structures::Stack<T>::IsEmpty(){ return !Top; }