#include <iostream>

using namespace std;

int main()
{
    float input;

    cout << "Please enter Fahrenheit value: ";
    cin >> input;

    cout << "Celsius value is " << 5.0f / 9.0f * (input - 32.0f) << endl;

    return 0;
}