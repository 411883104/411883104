/*
 * @Author       : Outsider
 * @Date         : 2023-03-19 17:23:30
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-22 11:46:21
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\setss.cc
 */
#include <iostream>
#include <set>
using namespace std;

class A
{
public:
    int a;
};

class Task
{
public:
    A* a;
    int ch;
    bool c;
    int tt;
    Task(A* a, int ch, bool c) : a(a), ch(ch), c(c) {}
};
class Fun
{
public:
    bool operator()(const Task* a, const Task* b) const
    {
        if (a->a != b->a)
        {
            return a->a < b->a;
        }
        if (a->c != b->c)
        {
            return a->c < b->c;
        }
        return a->ch < b->ch;
    }
};
set<Task*, Fun> tasks;

int main()
{
    auto a = new A();
    auto n = new Task(new A(), 2, true);
    auto m = new Task(new A(), 2, true);
    auto p = new Task(a, 2, true);
    p->tt = 1;
    auto q = new Task(a, 2, true);
    q->tt = 2;
    tasks.insert(n);
    tasks.insert(n);
    tasks.insert(m);
    tasks.insert(p);
    tasks.insert(p);
    tasks.insert(q);
    tasks.insert(new Task(a, 2, true));
    tasks.insert(new Task(a, 2, true));
    tasks.insert(new Task(a, 2, true));
    tasks.insert(new Task(a, 2, true));
    tasks.insert(new Task(a, 2, true));
    tasks.insert(new Task(a, 2, true));
    tasks.insert(q);
    tasks.insert(q);
    if (tasks.find(q) != tasks.end()) tasks.insert(q);
    delete q;
    tasks.erase(p);
    tasks.erase(q);
}