#include <iostream>
using namespace std;

int main() {
    int temp_F;
    cout << "Please enter Fahrenheit value: ";
    cin >> temp_F;
    float temp_C = (temp_F - 32) * (5.0f / 9.0f);
    cout << "Celsius value is " << temp_C;
}
