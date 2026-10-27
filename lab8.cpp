#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef double (*uf)(double, double, int&);
void tabl(double, double, double, double, uf);
double y(double, double, int&);
double s(double, double, int&);

int main()
{
    // Данные для 3 варианта
    double a = -0.9, b = 0.9, h = 0.2, eps = 0.001;

    // Шапка для точной функции
    cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k\n" << endl;
    tabl(a, b, h, eps, y);
    cout << endl;

    // Шапка для суммы ряда
    cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k\n" << endl;
    tabl(a, b, h, eps, s);

    return 0;
}

void tabl(double a, double b, double h, double eps, uf fun)
{
    int k = 0;
    double sum;
    for (double x = a; x <= b + 1e-9; x += h)
    {
        sum = fun(x, eps, k);
        cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
    }
}
double y(double x, double eps, int& k)
{
    k = 0; 
    return pow(1.0 + x, 1.0 / 3.0); 
}

double s(double x, double eps, int& k)
{
    if (fabs(x) < 1e-9) {
        k = 1;
        return 1.0;
    }

    double sum = 1.0; 
    double a = 1.0;   
    k = 1;

    while (fabs(a) > eps)
    {
        double factor = -x * (3.0 * k - 4.0) / (3.0 * k);
        a *= factor;

        sum += a;
        k++;
    }
    return sum;
}

