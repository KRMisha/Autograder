#include <iostream>
using namespace std;

int main() {

    double fahrenheit, celcius;

    cout << "Please enter the Fahrenheit value : ";
    cin >> fahrenheit;
    
    celcius =  5/9 * (fahrenheit - 32 );

    cout << "Celcius value is " << celcius << endl;

}