/*
 * @Author: Outsider
 * @Date: 2023-01-25 11:08:57
 * @LastEditors: Outsider
 * @LastEditTime: 2023-01-26 09:54:56
 * @Description: In User Settings Edit
 * @FilePath: \Lq\Luogu\LST\P3373.cc
 */
#include <iostream>
#include <cmath>

using namespace std;

const int c = 100050;
int p = 571373;
int arr[c];

class LST
{
public:
    long long sum;
    int left;
    int right;
    long long add;
    long long mul;
};

LST tt[5 * c];

void update(int x)
{
    tt[x].sum = tt[2 * x].sum + tt[2 * x + 1].sum;
    tt[x].sum %= p;
}

void markdown(int x)
{
    if (tt[x].left == tt[x].right)
    {
        return;
    }
    if (tt[x].mul != 1)
    {
        tt[x * 2].sum *= tt[x].mul;
        tt[x * 2].sum %= p;

        tt[x * 2 + 1].sum *= tt[x].mul;
        tt[x * 2 + 1].sum %= p;

        tt[x * 2].mul *= tt[x].mul;
        tt[x * 2].mul %= p;

        tt[x * 2 + 1].mul *= tt[x].mul;
        tt[x * 2 + 1].mul %= p;

        tt[x * 2].add *= tt[x].mul;
        tt[x * 2].add %= p;
        tt[x * 2 + 1].add *= tt[x].mul;
        tt[x * 2 + 1].add %= p;

        tt[x].mul = 1;
    }
    if (tt[x].add != 0)
    {
        tt[x * 2].sum += tt[x].add * (tt[x * 2].right - tt[x * 2].left + 1);
        tt[x * 2].sum %= p;
        tt[x * 2 + 1].sum += tt[x].add * (tt[x * 2 + 1].right - tt[x * 2 + 1].left + 1);
        tt[x * 2 + 1].sum %= p;
        tt[x * 2].add += tt[x].add;
        tt[x * 2].add %= p;
        tt[x * 2 + 1].add += tt[x].add;
        tt[x * 2 + 1].add %= p;
        tt[x].add = 0;
    }
}

void rm(int x, int l, int r, int val)
{
    if (tt[x].left >= l && tt[x].right <= r)
    {
        tt[x].sum *= val;
        tt[x].sum %= p;
        tt[x].mul *= val;
        tt[x].mul %= p;
        tt[x].add *= val;
        tt[x].add %= p;
        return;
    }

    markdown(x);

    int mid = tt[x].left + ((tt[x].right - tt[x].left) >> 1);
    if (l <= mid)
    {
        rm(x * 2, l, r, val);
    }
    if (r >= mid + 1)
    {
        rm(x * 2 + 1, l, r, val);
    }

    update(x);
}

void ra(int x, int l, int r, int val)
{
    if (tt[x].left >= l && tt[x].right <= r)
    {
        tt[x].sum += val * (tt[x].right - tt[x].left + 1);
        tt[x].sum %= p;
        tt[x].add += val;
        tt[x].add %= p;
        return;
    }

    markdown(x);

    int mid = tt[x].left + ((tt[x].right - tt[x].left) >> 1);
    if (l <= mid)
    {
        ra(x * 2, l, r, val);
    }
    if (r >= mid + 1)
    {
        ra(x * 2 + 1, l, r, val);
    }

    update(x);
}

long long rq(int x, int l, int r)
{
    if (tt[x].left >= l && tt[x].right <= r)
    {
        return tt[x].sum;
    }
    long long sum = 0;

    markdown(x);

    int mid = tt[x].left + ((tt[x].right - tt[x].left) >> 1);
    if (l <= mid)
    {
        sum += rq(2 * x, l, r);
        sum %= p;
    }
    if (r >= mid + 1)
    {
        sum += rq(2 * x + 1, l, r);
        sum %= p;
    }
    return sum;
}

void init(int x, int left, int right)
{
    tt[x].left = left;
    tt[x].right = right;
    tt[x].mul = 1;
    if (right == left)
    {
        tt[x].sum = arr[left];
        return;
    }
    int mid = left + ((right - left) >> 1);
    init(x * 2, left, mid);
    init(x * 2 + 1, mid + 1, right);
    update(x);
}

int n, m;

int main()
{
    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    init(1, 1, n);

    int x, y, k;
    while (m--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> x >> y >> k;
            rm(1, x, y, k);
        }
        else if (x == 2)
        {
            cin >> x >> y >> k;
            ra(1, x, y, k);
        }
        else if (x == 3)
        {
            cin >> x >> y;
            cout << rq(1, x, y) << endl;
        }
    }
}