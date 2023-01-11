/*
 * @Author: Outsider
 * @Date: 2023-01-06 21:28:40
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-06 21:44:40
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1104.cc
 */
#include <iostream>
#include <algorithm>

using namespace std;

struct Stu
{
    int id;
    string name;
    int year;
    int month;
    int day;
};

bool cmp(Stu a, Stu b)
{
    if (a.year == b.year)
    {
        if (a.month == b.month)
        {
            if (a.day == b.day)
            {
                return a.id > b.id;
            }
            return a.day < b.day;
        }
        return a.month < b.month;
    }
    return a.year < b.year;
}

Stu arr[105];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].year >> arr[i].month >> arr[i].day;
        arr[i].id = i;
    }
    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].name << endl;
    }
}