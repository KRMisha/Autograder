#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cout << " Please enter two integer values : " << endl;
    cout << "A : ";
    cin >> A;
    cout << "B : ";
    cin >> B;

    C = A;
    A = B;
    B = C;

    cout << "Value of A is " << A << endl;
    cout << "Value of B is " << B << endl;
}