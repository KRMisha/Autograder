#include <iostream>
#define endl '\n'
using namespace std;

int a,b;

void Swap(int &a, int &b){
    int tmp = b;
    b = a;
    a = tmp;
}

int main(){

    cout << "Please enter two integer values:";
    cin >> a >> b;
    cout << "A : " << a << endl;
    cout << "B : " << b << endl;
    Swap(a,b);
    cout << "value of A is : " << a << endl;
    cout << "value of B is : " << b;

    return 0;
}