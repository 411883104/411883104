/*
 * @Author: Outsider
 * @Date: 2023-01-06 15:46:02
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-06 20:47:12
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p1068.cc
 */
#include <iostream>
#include <map>

using namespace std;

struct St
{
    int id;
    int sco;
    bool operator<(St &s)
    {
        return this->sco < s.sco;
    }
};

St arr[5005];

void sort(int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j].sco > arr[j + 1].sco ||
                ((arr[j].sco == arr[j + 1].sco) && (arr[j].id < arr[j + 1].id)))
            {
                St s = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = s;
            }
        }
    }
}
int mp[105];
int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].id >> arr[i].sco;
        mp[arr[i].sco]++;
    }
    int d = m * 1.5;
    sort(n);
    int tol = 0;
    for (int i = 100; i >= arr[n - d].sco; i--)
    {
        tol += mp[i];
    }
    cout << arr[n - d].sco << " " << tol << endl;

    for (int i = 0; i < tol; i++)
    {
        cout << arr[n - 1 - i].id << " " << arr[n - 1 - i].sco << endl;
    }
}