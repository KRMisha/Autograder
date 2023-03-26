#include <iostream>
using namespace std;

int main()
{
    int a ;
    int b;
    int temp;
    cout << "Please enter the length of the rectangle : ";
    cin >> a;
    cout << "Please enter the length of the rectangle : ";
    cin >> b;
    temp = a;
    a = b;
    b = temp;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
