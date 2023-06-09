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
//========================================================================0========================================================================//
#define f(x, y) x * x + 1
double x0, h, y;
int n;
main()
{
    //freopen("t.inp", "r", stdin);
    cout << "(Hay chinh sua ham f(x) trong code)\n";
    cout << fixed << setprecision(6);
    cout << "Nhap gia tri khoi dau (x0 y0) = "; cin >> x0 >> y;
    cout << "Nhap buoc nhay h = "; cin >> h;
    cout << "Nhap gia tri n = "; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double tmp = f(x0, y), y1 = y + h / 2 * tmp;
        tmp = f((x0 + h / 2), y1);
        y += h * tmp;
        x0 += h;
        cout << "x" << i << " = " << x0 << ", y" << i << " = " << y << '\n';
    }
    return 0;
}
