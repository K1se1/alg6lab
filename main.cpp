#include <iostream>
#include<vector>
#include "headers/Stack/Stack.hpp"
#include "headers/Queue/Queue.hpp"
int main(int, char**){
    structures::Stack<int> test_stack;
    test_stack.Push(14);
    test_stack.Push(10);
    test_stack.Push(15);
    std::cout << test_stack.Pop() << " " << test_stack.Pop() << "\n";
    test_stack.Push(30);
    std::cout << test_stack.Pop() << " " <<  test_stack.Pop() << "\n";
    structures::Queue<int> test_q;
    test_q.PushFront(13);
    test_q.PushFront(23);
    std::cout  << test_q.PopBack() << "\n";
    test_q.PushFront(30);
    std::cout << test_q.PopBack() << " " << test_q.PopBack();

}




/// Надо поправить столько хуйни, в том числе переделать cmake файлы, сделать там мб вложенную структуру
/// Да и вприниципе доделать лабу, а то нихуя кроме реализации Node не готово 