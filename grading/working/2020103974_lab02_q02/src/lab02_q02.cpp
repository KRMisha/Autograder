#include <iostream>
using namespace std;

int main(){
    int A;
    int B;

    cout << "Please enter two integer values: ";
    cin >> A; cin >> B;

    cout << "A + B = " << " " << A + B << endl;
    cout << "A - B = " << " " << A - B << endl;
    cout << "A * B = " << " " << A * B << endl; 
    cout << "A / B = " << " " << float(A) / float(B) << endl;
    cout << "A % B = " << " " << A % B << endl;

    return 0;
    
}
