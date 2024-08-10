#include <iostream>
using namespace std;

const int cc = 5005;
int mm[] = {0,
            31,
            31 + 28,
            31 + 28 + 31,
            31 + 28 + 31 + 30,
            31 + 28 + 31 + 30 + 31,
            31 + 28 + 31 + 30 + 31 + 30,
            31 + 28 + 31 + 30 + 31 + 30 + 31,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
            31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
            31};
int it[cc];
int dp[cc];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int a, b, c;

    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        it[i] = mm[a - 1] + b;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= it[i]; j++)
        {
        }
    }
}