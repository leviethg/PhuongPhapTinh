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
#define f(x) x * x * x - 2 * x;
pair <double, double> p[100];
int n;
double x;
void input1()
{
    cout << "Nhap vao so bo roi rac n = "; cin >> n;
    cout << "Nhap vao cac bo du lieu (x, y) = \n";
    for (int i = 1; i <= n; i++) cin >> p[i].fi >> p[i].se;
    cout << "Nhap vao gia tri x can tim x = "; cin >> x;
}
void input2()
{
    cout << "(Hay chinh sua ham so o trong code)\n";
    double a, b;
    cout << "Nhap khoang khao sat (a b) = "; cin >> a >> b;
    cout << "Nhap so bo gia tri n = "; cin >> n;
    double d = (b - a) / (n - 1);
    for (int i = 1; i <= n; i++)
    {
        p[i].fi = a;
        p[i].se = f(a);
        a += d;
    }
    cout << "Nhap vao gia tri x can tim x = "; cin >> x;
}
void input()
{
    cout << fixed << setprecision(10);
    int type;
    cout << "Chon kieu input\n1.Input so luong va gia tri cac bo roi rac\n2.Input ham so, khoang khao sat va so luong cac bo gia tri roi rac (cach deu)\n"; cin >> type;
    if (type == 1) input1();
    else input2();
}
void interpolation()
{
    double res = 0;
    for (int i = 1; i <= n; i++)
    {
        double tmp = p[i].se;
        for (int j = 1; j <= n; j++)
        {
            if (i == j) continue;
            tmp *= (x - p[j].fi) / (p[i].fi - p[j].fi);
        }
        res += tmp;
    }
    cout << res;
}
main()
{
    input();
    interpolation();
    return 0;
}
