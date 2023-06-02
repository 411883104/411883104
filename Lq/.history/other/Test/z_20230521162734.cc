#include <iostream>
using namespace std;

bool cal(int x, int y, int z) { return x * 3 + y * 4 + 2 * z <= 12; }

int ans = 0;
int a[6][6][7];
void dfs(int x, int y, int z)
{
    if (!cal(x, y, z) || a[x][y][z])
    {
        return;
    }
    cout << x << " " << y << " " << z << endl;
    ans++;
    dfs(x, y, z + 1);
    dfs(x, y + 1, z);
    dfs(x + 1, y, z);
}

int main()
{
    dfs(0, 0, 0);
    cout << ans << endl;
}