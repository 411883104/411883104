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
    Node(T v) : val(v), left(nullptr), right(nullptr) {}
    Node(T v, Node* l, Node* r) : val(v), left(l), right(r) {}
};

template <typename T>
class AVLTree
{
public:
    std::shared_ptr<Node<T>> root;

    AVLTree() = default;
    AVLTree(T v) : root(std::make_shared<Node<T>>(v)) {}

    int GetHeight(Node<T>* n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return n->h;
    }

    int GetBalance(Node<T>* n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return GetHeight(n.left) - GetHeight(n.right);
    }

    void left_rotate(Node<T>* n) {}
    void right_rotate(Node<T>* n) {}

    void insert(T val)
    {
        if (root == nullptr)
        {
            root = std::make_shared<Node<T>>(val);
        }
    }
};

int main() { auto tree = std::make_shared<AVLTree<std::string>>();
tr }