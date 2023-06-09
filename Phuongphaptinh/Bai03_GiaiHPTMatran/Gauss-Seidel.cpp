#include <bits/stdc++.h>

using namespace std;

double a[1005][1005];
double x[1005], xo[1005];
double b[1005];


int main()
{
	cout << "Size of matrix: \n";
	int n; cin >> n;
	cout << "A matrix: " << endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> a[j][i];
		}
	}
	
	cout << "B matrix: " << endl;
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	
	cout << "X approximation: " << endl;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i];
		xo[i] = x[i];
	}
	
	
	int it = 1;
	int N = 100;
	double TOL = 1e-6;
	
	while(it <= N)
	{
		for(int i = 1; i <= n; i++)
		{
			double sum_1 = 0;
			double sum_2 = 0;
			for(int j = 1; j <= i-1; j++)
			{
				sum_1 += a[j][i]*x[j];
			}
			for(int j = i+1; j <= n; j++)
			{
				sum_2 += a[j][i]*xo[j];
			}
			
			x[i] = (1/a[i][i])*(b[i]-sum_1-sum_2);
		}
		
		bool ok = true;
		for(int k = 1; k <= n; k++)
		{
			if(abs(x[k]-xo[k]) >= TOL)
			{
				ok = false;
				break;
			}
		}
		if(ok){
			cout << "Iterations: " << it << endl;
			cout << "Solution: \n";
			
			for(int p = 1; p <= n; p++)
			{
				cout << "x" << p << ": " << x[p] << endl;
			}
			return 0;
		}
		
		it++;
		
		for(int p = 1; p <= n; p++)
		{
			xo[p] = x[p];
		}
	}
	cout << "No solution\n";
}

