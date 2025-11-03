#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

// we'll integrate: y = x^2
double original (double x) {
    return x * x;
}

// integral: F(x) = x^3/3
double integral(double x) {
    return (x * x * x) / 3.0;
}

// derivative: y' = 2x
double derivative(double x) {
    return 2 * x;
}

//for float
double rectangle_integral(int n) {
    float step = 1.0 / n;
    float sum = 0.0;
    for (int i = 1; i <= n; i++) {
        float x = i * step;
        sum += original(x) * step;
    }

    return sum;
}

// same but for double
double rectangle_integral_double(int n) {
    double step = 1.0 / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double x = i * step;
        sum += original(x) * step;
    }

    return sum;
}

int main() {

    cout << fixed;
    cout.precision(2);


    ofstream data("analytic.csv");
    ofstream result("integration.csv");

    double area = integral(1) - integral(0);

    for (int i = 0; i <= 100; i++) {
        double x = i / 100.0;
        data << x << "," << original(x) << "," << derivative(x) << "," << integral(x) << endl;
    }

    for (unsigned long long int i = 10; i<=10000000000000; i*=10) {
        double step = 1.0 / i;
        float area_float = rectangle_integral(i);
        double area_double = rectangle_integral_double(i);

        float error_float = fabs(area_float - area);
        double error_double = fabs(area_double - area);

        result << i << "," << step << "," << area_float << "," << area_double << "," << area << "," << error_float << "," << error_double << endl;

    }

    data.close();
    result.close();


    return 0;
}
