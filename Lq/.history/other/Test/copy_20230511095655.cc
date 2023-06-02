#include <iostream>
using namespace std;

class A
{
public:
    A() = default;
    A(const A& a);
    A(A&& a);
};

A::A(const A& a) { cout << "copy" << endl; }
A::A(A&& a) { cout << "move" << endl; }

int main()
{
    A a;
    A b = std::move(a);
}