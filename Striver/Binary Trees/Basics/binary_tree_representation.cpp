#include<iostream>
#include <memory>

template <typename T>
class BinaryTree{
  public:
    std::shared_ptr<BinaryTree<T>> left;
    std::shared_ptr<BinaryTree<T>> right;
    T data;

    BinaryTree(T data): data(data),left(nullptr),right(nullptr){}
    
    void preOrder(std::shared_ptr<BinaryTree<T>> head) const {
      if(head == NULL) return; 
      preOrder(head->left);
      std::cout << head->data << " ";
      preOrder(head->right);
      std::cout << std::endl;
  }
};

int main()
{
  BinaryTree<int> head(4);
  head.left = std::make_shared<BinaryTree<int>>(2);
  head.right = std::make_shared<BinaryTree<int>>(5);
  head.left->left = std::make_shared<BinaryTree<int>>(1);
  head.left->right = std::make_shared<BinaryTree<int>>(3);
  head.right->right = std::make_shared<BinaryTree<int>>(6);
  head.preOrder(std::make_shared<BinaryTree<int>>(head));
  return 0;
}
