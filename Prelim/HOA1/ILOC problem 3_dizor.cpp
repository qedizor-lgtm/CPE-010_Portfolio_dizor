#include <iostream>
#include <cmath>

using namespace std;

double calcDistance(double x1, double y1, double x2, double y2);

int main() {
    double result = calcDistance(1.0, 2.0, 4.0, 6.0);
    
    cout << "distance: " << result << endl;
    
    return 0;
}

double calcDistance(double x1, double y1, double x2, double y2) {
    double xDiff = x2 - x1;
    double yDiff = y2 - y1;
    
    double distance = sqrt((xDiff * xDiff) + (yDiff * yDiff));
    return distance;
}

