#include <iostream>

using namespace std;

int main() {
    float F_value, C_value;
    cout << "Please enter Fahrenheit value: ";
    cin >> F_value;
    C_value = (5.0f/9.0f)*(F_value-32);
    cout << "Celsius value is " << C_value << endl;
}