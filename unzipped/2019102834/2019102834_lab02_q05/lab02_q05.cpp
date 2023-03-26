#include <iostream>
using namespace std;
int main() {
    float fah,cel;

    cout<<"Please enter Fahrenheit value: "<<endl;
    cin>>fah;
    cel=5.0/9.0*(fah-32);
    cout<<"Celcius value is"<<cel<<endl;
}