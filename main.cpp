#include <iostream>
#include<vector>
#include "headers/Stack/Stack.hpp"
#include "headers/Queue/Queue.hpp"
#include "headers/BinTree/BinTree.hpp"

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
    std::cout << test_q.PopBack() << " " << test_q.PopBack() << "\n";
    ///
    structures::BinTree<int> test_tree;
    test_tree.Insert(1);
    test_tree.Insert(2);
    test_tree.Insert(0);
    std::vector<int> arr(test_tree.PreOrderData());
    for(int i: arr)
    {
        std::cout << i << " ";
    }

}

