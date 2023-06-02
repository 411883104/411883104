/*
 * @Author       : Outsider
 * @Date         : 2023-05-28 14:09:16
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-05-30 22:16:05
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\LST\P3870-block.cc
 */
#include <iostream>
#include <cmath>
using namespace std;

const int c = 1005;
int bb[c];
int block[c];
int res[c];
int n, m;
int bsz;

void modify(int l, int r)
{
    int ll = (l - 1) / bsz + 1, rr = (r - 1) / bsz + 1;
    if (ll == rr)
    {
        for (int i = l; i <= r; i++)
        {
            bb[i] = (bb[i] + 1) % 2;
            if (bb[i] == 0)
            {
                res[ll]--;
            }
            else
            {
                res[ll]++;
            }
        }
    }
    else
    {
        for (int i = ll + 1; i <= rr - 1; i++)
        {
            res[i] = bsz - res[i];
            block[i] ^= 1;
        }
        for (int i = l; i <= ll * bsz; i++)
        {
            bb[i] = (bb[i] + 1) % 2;
            if (bb[i] == 0)
            {
                res[ll]--;
            }
            else
            {
                res[ll]++;
            }
        }
        for (int i = (rr - 1) * bsz + 1; i <= r; i++)
        {
            bb[i] = (bb[i] + 1) % 2;
            if (bb[i] == 0)
            {
                res[rr]--;
            }
            else
            {
                res[rr]++;
            }
        }
    }
}

int query(int l, int r)
{
    int ans = 0;
    int ll = (l - 1) / bsz + 1, rr = (r - 1) / bsz + 1;
    if (ll == rr)
    {
        for (int i = l; i <= r; i++)
        {
            ans += ((bb[i]) % 2);
        }
    }
    else
    {
        for (int i = ll + 1; i <= rr - 1; i++)
        {
            ans += res[i];
        }
        for (int i = l; i <= ll * bsz; i++)
        {
            ans += (bb[i]) % 2;
        }
        for (int i = (rr - 1) * bsz + 1; i <= r; i++)
        {
            ans += (bb[i]) % 2;
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    bsz = sqrt(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0)
        {
            modify(b, c);
        }
        else
        {
            int ans = query(b, c);

            cout << ans << endl;
        }
    }
    return 0;
}