#include <bits/stdc++.h>

using namespace std;

double a[1005][1005];
double x[1005];
int main()
{
	cout << "Matrix size: " << endl;
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
	for(int j = 1; j <= n; j++)
	{
		cin >> a[n+1][j];
	}
	
	for(int i = 1; i <= n-1; i++)
	{
		int p = 0;
		for(int l = i; l <= n; l++)
		{
			if(a[i][l] != 0)
			{
				p = l;
				break;
			}
		}
		if(p == 0)
		{
			cout << "No solution\n";
			return 0;
		}
		
		//swap
		if(p != i)
		{
			for(int k = 1; k <= n+1; k++)
			{
				double tmp;
				tmp = a[k][i];
				a[k][i] = a[k][p];
				a[k][p] = tmp;
			}
		}
		
		for(int j = i+1; j<= n; j++)
		{
			double m = a[i][j]/a[i][i];
			
			for(int k = 1; k <= n+1; k++)
			{
				a[k][j] -= m*a[k][i];
			}
		}
		
		if(a[n][n] == 0)
		{
			cout << "No solution\n";
			return 0;
		}
		
		
	}
	
	x[n] = a[n+1][n]/a[n][n];
	for(int i = n-1; i>= 1; i--)
	{
		double sum = 0;
		for(int j = i+1; j <= n; j++)
		{
			sum += a[j][i]*x[j];
		}
		x[i] = (a[n+1][i]-sum)/a[i][i];
	}

	cout << "Solution: \n";
	
	for(int i = 1; i <= n; i++)
	{
		cout << "x" << i << ": " << x[i] << endl;
	}
}
