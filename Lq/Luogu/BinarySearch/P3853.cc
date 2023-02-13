#include <iostream>
using namespace std;

int a[1005];
int b[1005];
int main()
{
    int l, n, k;
    cin >> l >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    
}