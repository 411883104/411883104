#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
using namespace std;
vector<string> dfs(int n, int &tab)
{
    stringstream ss;
    vector<string> v;
    if (n == 1)
    {
        ss << "/\\";
        v.push_back(ss.str());
        cout << string(--tab, ' ') << ss.str() << endl;
        ss.str("");
        ss << "/__\\";
        v.push_back(ss.str());
        cout << string(--tab, ' ') << ss.str() << endl;
        return v;
    }
    auto ret = dfs(n - 1, tab);
    size_t sz = ret.size();
    size_t mm = (sz - 1) * 2;
    for (size_t i = 0; i < sz; i++)
    {
        ss.str("");
        ss << string(ret[i].begin(), ret[i].end()) << string(mm, ' ') << string(ret[i].begin(), ret[i].end());
        mm -= 2;
        ret.push_back(ss.str());
        cout << string(--tab, ' ') << ss.str() << endl;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    int tt = (1 << n);
    dfs(n, tt);
}