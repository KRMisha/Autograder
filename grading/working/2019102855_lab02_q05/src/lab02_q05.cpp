#include <iostream>
using namespace std;

int main() {
    int Fah;
    cout << "Please enter Fahrenheit value: ";
    cin >> Fah;
    float Cel = 5.0/9.0 * (float(Fah) - 32);
    cout << "Celsius value is " << Cel << endl;
}