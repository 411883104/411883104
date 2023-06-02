#include <iostream>

template <typename T>
class Node
{
public:
    T val;
    Node* left;
    Node* right;
    Node() = default;
    Node(T v) : val(v) {}
    Node(T v, Node* l, Node* r) : val(v), left(l), right(r) {}
};

int main() {}