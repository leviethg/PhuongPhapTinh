#include <iostream>
using namespace std;

int main() {
    double x00, x01, x02, f0, f1, f2, h;

    // Input values
    cout << "Enter h: ";
    cin >> h;
    
    cout << "Enter : x00 = "; cin >> x00;
    cout << "Enter : f(x00) = "; cin >> f0;
    cout << "Enter : x01 = "; cin >> x01;
    cout << "Enter : f(x01) = "; cin >> f1;
    cout << "Enter : x02 = "; cin >> x02;
    cout << "Enter : f(x02) = "; cin >> f2;
	double res = (f0 - 2 * f1 + f2)/(h * h);
    // Output the results
    cout << "Dao ham cap 2 tai x0 la : " << res;
    return 0;
}

