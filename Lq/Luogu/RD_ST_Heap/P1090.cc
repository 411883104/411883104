#include <iostream>

using namespace std;

int hh[10005];
int n;

void sink(int k)
{
    while (k * 2 + 1 < n)
    {
        int j = (k << 1) + 1;
        if (j + 1 < n && hh[j] > hh[j + 1])
        {
            j++;
        }
        if (hh[j] > hh[k])
        {
            break;
        }
        swap(hh[j], hh[k]);
        k = j;
    }
}

int remove()
{
    swap(hh[0], hh[--n]);
    sink(0);
    return hh[n];
}
void up(int k)
{
    while (k)
    {
        int j = ((k - 1) >> 1);
        if (hh[j] > hh[k])
        {
            swap(hh[j], hh[k]);
        }
        else
        {
            break;
        }
        k = j;
    }
}

void insert(int x)
{
    hh[n] = x;
    up(n++);
}

void init()
{
    for (int i = ((n - 1) >> 1); i >= 0; i--)
    {
        sink(i);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> hh[i];
    }
    init();
    int ans = 0;
    if (n == 1)
    {
        cout << hh[0] << endl;
        return 0;
    }
    while (n > 1)
    {
        int x = remove() + remove();
        insert(x);
        ans += x;
    }
    cout << ans << endl;
}