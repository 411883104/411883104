#include <iostream>
#include <vector>
using namespace std;
const int c = 100005;
int s[c];
int n;

vector<int> G[c];

int find(int x)
{
    if (s[x] == x)
    {
        return x;
    }
    return s[x] = find(s[x]);
}

int main()
{
    cin >> n;
    for (int i = 0; i <= n + 1; i++)
    {
        s[i] = i;
    }
    int x, y;
    int src, dst;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        int xx = find(x);
        int yy = find(y);
        if (xx == yy)
        {
            src = x;
            dst = y;
        }
        else
        {
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
}