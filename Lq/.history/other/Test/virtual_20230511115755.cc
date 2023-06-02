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

Base::Base(int a) : count(a) {}

int main() {}