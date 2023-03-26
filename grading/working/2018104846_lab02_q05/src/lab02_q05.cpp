#include <iostream>
using namespace std;

int main()
{
    double fah;
    double cel;

    cout << "Please enter Fahrenheit value: ";
    cin >> fah;

    cel = 5.0f / 5.0f * (fah - 32);

    cout << "Delsius value is " << cel << endl;

    return 0;
}