#include <iostream>

using namespace std;

struct Heap
{
    int hh[505];
    int n;
};
Heap maxx;
Heap minn;

void swap(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}

void maxx_float(int n)
{
    while (n)
    {
        int k = ((n - 1) >> 1);
        if (maxx.hh[k] < maxx.hh[n])
        {
            swap(maxx.hh[k], maxx.hh[n]);
        }
        n = k;
    }
}
void maxx_sink(int k)
{
    while (2 * k + 1 < maxx.n)
    {
        int j = 2 * k + 1;
        if (j + 1 < maxx.n && maxx.hh[j + 1] > maxx.hh[j])
        {
            j++;
        }
        if (maxx.hh[k] >= maxx.hh[j])
        {
            break;
        }
        swap(maxx.hh[j], maxx.hh[k]);
        k = j;
    }
}

void insert_max(int&& x)
{
    maxx.hh[maxx.n] = x;
    maxx_float(maxx.n++);
}
int remove_max()
{
    swap(maxx.hh[0], maxx.hh[--maxx.n]);
    maxx_sink(0);
    return maxx.hh[maxx.n];
}

void minn_float(int n)
{
    while (n)
    {
        int k = (n - 1) >> 1;
        if (minn.hh[n] < minn.hh[k])
        {
            swap(minn.hh[n], minn.hh[k]);
        }
        n = k;
    }
}

void insert_min(int&& x)
{
    minn.hh[minn.n] = x;
    minn_float(minn.n++);
}

void minn_sink(int k)
{
    while (2 * k + 1 < minn.n)
    {
        int j = 2 * k + 1;
        if (j + 1 < minn.n && minn.hh[j + 1] < minn.hh[j])
        {
            j++;
        }
        if (minn.hh[j] >= minn.hh[k])
        {
            break;
        }
        swap(minn.hh[j], minn.hh[k]);
        k = j;
    }
}
int remove_min()
{
    swap(minn.hh[--minn.n], minn.hh[0]);
    minn_sink(0);
    return minn.hh[minn.n];
}

int main()
{
    int n;
    int x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (maxx.n == 0 || maxx.hh[0] > x)
        {
            insert_max(std::move(x));
        }
        else
        {
            insert_min(std::move(x));
        }
        if (maxx.n > minn.n + 1)
        {
            insert_min(remove_max());
        }
        else if (minn.n > maxx.n)
        {
            insert_max(remove_min());
        }
        if (i % 2 == 1)
        {
            if (maxx.n > minn.n)
            {
                cout << maxx.hh[0] << endl;
            }
            else
            {
                cout << (maxx.hh[0] + minn.hh[0]) / 2 << endl;
            }
        }
    }
}