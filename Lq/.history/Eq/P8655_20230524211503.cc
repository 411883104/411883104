#include <iostream>
using namespace std;
const int c = 100005;
int s[c];
int n;

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
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        int xx = find(x);
        i yy = find(y);
        if (xx == yy)
        {
        }
    }
}