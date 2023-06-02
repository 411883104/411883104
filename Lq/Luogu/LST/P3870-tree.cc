/*
 * @Author       : Outsider
 * @Date         : 2023-05-28 14:09:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-28 17:58:22
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\LST\P3870-tree.cc
 */
#include <iostream>
using namespace std;

const int c = 1005;
int aa[c];
int n, m;

struct tree
{
    int ll, rr, sum;
};

tree tt[4 * c];

int update(int x){
    
}

void init(int x, int l, int r)
{
    if (l == r)
    {
        tt[x].sum = 0;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            modify(b, 1);
            modify(c + 1, -1);
        }
        else
        {
            int ans = 0;
            for (int i = b; i <= c; i++)
            {
                if (query(i) % 2 == 1)
                {
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}