#include <iostream>
#define endl '\n'
using namespace std;

int a,b;

int main(){

    cin >> a >> b; // input
    cout << "Please enter two integer values:";
    cout << a << "+" << b << "=" << a+b << endl;
    cout << a << "-" << b << "=" << a-b << endl;
    cout << a << "*" << b << "=" << a*b << endl;
    cout << a << "/" << b << "=" << a/b << endl;
    cout << a << "%" << b << "=" << a%b;

    return 0;
}