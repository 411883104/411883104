#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] <= '9' && s[i] > '0')
        {
            for (int j = 0; j < s[i] - '0' - 1; j++)
            {
                cout << s[i - 1];
            }
        }
        else
        {
            cout << s[i];
        }
    }
    cout << endl;
}