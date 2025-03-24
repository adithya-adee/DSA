#include <iostream>
#include <memory>
#include <queue>
#include <vector>

template <typename T>
class BinaryTree {
public:
    std::shared_ptr<BinaryTree<T>> left;
    std::shared_ptr<BinaryTree<T>> right;
    T data;

    BinaryTree(T data)
        : data(data), left(nullptr), right(nullptr) {}

    void levelOrderTraversal(const std::shared_ptr<BinaryTree<T>>& root) const {
        if (!root) {
            std::cout << "The tree is empty." << std::endl;
            return;
        }

        std::queue<std::shared_ptr<BinaryTree<T>>> nodesQueue;
        nodesQueue.push(root);

        std::vector<std::vector<T>> levels;

        // Process nodes level by level
        while (!nodesQueue.empty()) {
            size_t levelSize = nodesQueue.size();
            std::vector<T> currentLevel;
            
            for (size_t i = 0; i < levelSize; ++i) {
                std::shared_ptr<BinaryTree<T>> currentNode = nodesQueue.front();
                nodesQueue.pop();

                currentLevel.push_back(currentNode->data);

                if (currentNode->left) {
                    nodesQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    nodesQueue.push(currentNode->right);
                }
            }
            levels.push_back(currentLevel);
        }

        for (size_t i = 0; i < levels.size(); ++i) {
            std::cout << "Level " << i << ": ";
            for (const auto &value : levels[i]) {
                std::cout << value << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create the root node using a shared_ptr
    auto root = std::make_shared<BinaryTree<int>>(4);

    // Build the left subtree
    root->left = std::make_shared<BinaryTree<int>>(5);
    root->left->left = std::make_shared<BinaryTree<int>>(3);
    root->left->left->right = std::make_shared<BinaryTree<int>>(4);

    // Build the right subtree
    root->right = std::make_shared<BinaryTree<int>>(7);
    root->right->left = std::make_shared<BinaryTree<int>>(8);
    root->right->left->right = std::make_shared<BinaryTree<int>>(9);
    root->right->right = std::make_shared<BinaryTree<int>>(2);

    std::cout << "Level order traversal:" << std::endl;
    root->levelOrderTraversal(root);

    return 0;
}
