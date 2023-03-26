#include <iostream>
using namespace std;

int main () {
    cout << "Please enter two integer values:" << endl;
    int a, b, temp;
    cout << "A : " ;
    cin >> a;
    cout << "B : ";
    cin >> b;
    temp = a;
    a = b;
    b = temp;
    cout << "value of A is : " << a << endl;
    cout << "value if B is : " << b ;

}