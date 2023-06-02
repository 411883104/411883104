#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n / 2; i++)
    {
        cout << (n - i) * 2 << endl;
        v.push_back((n - i) * 2);
    }
    if (n % 2)
    {
        cout << (n - n / 2) * 2 - 2 << endl;
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << endl;
    }
}