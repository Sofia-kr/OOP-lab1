#include <iostream>
#include <cmath>

using namespace std;


class ZavdClass
{
public:
    double x, y, z, b;
    double calculate_a(double x, double y, double z, double b) {
        double A1 = z / pow(x, 2) + pow(sin(b), 2);
        double A2 = fabs((pow(x, 2) + y) / (z + pow(x, 3) / 3));
        double A3 = log(fabs(pow(x, 2) + z));
        return (pow(y, 2) + A1) / (A2 - A3);
    }


    double calculate_b(double x, double y, double z) {
        double B1 = fabs(((x + y) / pow(fabs(z), 0.6)) + pow(sin((x + pow(z, 2)) / (2 * x + y)), 2));
        double B2 = pow(B1, 1 / 3);
        double B3 = z * exp((pow(x, 2) - y) / (1 + z));
        return B2 - B3;
    }
};


int main() {
    ZavdClass zc;
    setlocale(LC_ALL, "Ukrainian");
    double x = 0.48 * 4;
    double y = 0.47 * 4;
    double z = -1.32 * 4;
    double b = 0;

    double a = zc.calculate_a(x, y, z, b);
    double c = zc.calculate_b(x, y, z);

    cout << "Значення a: " << a << endl;
    cout << "Значення b: " << c << endl;
    cout << "|   a    |" << "|    b   |" << endl;
    for (double n = -1; n < 1; n = n + 0.2)
    {
        double b = zc.calculate_b(n, y, z);
        zc.calculate_a(n, y, z, zc.b);
        double a1 = zc.calculate_a(n, y, z, zc.b);
        double c1 = zc.calculate_b(n, y, z);
        cout << "| " << a1 << "|" << "| " << c1 << "|" << endl;
    }

    return 0;
}
