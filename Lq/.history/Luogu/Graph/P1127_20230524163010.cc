#include <iostream>
#include <vector>

using namespace std;

vector<string> ss;

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        ss.push_back(s);
    }
}