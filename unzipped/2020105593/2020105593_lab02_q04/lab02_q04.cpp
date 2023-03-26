#include <iostream>
using namespace std;
int main(){
    int a, b, c;
    
    cout << "a : ";
    cin >> a; 
    cout << "b : ";
    cin >> b;
    c = a;
    a = b;
    b = c;
    cout << "value of a is : "<<a <<endl; 
    cout <<"value of b is : " <<b;
    return 0;
}