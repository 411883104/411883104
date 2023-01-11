/*
 * @Author: Outsider
 * @Date: 2023-01-07 14:53:53
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-07 15:09:54
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\sort\p5143.cc
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct point
{
    int x;
    int y;
    int z;
};
bool cmp(point a, point b)
{
    return a.z < b.z;
}

point arr[50005];

double dist(point a, point b)
{
    double ans =
        (a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y) +
        (a.z - b.z) * (a.z - b.z);
    return sqrt(ans);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y >> arr[i].z;
    }
    sort(arr, arr + n, cmp);
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += dist(arr[i], arr[i + 1]);
    }
    cout << fixed << setprecision(3) << ans << endl;
}