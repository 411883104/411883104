/*
 * @Author: Outsider
 * @Date: 2023-02-10 18:28:04
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-10 18:50:27
 * @Description: In User Settings Edit
 * @FilePath: \Lq\other\test.cc
 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Shape
{
public:
    Shape() {}
    ~Shape() {}
    virtual char *description() = 0;
};

class Square : public Shape
{
public:
    Square()
    {
        m_pName = new char[100];
        memset(m_pName, 0, sizeof(*m_pName));
        strcpy(m_pName, "Square");
    }
    ~Square()
    {
        delete m_pName;
    }
    char *description()
    {
        return m_pName;
    }

private:
    char *m_pName;
};

class Circle : public Shape
{
public:
    Circle() {}
    ~Circle() {}
    char *description() { return (char *)"Circle"; };
};

int main(int argc, char *argv[])
{
    vector<Shape *> ShapeContainer;
    ShapeContainer.push_back(new Square());
    ShapeContainer.push_back(new Circle());
    vector<Shape *>::iterator it = ShapeContainer.begin();
    for (; it != ShapeContainer.end(); )
    {
        printf("Shape name is: %s", (*it)->description());
        ShapeContainer.erase(it);
    }
}