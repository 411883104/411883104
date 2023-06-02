#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
    A() = default;
    A(const A& a);
    A(const A&& a);
    void print();
};

A::A(const A& a) { cout << "copy" << endl; }
A::A(const A&& a) { cout << "move" << endl; }
void A::print() { cout << "ptr" << endl; }

int main()
{
    A a;
    A b = std::move(a);
    auto ptr = auto_ptr<A>();
}