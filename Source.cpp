#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);

int main()
{
	double Pi = 4 * atan(1.);
	double xp, xk, x, dx, eps, res = 0, a = 0, R = 0, s = 0;
	int n = 0;
	cout << "xp = "; cin >> xp;
	cout << "xk = "; cin >> xk;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;
	cout << fixed;
	cout << "-----------------------------------------" << endl;
	cout << "|" << setw(7) << "x" << " |"
		<< setw(10) << "arctg(x)" << " |"
		<< setw(10) << "S" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------" << endl;
	x = xp;
	while (x <= xk)
	{
		s = S(x, eps, n, s);
		res = -Pi / 2 + s;
		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(10) << setprecision(5) << atan(x) << " |"
			<< setw(10) << setprecision(5) << res << " |"
			<< setw(5) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-----------------------------------------" << endl;
	return 0;
}
double S(const double x, const double eps, int& n, double s)
{
	n = 0;
	double a = -1 / x;
	s = a;
	do {
		n++;
		a = A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
	return s;
}
double A(const double x, const int n, double a)
{
	double R = (1. - 2 * n) / ((2 * n + 1) * pow(x, 2));
	a *= R;
	return a;
}
