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
    int A,B,tmp;
    cout <<"please enter two integer values:"<< endl;
    cout << "A : ";
    cin >> A;

    cout << "B : ";
    cin >> B;
    
    tmp = A;
    A = B;
    B = tmp;
    
    cout << "value of A is : "<< A << endl;
    cout << "value of B is : "<< B << endl;
    
    
    return 0;
}


