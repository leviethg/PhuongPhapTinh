#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 110, MOD = 1e9 + 7;
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
double matrix[MAX][MAX];
double b[MAX];
void Doolittle(int n)
{
    double l[n + 1][n + 1], u[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double s = 0;
            if (i == j)
            {
                l[i][i] = 1;
                for (int k = 1; k < i; k++) s += l[i][k] * u[k][i];
                u[i][i] = matrix[i][i] - s;
            }
            else if (j < i)
            {
                u[i][j] = 0;
                for (int k = 1; k < j; k++) s += l[i][k] * u[k][j];
                if (!u[j][j])
                {
                    cout << "Khong tach duoc ma tran L, U phu hop";
                    return;
                }
                l[i][j] = (matrix[i][j] - s) / u[j][j];
            }
            else
            {
                l[i][j] = 0;
                for (int k = 1; k < i; k++) s += l[i][k] * u[k][j];
                u[i][j] = matrix[i][j] - s;
            }
        }
    }
    cout << "\nMa tran L:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << l[i][j] << " ";
        cout << '\n';
    }
    cout << "\nMa tran U:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << u[i][j] << " ";
        cout << '\n';
    }

    double y[n + 1], x[n + 1];
    for (int i = 1; i <= n; i++)
    {
        double s = 0;
        for (int k = 1; k < i; k++) s += l[i][k] * y[k];
        y[i] = b[i] - s;
    }
    for (int i = n; i >= 1; i--)
    {
        double s = 0;
        for (int k = n; k > i; k--) s += u[i][k] * x[k];
        x[i] = (y[i] - s) / u[i][i];
    }
    cout << "Nghiem cua he phuong trinh la:\n";
    for (int i = 1; i <= n; i++) cout << x[i] << "\n";
}
main()
{
    int n;
    cout << "Nhap kich thuoc ma tran n = ";
    cin >> n;
    cout << "\nNhap ma tran he so A = \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cin >> matrix[i][j];
    }
    cout << "\nNhap ma tran ket qua b = \n";
    for (int i = 1; i <= n; i++) cin >> b[i];
    Doolittle(n);
    return 0;
}
