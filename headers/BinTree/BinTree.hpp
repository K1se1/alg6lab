#pragma once 
#include "..\Nodes\TwoForwardNode.hpp"
#include<vector>
namespace structures
{



template<class T>
class BinTree
{
    private:
        TwoForwardNode<T> *root;
        void PreOrderData(TwoForwardNode<T>* root, std::vector<T>& result); // Это либо хитрость, либо глупость, хочу так реализовать рекурсию внутри класса
    public:
        BinTree();
        BinTree(const T& data);
        void Insert(const T& data);
        bool FindData(const T& data) const;
        std::vector<T> PreOrderData();
};

template<class T>
BinTree<T>::BinTree(): root(nullptr) {}


template<class T>
BinTree<T>::BinTree(const T& data)
{
    root = new TwoForwardNode<T>(data);
}

template<class T>
void BinTree<T>::Insert(const T& data)
{
    if(root == nullptr){ root = new TwoForwardNode<T>(data); return;} 
    TwoForwardNode<T> *temp = root;
    while(true) // по дереву пока не найдем null лист
    {
        if(data >= root->GetData())
        {
            if(!root->GetNext()){ root->SetNext(new TwoForwardNode<T>(data)); root = temp; return; }
            root = root->GetNext();
        }
        else
        {
            if(!root->GetPrevious()){ root->SetPrevious(new TwoForwardNode<T>(data)); root = temp; return;}
            root = root->GetPrevious();
        }
    }
}

template<class T>
bool BinTree<T>::FindData(const T& data) const
{
    TwoForwardNode<T>* temp = root;
    while(temp != nullptr) // Ищем пока не дойдем до null листа
    {
        if(temp->GetData() == data) return true; // если нашли, возвращаем true
        else if(temp->GetData() > data) temp = temp->GetPrevious(); // Если больше, берем левый лист
        else temp = temp->GetNext(); // Иначе берем правый
    }
    return false; // Если наткнулись на null лист - возвращаем false
}

template<class T>
void BinTree<T>::PreOrderData(TwoForwardNode<T>* root, std::vector<T> &result)
{
    if(root == nullptr)
        return;
    result.push_back(root->GetData());
    PreOrderData(root->GetNext(), result);
    PreOrderData(root->GetPrevious(), result);
}

template<class T>
std::vector<T> BinTree<T>::PreOrderData()
{
    if(root == nullptr)
        throw std::logic_error("BinTree is empty!!!!");
    std::vector<T> result(1, root->GetData());
    PreOrderData(root->GetNext(), result);
    PreOrderData(root->GetPrevious(), result);
    return result;

}


}