#include <iostream>
using namespace std;

int main(){
    float F;

    cout << "Please enter Fahrenheit value: "; cin >> F;
    cout << "Celcius value is " << (5.0f / 9.0f) * (F - 32);

    return 0;
}
