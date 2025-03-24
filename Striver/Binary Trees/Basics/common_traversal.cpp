#include <iostream>
#include <memory>

template <typename T>
class BinaryTree
{
public:
    std::shared_ptr<BinaryTree<T>> left;
    std::shared_ptr<BinaryTree<T>> right;
    T data;

    BinaryTree(T data) : data(data), left(nullptr), right(nullptr) {}

    void preOrder(std::shared_ptr<BinaryTree<T>> head) const
    {
        if (head == nullptr)
            return;
        std::cout << head->data << " ";
        preOrder(head->left);
        preOrder(head->right);
    }

    void inOrder(std::shared_ptr<BinaryTree<T>> head) const
    {
        if (head == nullptr)
            return;
        inOrder(head->left);
        std::cout << head->data << " ";
        inOrder(head->right);
    }

    void postOrderTraversal(std::shared_ptr<BinaryTree<T>> head) const
    {
        if (head == nullptr)
            return;
        postOrderTraversal(head->left);
        postOrderTraversal(head->right);
        std::cout << head->data << " ";
    }
};

int main()
{
    auto head = std::make_shared<BinaryTree<int>>(4);
    
    // Build left subtree
    head->left = std::make_shared<BinaryTree<int>>(5);
    head->left->left = std::make_shared<BinaryTree<int>>(3);
    head->left->left->right = std::make_shared<BinaryTree<int>>(4);
    
    // Build right subtree
    head->right = std::make_shared<BinaryTree<int>>(7); // Added this line
    head->right->right = std::make_shared<BinaryTree<int>>(2);
    head->right->left = std::make_shared<BinaryTree<int>>(8);
    head->right->left->right = std::make_shared<BinaryTree<int>>(9);
    
    // Print headers for clarity
    std::cout << "Pre-order traversal: ";
    head->preOrder(head);
    std::cout << std::endl;
    
    std::cout << "In-order traversal: ";
    head->inOrder(head);
    std::cout << std::endl;
    
    std::cout << "Post-order traversal: ";
    head->postOrderTraversal(head);
    std::cout << std::endl;
    
    return 0;
}