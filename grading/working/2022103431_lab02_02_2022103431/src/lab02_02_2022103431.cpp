#include <iostream>
using namespace std;

int main() {
    int x,y,sum,sub,mul,d;
    float div;
    cin>>x>>y;
    sum=x+y;
    sub=x-y;
    mul=x*y;
    div=(float)x/y;
    d=x%y;
    cout<<x<<"+"<<y<<"="<<sum<<endl;
    cout<<x<<"-"<<y<<"="<<sub<<endl;
    cout<<x<<"*"<<y<<"="<<mul<<endl;
    cout<<x<<"/"<<y<<"="<<div<<endl;
    cout<<x<<"%"<<y<<"="<<d<<endl;

}