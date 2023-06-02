#include <iostream>
using namespace std;

int prime[50005];
int bcnt[500005];

int main()
{
    int n = 0;
    for (int i = 2; i <= 500000; i++)
    {
        if (bcnt[i] == 0)
        {
            prime[n++] = i;
        }
        for (int j = 0; j < n && prime[j] * i <= 500000; j++)
        {
            bcnt[prime[j] * i] = 1;
            if (prime[j] % i == 0)
            {
                break;
            }
        }
    }
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
    }
}