#include <iostream>
#include<vector>
#include<random>

#include "headers/BinTree/BinTree.hpp"

int main(int, char**){

    structures::BinTree<int> test_tree;
    for(int i =0; i < 20; ++i)
    {
        test_tree.Insert(rand() % 100);
    }
    std::vector<int> pre(test_tree.PreOrderData());
    std::vector<int> post(test_tree.PostOrderData());
    std::vector<int> in(test_tree.InOrderData());
    std::vector<int> rev_in(test_tree.ReverseInOrderData());
    std::cout << "PreOrder: ";
    for(int i: pre)
    {
        std::cout << i << " ";
    }
    std::cout << "\nPostOrder: ";
    for(int i: post)
    {
        std::cout << i << " ";
    }
    std::cout << "\nInOrder: ";
    for(int i: in)
    {
        std::cout << i << " ";
    }
    std::cout << "\nReverseInOrder: ";
    for(int i: rev_in)
    {
        std::cout << i << " ";
    }

}

