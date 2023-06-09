#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
double x, y[MAX], z[MAX], k[5][MAX], h;
int n, step;
double f(double i, double x)
{
    if (i == 1) return -4 * z[1] + -2 * z[2] + cos(x) + 4 * sin(x);
    if (i == 2) return 3 * z[1] + z[2] - 3 * sin(x);
    //if (i == 3) return pow(y[3], 1.0/3) - x * y[2];
    return 0;
}
void input()
{
    cout << fixed << setprecision(10);
    cout << "(Hay chinh sua HPT trong code)\n";
    cout << "Nhap so luong phuong trinh n = "; cin >> n;
    cout << "Nhap gia tri ban dau x0 = "; cin >> x;
    cout << "Nhap cac gia tri ban dau y0[i] = \n";
    for (int i = 1; i <= n; i++) cin >> y[i];
    cout << "Nhap buoc nhay h = "; cin >> h;
    cout << "Nhap so luong buoc nhay step = "; cin >> step;
}
void midpoint()
{
    for (int s = 1; s <= step; s++)
    {
        cout << "\nStep " << s << ":\n";
        for (int i = 1; i <= n; i++) z[i] = y[i];
        for (int i = 1; i <= n; i++)
        {
            k[1][i] = z[i] + h / 2 * f(i, x);
        }
        for (int i = 1; i <= n; i++) z[i] = k[1][i];
        for (int i = 1; i <= n; i++)
        {
            y[i] += h * f(i, x + h);
            cout << "y" << s << "[" << i << "] = " << y[i] << '\n';
        }
        x += h;
    }
}
main()
{
    input();
    midpoint();
    return 0;
}
