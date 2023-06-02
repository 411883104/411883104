#include <iostream>
using namespace std;

class A
{
public:
    A() = default;
    A(A& a);
};

A::A(A& a) { cout << "copy" << endl; }

int main() { A a; }