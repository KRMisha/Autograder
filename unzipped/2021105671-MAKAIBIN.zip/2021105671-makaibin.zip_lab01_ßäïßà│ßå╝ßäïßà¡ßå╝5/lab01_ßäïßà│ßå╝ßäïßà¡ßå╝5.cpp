#include<iostream>
using namespace std;
int main()
{
    float a;
    cout << "please enter Fahrenheit value " << endl;
    cin >> a;
    float b;
    b = 5 * (a - 32) / 9;
    cout << "celsius value is= : " << b << endl;
    return 0;
}
