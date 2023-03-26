#include <iostream>

using namespace std;

int main()
{
    int x = 5, y = 9, z = 32, F;
    float C;

    cout << "Please enter Fahrenheit value : ";
    cin >> F;

    C = float(x) / float(y) * (F - z);

    cout << "Celsius value is : " << C << endl;
}