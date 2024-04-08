#include <iostream>
#include "headers/nodes/OneForwardNode.h"
int main(int, char**){
    std::cout << "Hello, from lab06!\n";
    structures::OneForwardNode<int> firstNode(5);
    std::cout << firstNode.GetData();
    firstNode.SetNext(new structures::OneForwardNode<int>(100));
    std::cout << firstNode.GetNext()->GetData();
}




/// Надо поправить столько хуйни, в том числе переделать cmake файлы, сделать там мб вложенную структуру
/// Да и вприниципе доделать лабу, а то нихуя кроме реализации Node не готово 