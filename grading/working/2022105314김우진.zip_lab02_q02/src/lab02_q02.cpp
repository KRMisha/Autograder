//
//  main.cpp
//  q7
//
//  Created by 김우진 on 2023/03/09.
//

#include <iostream>
using namespace std;
int main(){
    int a,b,sum,sub,mult,Div,rem;
    cout<<"Please enter two integer values:\n";
    cin>>a>>b;
    cout<<a<<"\t"<<b<<"\n";
    sum=a+b;
    sub=a-b;
    mult=a*b;
     Div=a/b;
    rem=a%b;
    cout<<a<<"+"<<b<<"="<<sum<<"\n";
    cout<<a<<"-"<<b<<"="<<sub<<"\n";
    cout<<a<<"*"<<b<<"="<<mult<<"\n";
    cout<<a<<"/"<<b<<"="<<Div<<"\n";
    cout<<a<<"%"<<b<<"="<<rem<<"\n";
}

