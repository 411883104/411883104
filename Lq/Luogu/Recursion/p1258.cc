#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s(2 * n + 2, '-');
    for (int i = 0; i < n; i++)
    {
        s[i] = 'o';
        s[i + n] = '*';
    }
    cout << s << endl;
    while (n > 4)
    {
        s[n - 1] = s[n] = '-';
        s[n * 2] = 'o';
        s[n * 2 + 1] = '*';
        cout << s << endl;
        s[n - 1] = s[n] = '*';
        s[(n - 1) * 2] = s[(n - 1) * 2 + 1] = '-';
        cout << s << endl;
        n -= 1;
    }
    s[3] = s[4] = '-';
    s[8] = 'o';
    s[9] = '*';
    cout << s << endl;
    s[3] = '*';
    s[4] = 'o';
    s[7] = s[8] = '-';
    cout << s << endl;
    s[1] = s[2] = '-';
    s[7] = s[8] = 'o';
    cout << s << endl;
    s[1] = '*';
    s[2] = 'o';
    s[6] = s[7] = '-';
    cout << s << endl;
    s[0] = s[1] = '-';
    s[6] = 'o';
    s[7] = '*';
    cout << s << endl;
}