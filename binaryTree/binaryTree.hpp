#pragma once


template <typename T>
struct binaryTreeNode
{
    T _data;
    binaryTreeNode<T> * _left;
    binaryTreeNode<T> * _right;

    binaryTreeNode(const T& data)
        :_data(data)
         ,_left(NULL)
         ,_right(NULL)
    {}
};


template <typename T>
class binaryTree
{
    typedef binaryTreeNode<T> Node;
public:
    binaryTree()
        :_root(NULL)
    {}


private:
    Node* _root;

}



