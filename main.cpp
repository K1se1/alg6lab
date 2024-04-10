#include <iostream>
#include "headers/stack/stack.h"
int main(int, char**){
    structures::Stack<int> test_stack(5);
    test_stack.Push(14);
    test_stack.Push(10);
    test_stack.Push(15);
    std::cout << test_stack.Pop() << " " << test_stack.Pop() << " " << test_stack.Pop() << test_stack.Pop();
}




/// Надо поправить столько хуйни, в том числе переделать cmake файлы, сделать там мб вложенную структуру
/// Да и вприниципе доделать лабу, а то нихуя кроме реализации Node не готово 