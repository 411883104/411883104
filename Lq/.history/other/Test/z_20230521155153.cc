#include <iostream>
using namespace std;

bool cal(int x, int y, int z) { return x * 3 + y * 4 + 2 * z <= 12; }

int ans = 0;
void dfs(int x, int y, int z)
{
    if (cal(x, y, z))
    {
        ans++;
    }
    for (int i = x + 1; i <= 6; i++)
    {
    }
    for (int i = x + 1; i <= 6; i++)
    {
    }
    for (int i = x + 1; i <= 6; i++)
    {
    }
}

int main() {}