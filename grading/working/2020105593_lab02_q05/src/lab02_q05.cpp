#include <iostream>
using namespace std;
double a, b;
int main(){
    cout<<"Please enter Fahrenheit value: ";
    cin >> a;
    b = 5.0/9.0 * (a-32);
    cout <<"Celsius value is "<<b;
    return 0;
}