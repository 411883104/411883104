#include <iostream>
using namespace std;

bool cal(int x, int y, int z) { return x * 3 + y * 4 + 2 * z <= 12; }

int ans = 0;
void dfs(int x, int y, int z)
{
    if (cal(x, y, z))
    {
        ans++;
    }else{
        return;
    }
    for (int i = x + 1; i <= 6; i++)
    {
        dfs(i, y, z);
    }
    for (int i = y + 1; i <= 6; i++)
    {
        dfs(x, i, z);
    }
    for (int i = z + 1; i <= 6; i++)
    {
        dfs(z, y , i);
    }
}

int main() {
    dfs(0,0,0);
    cout<<ans<<endl;
}