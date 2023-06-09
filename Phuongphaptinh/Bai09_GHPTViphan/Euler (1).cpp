#include <iostream>
#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
double x, y[MAX], z[MAX], h;
int n, step;
double f(double i, double x)
{
    if (i == 1) return 3 * y[1] + 2 * y[2] - (2 * x * x + 1) * exp(2 * x);
    if (i == 2) return 4 * y[1] + y[2] + (x * x + 2 * x - 4) * exp(2 * x);
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
void euler()
{
    for (int s = 1; s <= step; s++)
    {
        cout << "\nStep " << s << ":\n";
        for (int i = 1; i <= n; i++)
        {
            z[i] = y[i] + h * f(i, x);
        }
        for (int i = 1; i <= n; i++)
        {
            y[i] = z[i];
            cout << "y" << s << "[" << i << "] = " << y[i] << '\n';
        }
        x += h;
    }
}
main()
{
    input();
    euler();
    return 0;
}
