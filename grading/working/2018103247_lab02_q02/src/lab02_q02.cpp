#include <iostream>

using namespace std;

int main()
{
    int x, y, sum, sub, mult, rem;
    float div;
    cout << "Please enter two integer values : ";
    cin >> x >> y;
    sum = x + y;
    sub = x - y;
    mult = x * y;
    div = x / y;
    rem = x % y;
    cout << "x + y = " << sum << endl;
    cout << "x - y = " << sub << endl;
    cout << "x * y = " << mult << endl;
    cout << "x / y = " << div << endl;
    cout << "x % y = " << rem << endl;
}