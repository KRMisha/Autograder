#include <iostream>
using namespace std;

int i1=2;
int i2=5;
int i3=-3;
double d1=2.0;
double d2=5.0;
double d3=-0.5;

int main() {
    cout<<i1+(i2*i3)<<endl;
    cout<<i1*(i2+i3)<<endl;
    cout<<i1/(i2+i3)<<endl;
    cout<<i1/i2+i3<<endl;
    cout<<3+4+5/3<<endl;
    cout<<(3+4+5)/3<<endl;
    cout<<d1+(d2*d3)<<endl;
    cout<<d1+d2*d3<<endl;
    cout<<d1/d2-d3<<endl;
    cout<<d1/(d2-d3)<<endl;
    cout<<d1+d2+d3/3<<endl;
    cout<<(d1+d2+d3)/3<<endl;

    
}