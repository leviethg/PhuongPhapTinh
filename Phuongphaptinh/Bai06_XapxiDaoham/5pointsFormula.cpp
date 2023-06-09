#include <iostream>
using namespace std;

int main() {
    double x[5], f[5], h;

    // Input values
    cout << "Enter h: ";
    cin >> h;
    
    for (int i = 0; i < 5; ++i) {
    	cout << "Enter x" << i << " : ";
    	cin >> x[i];
    	cout << "Enter f(x" << i << ") : ";
    	cin >> f[i];
	}

    
    // Calculate derivatives using the formulas
    double midpointDerivative = (f[0] - 8 * f[1] + 8 * f[3] - f[4]) / (12 * h);
    double endpointDerivative = (-25 * f[0] + 48 * f[1] - 36 * f[2] + 16 * f[3] - 3 * f[4]) / (12 * h);

    // Output the results
    cout << "Using Five-Point Midpoint Formula, f'(x2) = " << midpointDerivative << endl;
    cout << "Using Five-Point Endpoint Formula, f'(x0) = " << endpointDerivative << endl;

    return 0;
}

