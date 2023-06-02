#include <iostream>

class A
{
public:
    virtual inline void print();
};

void A::print() { std::cout << 'A' << std::endl; }

int main()
{
    A a;
    a.print();
}