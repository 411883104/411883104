#include <iostream>

using namespace std;

int main()
{
    int n, k, a, b;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> a >> b;
        if (n < k)
        {
            cout << 0 << endl;
            for (int i = 0; i < n; i++)
            {
                cout << "ab"[i % 2];
            }
            cout << endl;
        }
        else
        {
            cout << endl
                 << endl;
        }
    }
}