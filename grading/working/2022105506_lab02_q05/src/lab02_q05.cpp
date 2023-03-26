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
    float A,B;
    
    cout<< "please enter Fahrenheit value: ";
    cin >> A;
    
    B = 5.0/9.0*(A - 32);
    
    cout <<"Celsius avlue is "<< B;
    
    return 0;
}


