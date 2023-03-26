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
    int x, y, sum, mult;
    float div;
    cin >> x >> y;
    sum = x+y;
    mult = x*y;
    div = ((float)x)/((float)y);
    
    cout<< x << '\t' << y << endl;
    cout<< "x + y = " << sum << endl;
    cout<< "x * y = " << mult << endl;
    cout<< "x / y = " << div << endl;
    
    
    return 0;
}


