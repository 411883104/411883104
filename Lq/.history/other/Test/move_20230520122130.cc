#include <iostream>
#include <vector>

class A
{
public:
    A() { std::cout << "A" << std::endl; }
};

std::vector<int> fun() { return {}; }

int main() { fun(); }