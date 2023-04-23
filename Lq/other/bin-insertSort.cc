#include <iostream>
using namespace std;

int a[20] = {2, 5, 96, 12, 41, 20, 1, 3, 95, 1, 5, 6, 4, 5, 95, 15, 15, 5, 12, 21};

int main()
{
    for (int i = 1; i < 20; i++)
    {
        int x = a[i];
        int l = 0, r = i;
        while (l < r)
        {
            int m = l + ((r - l) >> 1);
            if (a[m] == x)
            {
                r = m;
            }
            else if (a[m] > x)
            {
                r = m;
            }
            else if (a[m] < x)
            {
                l = m + 1;
            }
        }

        for (int j = i; j > l; j--)
        {
            a[j] = a[j - 1];
        }
        a[l] = x;
    }
    for (int i = 0; i < 20; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}