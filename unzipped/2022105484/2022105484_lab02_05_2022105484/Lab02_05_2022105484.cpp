# include <iostream>

using namespace std;

int main(){
	int F,C;
	cout << "please enter Fahrenheit value: ";
	cin >> F;
	
	C = float(5)/9*(F-32);
	
	cout << "Celsius value is " << C;
}
