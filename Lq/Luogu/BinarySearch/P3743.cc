#include <iostream>
#include <climits>
using namespace std;

pair<double, double> a[2005];
double n, p;

bool check(double x)
{
    double ect = p * x;
    double tol = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].first * x > a[i].second)
        {
            tol += (x * a[i].first - a[i].second);
        }
    }
    return tol <= ect;
}

int main()
{
    cin >> n >> p;
    double x, y;
    double tol = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a[i] = pair<double, double>(x, y);
        tol += x;
    }
    if (p >= tol)
    {
        cout << -1 << endl;
        return 0;
    }
    double ll = 0, rr = 1e10;
    while (rr - ll > 1e-6)
    {
        double mm = ll + ((rr - ll) / 2);
        if (check(mm))
        {
            ll = mm;
        }
        else
        {
            rr = mm;
        }
    }
    cout.setf(ios::showpoint); // 设置输出小数点后多余的0
    cout << ll << endl;
}