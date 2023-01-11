/*
 * @Author: Outsider
 * @Date: 2023-01-06 12:04:14
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-06 13:20:36
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1093.cc
 */
#include <iostream>

using namespace std;

struct Stu
{
    int id;
    int ch;
    int mh;
    int eh;
    int tol;
};

Stu stu[1005];
int n;

void swap(Stu &a, Stu &b)
{
    Stu temp = a;
    a = b;
    b = temp;
}

int sort()
{
    for (int i = n - 1; i > n - 6; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (stu[j].tol > stu[j + 1].tol)
            {
                swap(stu[j], stu[j + 1]);
            }
            else if (stu[j].tol == stu[j + 1].tol)
            {
                if (stu[j].ch >= stu[j + 1].ch)
                {
                    swap(stu[j], stu[j + 1]);
                }
                else if (stu[j].ch == stu[j + 1].ch)
                {
                    if (stu[j].id > stu[j+1].id)
                    {
                        swap(stu[j], stu[j + 1]);
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        stu[i].id = i + 1;
        cin >> stu[i].ch >> stu[i].mh >> stu[i].eh;
        stu[i].tol = stu[i].ch + stu[i].mh + stu[i].eh;
    }
    sort();
    for (int i = n - 1; i > n - 6; i--)
    {
        cout << stu[i].id << " " << stu[i].tol << endl;
    }
}