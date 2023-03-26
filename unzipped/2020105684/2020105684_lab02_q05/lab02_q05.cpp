#include <iostream>

using namespace std;

int main()
{
    double fahr, cels;
    cout << "Please enter Fahrenheit value: ";
    cin >> fahr;
    cels = (fahr - 32) * (5.0 / 9.0);
    cout << "Celsius value is " << cels << endl;
}