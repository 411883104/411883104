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

    int GetHeight(Node* n)
    {
        if (n == nullptr)
        {
            return 0;
        }
        return n->h;
    }

    int GetBalance() { return GetHeight(left) - GetHeight(right); }
};

template <typename T>
class AVLTree
{
public:
    std::shared_ptr<Node<T>> root;
};

int main() { auto tree = std::make_shared<Node<std::string>>("head"); }