#include <iostream>
using namespace std;

int A[] = {2, 56, 23, 54, 12, 55, 56, 95, 12, 3, 5, 84, 62, 9, 51, 7, 3, 6, 100, 50};

int main()
{
    for (int i = 1; i < sizeof(A) / sizeof(int); i++)
    {
        int x = A[i];
        int ll = 0, rr = i;
        while (ll < rr)
        {
            int mm = (ll + rr) / 2;
            if (A[mm] == x)
            {
                ll = mm + 1;
            }
            else if (A[mm] > x)
            {
                rr = mm;
            }
            else if (A[mm] < x)
            {
                ll = mm + 1;
            }
        }
        for (int j = i; j > ll; j--)
        {
            A[j] = A[j - 1];
        }
        A[ll] = x;
    }
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}