#include <iostream>

using namespace std;

class Base
{
public:
    Base() = default;
    Base(int a);

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

Child::Child(int c) : child(c) {}

int main() {}