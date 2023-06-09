#include <bits/stdc++.h>
using namespace std;

using vec = vector<double>;
int n;
struct SplineSet{
    double a, b, c, d, x;
};

vector<SplineSet> spline(vec &x, vec &y)
{
    vec a;
    a.insert(a.begin(), y.begin(), y.end());
    vec b(n);
    vec d(n);
    vec h;

    for(int i = 0; i < n; ++i)
        h.push_back(x[i+1]-x[i]);

    vec alpha;
    alpha.push_back(0);
    for(int i = 1; i < n; ++i)
        alpha.push_back( 3*(a[i+1]-a[i])/h[i] - 3*(a[i]-a[i-1])/h[i-1]  );

    vec c(n+1);
    vec l(n+1);
    vec mu(n+1);
    vec z(n+1);
    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    for(int i = 1; i < n; ++i)
    {
        l[i] = 2 *(x[i+1]-x[i-1])-h[i-1]*mu[i-1];
        mu[i] = h[i]/l[i];
        z[i] = (alpha[i]-h[i-1]*z[i-1])/l[i];
    }

    l[n] = 1;
    z[n] = 0;
    c[n] = 0;

    for(int j = n-1; j >= 0; --j)
    {
        c[j] = z [j] - mu[j] * c[j+1];
        b[j] = (a[j+1]-a[j])/h[j]-h[j]*(c[j+1]+2*c[j])/3;
        d[j] = (c[j+1]-c[j])/3/h[j];
    }

    vector<SplineSet> output_set(n);
    for(int i = 0; i < n; ++i)
    {
        output_set[i].a = a[i];
        output_set[i].b = b[i];
        output_set[i].c = c[i];
        output_set[i].d = d[i];
        output_set[i].x = x[i];
    }
    return output_set;
}

int main()
{
    //freopen("t.inp", "r", stdin);
    cout << fixed << setprecision(6);
    cout << "Nhap vao so bo du lieu n = "; cin >> n;
    vec x(n); vec y(n);
    n--;
    cout << "Nhap vao cac bo du lieu (x y) = \n";
    for (int i = 0; i <= n; i++) cin >> x[i] >> y[i];
    vector<SplineSet> cs = spline(x, y);
    cout << "Chon loai output:\n";
    cout << "1. Dua ra cac da thuc bac 3 spline\n";
    cout << "2. Nhap vao gia tri x. Tinh gia tri cua ham so tai diem x do\n";
    int type;
    cin >> type;
    if (type == 1)
    {
        cout << "Cac da thuc spline la: \n";
        for (int i = 0; i < (int)cs.size(); ++i)
        {
            cout << "g" << i << "(x) = ";
            cout << cs[i].d << "(x - " << x[i] << ")^3 + ";
            cout << cs[i].c << "(x - " << x[i] << ")^2 + ";
            cout << cs[i].b << "(x - " << x[i] << ") + ";
            cout << cs[i].a << '\n';
        }
    }
    else if (type == 2)
    {
        double X;
        cout << "Nhap vao gia tri x: "; cin >> X;
        cout << "Gia tri cua ham so tai diem x la: ";
        for (int i = 1; i <= n; i++)
        {
            if (x[i] > X)
            {
                i--;
                cout << cs[i].d * (X - x[i]) * (X - x[i]) * (X - x[i])
                        + cs[i].c * (X - x[i]) * (X - x[i])
                        + cs[i].b * (X - x[i])
                        + cs[i].a;
                return 0;
            }
        }
    }
}
