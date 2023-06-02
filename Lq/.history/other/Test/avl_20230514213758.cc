#include <iostream>
#include <memory>

template <typename T>
class Node
{
public:
    T val;
    int h{1};
    Node* left;
    Node* right;

    Node() = default;
    Node(T v) : val(v) {}
    Node(T v, Node* l, Node* r) : val(v), left(l), right(r) {}

    
};

template <typename T>
class AVLTree
{
public:
    std::shared_ptr<Node<T>> root;

    AVLTree() = default;
    AVLTree(T v) : root(std::make_shared<Node<T>>(v)) {}
};

int main() { auto tree = std::make_shared<AVLTree<std::string>>("root"); }