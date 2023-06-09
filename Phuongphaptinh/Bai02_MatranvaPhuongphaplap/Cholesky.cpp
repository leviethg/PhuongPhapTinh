#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 50, MOD = 1e9 + 7;
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
double matrix[MAX][MAX], b[MAX];
void Cholesky(int n)
{
    int l[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            double s = 0;
            if (i == j)
            {
                for (int k = 1; k < j; k++) s += l[i][k] * l[i][k];
                if (s > matrix[i][i])
                {
                    cout << "Khong the tach thanh ma tran L, U phu hop";
                    return;
                }
                l[i][i] = sqrt(matrix[i][i] - s);
            }
            else if (j < i)
            {
                for (int k = 1; k < j; k++) s += l[i][k] * l[j][k];
                if (!l[j][j])
                {
                    cout << "Khong the tach thanh ma tran L, U phu hop";
                    return;
                }
                l[i][j] = (matrix[i][j] - s) / l[j][j];
            }
            else l[i][j] = 0;
        }
    }
    cout << fixed << setprecision(3);
    cout << "\nMa tran L la:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cout << l[i][j] << " ";
        cout << '\n';
    }
    double y[n + 1], x[n + 1];
    for (int i = 1; i <= n; i++)
    {
        double s = 0;
        for (int k = 1; k < i; k++) s += l[i][k] * y[k];
        y[i] = (b[i] - s) / l[i][i];
    }
    for (int i = n; i >= 1; i--)
    {
        double s = 0;
        for (int k = n; k > i; k--) s += l[k][i] * x[k];
        x[i] = (y[i] - s) / l[i][i];
    }
    cout << "Nghiem cua he phuong trinh la:\n";
    for (int i = 1; i <= n; i++) cout << x[i] << "\n";
}
main()
{
    //freopen("t.inp", "r", stdin);
    int n;
    cout << "Nhap kich thuoc ma tran A: n = ";
    cin >> n;
    cout << "\nNhap ma tran A: A = \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cin >> matrix[i][j];
    }
    cout << "\nNhap ma tran ket qua b = \n";
    for (int i = 1; i <= n; i++) cin >> b[i];
    Cholesky(n);
    return 0;
}
