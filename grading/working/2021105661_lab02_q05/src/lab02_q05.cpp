#include <iostream>
using namespace std;

int main () {
    int a;
    cout << "Please enter Fahrenheit value : " ;
    cin >> a;
    a = 5/9 * (a - 32);
    cout << "Celsius value is " << a;
}