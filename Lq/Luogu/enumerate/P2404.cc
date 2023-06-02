#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> v;
void dfs(int x, int s)
{
    if (x == n)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            cout << v[i] << "+";
        }
        cout << v[v.size() - 1] << endl;
        return;
    }
    if (x > n)
    {
        return;
    }
    for (int i = s; i < n; i++)
    {
        v.push_back(i);
        dfs(x + i, i);
        v.pop_back();
    }
}

int main()
{
    cin >> n;
    dfs(0, 1);
}