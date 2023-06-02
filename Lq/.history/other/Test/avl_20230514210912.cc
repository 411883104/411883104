#include <iostream>

template <typename T>
class Node
{
public:
    T val;
    int h{0};
    Node* left;
    Node* right;

    Node() = default;
    Node(T v) : val(v) {}
    Node(T v, Node* l, Node* r) : val(v), left(l), right(r) {}

    int GetHeight()
    {
        if (n == nullptr)
        {
            return 0;
        }
        return h;
    }

    int GetBalance() {}
};

int main() {}