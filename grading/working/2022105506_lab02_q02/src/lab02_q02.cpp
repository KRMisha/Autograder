/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int A,B;
    cout << "Please enter two integer values:" << endl;
    cin >> A >> B;
    
    
    cout<< A << "+" << B << "=" << A + B << endl;
    cout<<  A << "-" << B << "=" << A - B << endl;
    cout<<  A << "*" << B << "=" <<A * B << endl;
    cout<<  A << "/" << B << "=" <<((float)A) / ((float)B) << endl;
    cout<<  A << "%" << B << "=" <<A % B << endl;
    
    
    return 0;
}


