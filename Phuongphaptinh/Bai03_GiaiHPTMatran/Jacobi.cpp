#include <bits/stdc++.h>

using namespace std;

double a[1005][1005];
double x[1005], xo[1005];
double b[1005];
double T[1000][1000];


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
	int N = 100000;
	double TOL = 1e-3;
	cout << endl;
	
	while(it <= N)
	{
		for(int i = 1; i <= n; i++)
		{
			double sum = 0;
			for(int j = 1; j <= n; j++)
			{
				if(j != i)
					sum+=a[j][i]*xo[j];
			}
			x[i] = (1/a[i][i])*(b[i]-sum);
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
		cout << "Iteration no." << it << ": ";
		for(int p = 1; p <= n; p++)
		{
			cout << x[p] << " ";
		}	
		
		cout << endl;
		if(ok){
			cout << "Iterations: " << it << endl;
			cout << "Solution: \n";
			
			for(int p = 1; p <= n; p++)
			{
				cout << x[p] << " ";
			}
			cout << endl;
			
			//Error estimation
			double max_val = -1;
			double row_norm = 0;
			double norm_x = 0;
			for(int i = 1; i <= n; i++){
				norm_x = x[i] - xo[i];
				max_val = max(norm_x,max_val);
			}
			norm_x = max_val;
			max_val = -1;
			
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					if(i == j){
						T[j][i] = 0;
					}
					else{
						T[j][i] = -1*a[j][i]/(a[i][i]);
						row_norm += T[j][i];
						max_val = max(max_val,row_norm);
					}
				}
			}
			row_norm = max_val;
			
			double error = row_norm*norm_x/(1-row_norm);
			cout << "Estimated error: " << abs(error);
			return 0;
		}
		
		it++;
		for(int p = 1; p <= n; p++)
		{
			xo[p] = x[p];
		}
	}
	cout << "Max reached";	
}
