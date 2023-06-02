#include <iostream>
#include <vector>

class A
{
public:
    A() { std::cout << "A" << std::endl; }
};

std::vector<A> fun() { return {}; }

int main() { fun(); }