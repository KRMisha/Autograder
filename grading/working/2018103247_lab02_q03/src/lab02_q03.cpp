#include <iostream>

using namespace std;

int main()
{
    int i1 = 2, i2 = 5, i3 = -3, a = 3, b = 4, c = 5;
    double d1 = 2.0, d2 = 5.0, d3 = -0.5;

    cout << i1 + (i2 * i3) << endl;
    cout << i1 * (i2 + i3) << endl;
    cout << i1 / (i2 + i3) << endl;
    cout << i1 / i2 + i3 << endl;
    cout << a + b + c / a << endl;
    cout << (a + b + c) / a << endl;
    cout << d1 + (d2 * d3) << endl;
    cout << d1 + d2 * d3 << endl;
    cout << d1 / d2 - d3 << endl;
    cout << d1 / (d2 - d3) << endl;
    cout << d1 + d2 + d3 / a << endl;
    cout << (d1 + d2 + d3) / a << endl;
}