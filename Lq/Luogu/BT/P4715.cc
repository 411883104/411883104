#include <iostream>
using namespace std;

pair<int, int> tt[1 << 10];

void search(int nn)
{
    for (int i = (1 << nn) - 1; i < (1 << (nn + 1)) - 1; i += 2)
    {
        if (tt[i].second > tt[i + 1].second)
        {
            tt[i >> 1] = tt[i];
        }
        else
        {
            tt[i >> 1] = tt[i + 1];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 1 << endl;
    }
    for (int i = (1 << (n)) - 1; i < (1 << (n + 1)) - 1; i++)
    {
        cin >> tt[i].second;
        tt[i].first = (i - ((1 << n) - 2));
    }
    while (n)
    {
        search(n--);
    }
    cout << (tt[1].second > tt[2].second ? tt[2].first : tt[1].first) << endl;
}