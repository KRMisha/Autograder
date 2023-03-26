#include <iostream>

using namespace std;

int main () {
    int cTemp, fTemp;
    cout << "Please enter Fahrenheit value :";
    cin >> fTemp;
    cTemp = (float)5/9*(fTemp -32);
    cout << "Celsius value is " << cTemp; 
}