#include <iostream>
using namespace std;

double convertTemp(double kelvin);

int main() {
    double k = 300.0;
    double f = convertTemp(k);
    
    cout << "Fahrenheit is " << f << endl;
    return 0;
}

double convertTemp(double kelvin) {
	
    double fahrenheit = (kelvin - 273.15) * 1.8 + 32.0;
    return fahrenheit;
}

