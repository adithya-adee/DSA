#ifndef BINARY_TREE_HP
#define BINARY_TREE_HPP

#include <iostream>
#include <queue>

template <typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree *left;
    BinaryTree *right;

    explicit BinaryTree(T data) : data{data}, left{nullptr}, right{nullptr} {}

    ~BinaryTree()
    {
        delete left;
        delete right;
    }

    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;
    void levelOrderTraversal() const;
};

template <typename T>
void BinaryTree<T>::preOrderTraversal() const
{
    std::cout << data << " ";
    if (left)
        left->preOrderTraversal();
    if (right)
        right->preOrderTraversal();
}

template <typename T>
void BinaryTree<T>::inOrderTraversal() const
{
    if (left)
        left->inOrderTraversal();
    std::cout << data << " ";
    if (right)
        right->inOrderTraversal();
}

template <typename T>
void BinaryTree<T>::postOrderTraversal() const
{
    if (left)
        left->postOrderTraversal();
    if (right)
        right->postOrderTraversal();
    std::cout << data << " ";
}

template <typename T>
void BinaryTree<T>::levelOrderTraversal() const
{
    std::queue<const BinaryTree<T> *> nodesQueue;
    nodesQueue.push(this);
    while (!nodesQueue.empty())
    {
        auto current = nodesQueue.front();
        nodesQueue.pop();
        std::cout << current->data << " ";
        if (current->left)
            nodesQueue.push(current->left);
        if (current->right)
            nodesQueue.push(current->right);
    }
}

#endif