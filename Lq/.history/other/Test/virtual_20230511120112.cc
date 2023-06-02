#include <iostream>

using namespace std;

class Base
{
public:
    Base() = default;
    Base(int a);

    void print();

private:
    int count;
};

class Child : public Base
{
public:
    Child() = default;
    Child(int c);

private:
    int child;
};

Base::Base(int a) : count(a) {}

void Base::print() { cout << count << endl; }

Child::Child(int c) : child(c) {}

int main()
{
    Child c(1);
    Base *b = &c;
    b->print();
}