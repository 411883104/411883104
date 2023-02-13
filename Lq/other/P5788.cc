/*
 * @Author: Outsider
 * @Date: 2023-02-10 11:16:09
 * @LastEditors: Outsider
 * @LastEditTime: 2023-02-10 14:56:50
 * @Description: In User Settings Edit
 * @FilePath: \Lq\other\P5788.cc
 */
#include <iostream>
using namespace std;
int a[3000005];
pair<int, int> ss[3000005];
int ans[3000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int tt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (tt == 0 || ss[tt].second >= a[i])
        {
            ss[++tt] = make_pair(i, a[i]);
        }
        else if (ss[tt].second < a[i])
        {
            while (tt > 0 && ss[tt].second < a[i])
            {
                ans[ss[tt].first] = i;
                --tt;
            };
            ss[++tt] = make_pair(i, a[i]);
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << ans[n] << endl;
}