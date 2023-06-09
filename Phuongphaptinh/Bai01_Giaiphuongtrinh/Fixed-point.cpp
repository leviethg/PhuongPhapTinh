#include <bits/stdc++.h>

using namespace std;

double f(double x)
{
    return -(692*pow(x,5)+pow(x,4)+pow(x,3)+pow(x,2)*1293-123);
}

int main()
{
    double p0; cin >> p0;

    double TOL = 1e-6;
    int N = 100;
    
    int i = 1;
    //function
    while(i <= N)
    {
        double p = f(p0);
        cout << p << endl;
        if(abs(p-p0) < TOL)
        {
            cout << p << endl;
            cout << i << endl;
            return 0;
        }
        i++;
        p0 = p;
    }
    cout << "Can't solve for X";
}
