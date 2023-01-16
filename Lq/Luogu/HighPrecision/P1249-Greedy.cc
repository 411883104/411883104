/*
 * @Author: Outsider
 * @Date: 2023-01-16 14:22:26
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-16 20:11:45
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\Recursion\P1249-Greedy.cc
 */
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> ans;
vector<ll> tem;
ll maxx = 1;

ll arr[1000] = {0};

int mul(ll lt[], int len, int rt)
{
    for (int i = 0; i < len; i++)
    {
        lt[i] *= rt;
    }
    int i = 0;
    for (; i < len; i++)
    {
        lt[i + 1] += lt[i] / 10;
        lt[i] %= 10;
    }
    while (lt[i] != 0)
    {
        lt[i + 1] = lt[i] / 10;
        lt[i++] %= 10;
    }
    if (lt[i] == 0)
    {
        return i;
    }
    return i + 1;
}

int main()
{
    int n;
    cin >> n;
    if (n == 3 || n == 4)
    {
        cout << 1 << " " << n - 1 << endl
             << n - 1 << endl;
        return 0;
    }

    int sum = 0;
    for (int i = 2; i < n && sum < n; i++)
    {
        ans.push_back(i);
        sum += i;
    }
    int rt = sum - n;
    int i = 0;
    if (rt != 0)
    {
        for (; i < ans.size() && ans[i] < rt; i++)
            ;
        ans[ans.size() - 1] += ans[i] - rt;
        ans.erase(ans.begin() + i);
    }

    int len = 1;
    arr[0] = 1;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
        len = mul(arr, len, ans[i]);
    }
    cout << endl;
    for (int i = len - 1; i >= 0; i--)
    {
        cout << arr[i];
    }
    cout << endl;
}