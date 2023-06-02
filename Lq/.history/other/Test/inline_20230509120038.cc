#include <iostream>

class A
{
public:
    virtual inline void print();
};

class B
{
public:
    virtual inline void print();
};

void A::print() { std::cout << 'A' << std::endl; }
void B::print() { std::cout << 'B' << std::endl; }

int main()
{
    A a;
    a.print();
}