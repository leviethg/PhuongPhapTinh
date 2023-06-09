#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e3 + 10, MOD = 1e9 + 7;
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
double matrix[MAX][MAX], val[MAX][MAX], sum[2][MAX], sol[MAX];
pair <double, double> giatri[MAX];
int n, m;
void swapRow(int i, int j)
{
    for (int k = 1; k <= n + 2; k++)
        swap(matrix[i][k], matrix[j][k]);
}
int elimination()
{
    for (int i = 1; i <= n + 1; i++)
    {
        int maxI = i;
        double maxVal = matrix[i][i];
        for (int j = i + 1; j <= n + 1; j++)
            if (abs(matrix[j][i]) > maxVal)
            {
                maxVal = matrix[j][i];
                maxI = j;
            }
        if (!maxVal) return (!matrix[maxI][n + 2] ? -1 : 0);
        else if (maxI != i) swapRow(i, maxI);
        for (int k = i + 1; k <= n + 1; k++)
        {
            double mul = matrix[k][i] / matrix[i][i];
            for (int j = i; j <= n + 2; j++)
                matrix[k][j] -= matrix[i][j] * mul;
        }

    }
    return 1;
}
void backSub()
{
    cout << "He so cua xap xi bac " << n << " la:\n";
    for (int i = n + 1; i >= 1; i--)
    {
        sol[i] = matrix[i][n + 2];
        for (int k = n + 1; k > i; k--) sol[i] -= matrix[i][k] * sol[k];
        sol[i] /= matrix[i][i];
    }
    for (int i = 1; i <= n + 1; i++) cout << "a" << i - 1 << " = " << sol[i] << '\n';
}
double getVal(double x, double y)
{
    double ret = 0, tmp = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        ret += tmp * sol[i];
        tmp *= x;
    }
    return (y - ret) * (y - ret);
}
void input()
{
    cout << fixed << setprecision(6);
    cout << "Nhap bac cua ham so n = "; cin >> n;
    cout << "Nhap so bo gia tri roi rac m = "; cin >> m;
    cout << "Nhap cac bo gia tri roi rac (x, y) = \n";
    for (int i = 1; i <= m; i++)
    {
        cin >> giatri[i].fi >> giatri[i].se;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            if (!j) val[i][j] = 1;
            else val[i][j] = val[i][j - 1] * giatri[i].fi;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            sum[0][j] += val[i][j];
            sum[1][j] += val[i][j] * giatri[i].se;
        }
    }
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            matrix[i][j] = sum[0][i + j - 2];
        }
    }
    for (int i = 1; i <= n + 1; i++)
    {
        matrix[i][n + 2] = sum[1][i - 1];
    }
    int t = elimination();
    if (t == -1 || !t) cout << "Khong tim duoc xap xi bac " << n;
    else
    {
        backSub();
        double err = 0;
        for (int i = 1; i <= m; i++) err += getVal(giatri[i].fi, giatri[i].se);
        cout << "Sai so E = " << err;
    }
}
main()
{
    freopen("t.inp", "r", stdin);
    input();
    return 0;
}
