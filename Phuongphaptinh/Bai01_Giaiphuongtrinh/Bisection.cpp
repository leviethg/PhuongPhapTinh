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
#define f(x) sin(x)
void Bisection()
{
    double x0, x1, fx1, fx0, TOL, preX = 0, p, fp;
    int step = 0, MAX_STEP;
    cout << fixed << setprecision(10);
    cout << "Nhap vao gia tri x0 = "; cin >> x0;
    cout << "\nNhap vao gia tri x1 = "; cin >> x1;
    cout << "\nNhap vao sai so toi da TOL = "; cin >> TOL;
    cout << "\nNhap vao so buoc toi da MAX_STEP = "; cin >> MAX_STEP;
    cout << "\n";
    while (1)
    {
        step++;
        if (step > MAX_STEP)
        {
            cout << "So buoc vuot muc cho phep! / Ham khong hoi tu";
            return;
        }
        fx1 = f(x1); fx0 = f(x0);
        p = x0 + (x1 - x0) / 2;
        fp = f(p);
        if (fp == 0 || (x1 - x0) / 2 < TOL) {
        	cout << "\nNghiem gan dung cua phuong trinh la : p = " << p;
        	return;
		}
		cout << "Buoc " << step << ": p" << step << " = " << p << endl;
		if (fx0 * fp > 0) {
			x0 = p;
			fx0 = fp;
		}
		else {
			x1 = p;
			fx1 = fp;
		}
    }
}

main()
{
    //freopen("t.inp", "r", stdin);
    Bisection();
    return 0;
}
