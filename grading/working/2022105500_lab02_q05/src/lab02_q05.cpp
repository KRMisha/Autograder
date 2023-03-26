//
//  main.cpp
//  sol_extend_5
//
//  Created by 최우석 on 2023/03/09.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    double Fahrenheit, Celsius;
    cout << "Please enter Fahenheit value: ";
    cin >> Fahrenheit;
    Celsius = 5.0/9.0 * (Fahrenheit - 32);
    cout << "Celsius value is " << Celsius;
    return 0;
}
