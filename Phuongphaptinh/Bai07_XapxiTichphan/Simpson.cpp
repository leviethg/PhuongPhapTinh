#include <iostream>
#include <bits/stdc++.h>
#define M_PI 3.1415926535
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
#define f(x) sqrt(2 * M_PI) * exp(-x * x / 2)
int n;
double x[MAX], a, b;
void simpson()
{
    cout << "(Hay chinh sua ham f(x) trong code)\n";
    cout << fixed << setprecision(15);
    cout << "Nhap vao khoang khao sat (a b) = "; cin >> a >> b;
    cout << "Nhap vao so (le) diem moc n = "; cin >> n;
    while (n % 2 == 0)
    {
        cout << "Yeu cau n la so le\nNhap vao so (le) diem moc n = ";
        cin >> n;
    }
    double h = (b - a) / (n - 1);
    double res = 0;
    for (int i = 0; i < n; i++)
    {
        x[i] = a;
        double tmp = f(x[i]);
        if (i == 0 || i == n - 1) res += tmp;
        else if (i % 2) res += 4 * tmp;
        else res += 2 * tmp;
        a += h;
    }
    res *= h / 3;
    cout << "Tich phan cua ham so xap xi bang " << res;
}
main()
{
    //freopen("t.inp", "r", stdin);
    simpson();
    return 0;
}
