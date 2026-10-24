#include <iostream>

class Triangle{
	private:
		double totalAngle, angleA, angleB, angleC;
	public:
		Triangle(double A, double B, double C);
		void setAngles(double A, double B, double C);
		const bool validateTriangle();
};
int main(){
    
    Triangle setl(40,30,110);
    if(setl.validateTriangle()){
    	std::cout<<"the shape is a valid triangle \n";
   }else{
   	std::cout<<"the shape is not a valid triangle \n";
   }
	}
Triangle::Triangle(double A, double B, double C){
	angleA = A;
	angleB = B;
	angleC = C;
	totalAngle = A+B+C;
}

void Triangle::setAngles(double A, double B, double C){
	angleA= A;
	angleB = B;
	totalAngle = A+B+C;
}
const bool Triangle::validateTriangle(){
	return(totalAngle <= 180);
}

