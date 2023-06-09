#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
void unset(int &t, int pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(int &t, int pos)
{
    t |= (1ll << (pos - 1));
}
int getbit(int i,int k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(int &x, int y)
{
    x = min(x, y);
}
void maximize(int &x, int y)
{
    x = max(x, y);
}
int ADD(int x, int y)
{
    return (x + y) % MOD;
}
int MINUS(int x, int y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
#define f(x) 2*x*cos(2*x) - (x - 2)*(x - 2)
//Sua f(x) neu can
#define g(x) 2*cos(2*x) - 4*x*sin(2*x) - 2*(x - 2)
//Sua g(x) = f'(x) neu can
void Newton()
{
    double x0, TOL , f1;
    int step = 0, MAX_STEP;
    cout << fixed << setprecision(6);
    cout << "Nhap vao gia tri x0 = ";
    cin >> x0;
    cout << "\nNhap vao sai so toi da TOL = ";
    cin >> TOL;
    cout << "\nNhap vao so buoc toi da MAX_STEP = ";
    cin >> MAX_STEP;
    cout << '\n';
    do
    {
        step++;
        if (step > MAX_STEP)
        {
            cout << "So buoc vuot muc cho phep! / Ham khong hoi tu";
            return;
        }
        double g0 = g(x0);
        double f0 = f(x0);
        if (g0 == 0.0)
        {
            cout << "Xuat hien dao ham bang 0!";
            return;
        }
        double x1 = x0 - f0 / g0;
        cout << "Buoc " << step << ": x" << step << " = " << x1 << '\n';
        f1 = f(x1);
        x0 = x1;
    }
    while (fabs(f1) > TOL);
    cout << '\n' << "Nghiem gan dung la: x = " << x0;
}
main()
{
    //freopen("t.inp", "r", stdin);
    Newton();
    return 0;
}
