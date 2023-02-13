#include <iostream>
using namespace std;

void dfs(int x, int y, int xx, int yy, int s)
{
    if (s == 1)
    {
        return;
    }
    int hh = (s >> 1);
    if (xx < x + hh && yy < y + hh)
    {
        cout << hh + x << " " << hh + y << " " << 1 << endl;
        dfs(x, y, xx, yy, hh);
        dfs(x, y + hh, x + hh - 1, y + hh, hh);
        dfs(x + hh, y, x + hh, y + hh - 1, hh);
        dfs(x + hh, y + hh, x + hh, y + hh, hh);
    }
    else if (xx >= hh + x && yy >= hh + y)
    {
        cout << hh + x - 1 << " " << hh + y - 1 << " " << 4 << endl;
        dfs(hh + x, hh + y, xx, yy, hh);
        dfs(x, y, x + hh - 1, y + hh - 1, hh);
        dfs(x, y + hh, x + hh - 1, y + hh, hh);
        dfs(x + hh, y, x + hh, y + hh - 1, hh);
    }
    else if (xx < hh + x && yy >= hh + y)
    {
        cout << hh + x << " " << hh + y - 1 << " " << 2 << endl;
        dfs(x, hh + y, xx, yy, hh);
        dfs(x, y, hh + x - 1, hh + y - 1, hh);
        dfs(x + hh, y, x + hh, y + hh - 1, hh);
        dfs(x + hh, y + hh, x + hh, y + hh, hh);
    }
    else if (xx >= hh + x && yy < hh + y)
    {
        cout << hh + x - 1 << " " << hh + y << " " << 3 << endl;
        dfs(x + hh, y, xx, yy, hh);
        dfs(x, y, hh + x - 1, hh + y - 1, hh);
        dfs(x, hh + y, x + hh - 1, y + hh, hh);
        dfs(x + hh, y + hh, x + hh, y + hh, hh);
    }
}

int main()
{
    int n;
    cin >> n;
    int sx, sy;
    cin >> sx >> sy;
    dfs(1, 1, sx, sy, (1 << n));
}