/*
 * @Author       : Outsider
 * @Date         : 2023-05-26 19:38:57
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-26 19:46:38
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\other\Test\mt\1.cc
 */
#include <iostream>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

unordered_map<int, int> m;
set<int> s;
deque<int> q;

int a[5005];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && (s.size() >= k && m[a[i]] == 0))
        {
            m[q.front()]--;
            if (m[q.front()] == 0)
            {
                s.erase(q.front());
            }
            q.pop_front();
            res--;
        }
        if (q.empty() || s.size() <= k || m[a[i]] != 0)
        {
            q.push_back(a[i]);
            if (m[a[i]] == 0)
            {
                s.insert(a[i]);
            }
            m[a[i]]++;
            res++;
            ans = max(res, ans);
        }
    }
    cout << ans << endl;
    return 0;
}