#include <iostream>
using namespace std;

float c(float f);
float f(float c);


int main() {
    float f;
    cout<<"Please enter Farenheit value: "<<endl;
    cin>>f;
    float result=5.0/9.0*(f-32);
    cout<<"Celcius value is "<<result<<endl;

}
