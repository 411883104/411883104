/*
 * @Author       : Outsider
 * @Date         : 2023-03-03 10:07:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-03 10:13:34
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\RD_ST_Heap\P1090-stl.cc
 */
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n;
int main()
{
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    if (n == 1)
    {
        cout << q.top() << endl;
        return 0;
    }
    while (q.size() > 1)
    {
        int x = q.top();
        q.pop();
        x += q.top();
        q.pop();
        q.push(x);
        ans += x;
    }
    cout << ans << endl;
}