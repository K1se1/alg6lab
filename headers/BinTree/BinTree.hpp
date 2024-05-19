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
        void PreOrderData(TwoForwardNode<T>* root, std::vector<T>& result);
        void PostOrderData(TwoForwardNode<T>* root, std::vector<T>& result);
        void InOrderData(TwoForwardNode<T>* root, std::vector<T>& result);
        void ReverseInOrderData(TwoForwardNode<T>* root, std::vector<T>& result);

    public:
        BinTree();
        BinTree(const T& data);
        void Insert(const T& data);
        bool FindData(const T& data) const;
        std::vector<T> PreOrderData();
        std::vector<T> PostOrderData();
        std::vector<T> InOrderData();
        std::vector<T> ReverseInOrderData();
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
    PreOrderData(root->GetPrevious(), result);
    PreOrderData(root->GetNext(), result);
}

template<class T>
std::vector<T> BinTree<T>::PreOrderData()
{
    if(root == nullptr)
        throw std::logic_error("BinTree is empty!!!!");

    std::vector<T> result(1, root->GetData());
    PreOrderData(root->GetPrevious(), result);
    PreOrderData(root->GetNext(), result);

    return result;

}


template<class T>
void BinTree<T>::InOrderData(TwoForwardNode<T>* root, std::vector<T> &result)
{
    if(root == nullptr)
        return;
    InOrderData(root->GetPrevious(), result);
    result.push_back(root->GetData());
    InOrderData(root->GetNext(), result);
}

template<class T>
std::vector<T> BinTree<T>::InOrderData()
{
    if(root == nullptr)
        throw std::logic_error("BinTree is empty!!!!");
    std::vector<T> result;
    InOrderData(root->GetPrevious(), result);
    result.push_back(root->GetData());
    InOrderData(root->GetNext(), result);
    return result;
}


template<class T>
void BinTree<T>::PostOrderData(TwoForwardNode<T>* root, std::vector<T> &result)
{
    if(root == nullptr)
        return;
    PostOrderData(root->GetPrevious(), result);
    PostOrderData(root->GetNext(), result);
    result.push_back(root->GetData());

}


template<class T>
std::vector<T> BinTree<T>::PostOrderData()
{
    if(root == nullptr)
        throw std::logic_error("BinTree is empty!!!!");
    std::vector<T> result;
    PostOrderData(root->GetPrevious(), result);
    PostOrderData(root->GetNext(), result);   
    result.push_back(root->GetData());
    return result;
}   


template<class T>
void BinTree<T>::ReverseInOrderData(TwoForwardNode<T>* root, std::vector<T> &result)
{
    if(root == nullptr)
        return;
    ReverseInOrderData(root->GetNext(), result);
    result.push_back(root->GetData());
    ReverseInOrderData(root->GetPrevious(), result);
}


template<class T>
std::vector<T> BinTree<T>::ReverseInOrderData()
{
    std::vector<T> result;
    if(root == nullptr)
        throw std::logic_error("BinTree is empty!!!!");
    ReverseInOrderData(root->GetNext(), result);
    result.push_back(root->GetData());
    ReverseInOrderData(root->GetPrevious(), result);   
    return result;
}
}