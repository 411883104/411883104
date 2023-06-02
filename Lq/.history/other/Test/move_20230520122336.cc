#include <iostream>
#include <vector>

class A
{
public:
    A() { std::cout << "A" << std::endl; }
};

std::vector<A> fun()
{
    std::vector<A> res(2);
    return res;
}

int main() { fun(); }