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


int main()
{
    A a;
    A b = a;
}