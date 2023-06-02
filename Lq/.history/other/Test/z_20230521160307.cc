#include <iostream>
using namespace std;

bool cal(int x, int y, int z) { return x * 3 + y * 4 + 2 * z <= 12; }

int ans = 0;
void dfs(int x, int y, int z)
{
    if (cal(x, y, z))
    {
        cout << x << " " << y << " " << z << endl;
        ans++;
    }
    else
    {
        return;
    }
    dfs(x, y, z + 1);
    dfs(x, y + 1, z);
    dfs(x + 1, y, z);
}

int main()
{
    dfs(0, 0, 0);
    cout << ans << endl;
}