# include <iostream>
using namespace std;

int main()
{
	double F, C;
	cin >> F;
	C = (float(5) / float(9)) * (F - 32);

	cout << "Please enter Fahrenheit value : " << F << endl;
	cout << "Celsius value is " << C << endl;

}