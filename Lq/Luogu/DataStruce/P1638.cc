#include <iostream>
#include <set>
#include <queue>
#include <deque>
using namespace std;

int sum[105];

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> s;
    deque<pair<int, int>> q;
    int x;

    int ll = 1, rr = n;
    int maxx = 0xfffffff;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        q.push_back(make_pair(x, i));
        s.insert(x);
        sum[x]++;
        if (q.size() != 1 && q.back().first == q.front().first)
        {
            
            sum[q.front().first]--;
            if (sum[q.front().first] == 0)
            {
                s.erase(q.front().first);
            }
            q.pop_front();
        }
        while (sum[q.front().first] > 1)
        {
            sum[q.front().first]--;
            q.pop_front();
        }
        if (s.size() == m && q.back().second - q.front().second < maxx)
        {
            maxx = q.back().second - q.front().second;
            ll = q.front().second;
            rr = q.back().second;
            // while (q.size() > m)
            // {
            //     q.pop_front();
            // }
        }
    }
    cout << ll << " " << rr << endl;
    return 0;
}