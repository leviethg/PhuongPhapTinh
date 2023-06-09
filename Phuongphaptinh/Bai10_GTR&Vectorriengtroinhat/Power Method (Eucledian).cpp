#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 100 + 10, MOD = 1e9 + 7;
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
double a[MAX][MAX], x[MAX], y[MAX], TOL;
int n, step;
double findVal()
{
    double ret = 0;
    for (int i = 1; i <= n; i++) ret += x[i] * x[i];
    return sqrt(ret);
}
double getLambda()
{
    double ans1 = 0;
    for (int i = 1; i <= n; i++) y[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            y[i] += a[i][j] * x[j];
        }
    }
    for (int i = 1; i <= n; i++) ans1 += y[i] * x[i];
    return ans1;
}
void powermethod()
{
    bool relative = 0;
    cout << fixed << setprecision(6);
    cout << "Nhap vao kich co ma tran n = "; cin >> n;
    cout << "Nhap vao ma tran A = \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    cout << "Nhap vao ma tran khoi dau x0 = \n";
    for (int i = 1; i <= n; i++) cin >> x[i];
    cout << "Nhap vao so buoc toi da step = "; cin >> step;
    cout << "Chon kieu sai so:\n0. Tuyet doi\n1.Tuong doi (%)\n"; cin >> relative;
    cout << "Nhap vao sai so cho phep TOL = "; cin >> TOL;
    if (relative) TOL /= 100;
    int curStep = 0;
    double oldLambda = 0, lambda = 0;
    while (++curStep <= step)
    {
        for (int i = 1; i <= n; i++) y[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                y[i] += a[i][j] * x[j];
            }
        }
        for (int i = 1; i <= n; i++) x[i] = y[i];
        double d = findVal();
        for (int i = 1; i <= n; i++) x[i] /= d;
        lambda = getLambda();
        cout << "x" << curStep << " = [ ";
        for (int i = 1; i <= n; i++) cout << x[i] << " ";
        cout << "]\nLambda" << curStep << " = " << lambda << "\n\n";
        double tmp = fabs((lambda - oldLambda));
        if (relative) tmp = fabs((lambda - oldLambda) / lambda);
        if (tmp <= TOL)
        {
            cout << "Tri rieng lon nhat la Lambda = " << lambda;
            cout << "\nVector rieng ung voi tri rieng lon nhat la x = [ ";
            for (int i = 1; i <= n; i++) cout << x[i] << " ";
            cout << "]";
            return;
        }
        oldLambda = lambda;
    }
    cout << "Vuot qua so buoc cho phep!";
}
main()
{
    //freopen("t.inp", "r", stdin);
    powermethod();
    return 0;
}
