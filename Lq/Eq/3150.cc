#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxx = INT_MAX, minn = INT_MIN;

    int x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;

        maxx = min(x / y, maxx);
        minn = max(x / (y + 1) + 1, minn);
    }
    cout << minn << " " << maxx << endl;
    return 0;
}