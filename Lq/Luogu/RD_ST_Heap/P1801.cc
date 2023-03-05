/*
 * @Author       : Outsider
 * @Date         : 2023-03-02 13:58:02
 * @LastEditors  : Outsider
 * @LastEditTime : 2023-03-02 15:54:18
 * @Description  : In User Settings Edit
 * @FilePath     : \Lq\Luogu\RD_ST_Heap\P1801.cc
 */
#include <iostream>

using namespace std;

int maxx[205];
int minn[205];
int lmax;
int lmin;

void max_sink(int k)
{
    while (k * 2 + 1 < lmax)
    {
        int j = k * 2 + 1;
        if (j + 1 < lmax && maxx[j + 1] > maxx[j])
        {
            j++;
        }
        if (maxx[j] <= maxx[k])
        {
            break;
        }
        swap(maxx[j], maxx[k]);
        k = j;
    }
}
void min_sink(int k)
{
    while (2 * k + 1 < lmin)
    {
        int j = k * 2 + 1;
        if (j + 1 < lmin && minn[j + 1] < minn[j])
        {
            j++;
        }
        if (minn[j] >= minn[k])
        {
            break;
        }
        swap(minn[j], minn[k]);
        k = j;
    }
}
void max_float(int n)
{
    while (n)
    {
        int k = (n - 1) >> 1;
        if (maxx[k] < maxx[n])
        {
            swap(maxx[k], maxx[n]);
        }
        else
        {
            break;
        }
        n = k;
    }
}
void min_float(int n)
{
    while (n)
    {
        int k = (n - 1) >> 1;
        if (minn[k] > minn[n])
        {
            swap(minn[k], minn[n]);
        }
        else
        {
            break;
        }
        n = k;
    }
}
void max_insert(int x)
{
    maxx[lmax] = x;
    max_float(lmax++);
}
void min_insert(int x)
{
    minn[lmin] = x;
    min_float(lmin++);
}
int max_remove()
{
    swap(maxx[0], maxx[--lmax]);
    max_sink(0);
    return maxx[lmax];
}
int min_remove()
{
    swap(minn[0], minn[--lmin]);
    min_sink(0);
    return minn[lmin];
}
int add[200005];
int get[200005];

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> add[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> get[i];
    }
    int k = 0;
    int j = 0;
    for (int i = 1; i <= m; i++)
    {
        min_insert(add[i]);
        while (get[j] == i)
        {
            k++;
            if (lmax == 0)
                max_insert(min_remove());
            else
            {
                while (maxx[0] > minn[0])
                {
                    int t = min_remove();
                    min_insert(max_remove());
                    max_insert(t);
                }
                while (lmax < k)
                {
                    max_insert(min_remove());
                }
            }
            cout << maxx[0] << endl;
            j++;
        }
    }
}