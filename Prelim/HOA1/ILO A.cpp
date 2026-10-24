#include <iostream>
 int sumOfTwoNum(int fNum, int sNum);
 
 int main(){
 	
 	std::cout<<"the sum of the two numbers:"<<sumOfTwoNum(5,4);
 	
 }
 int sumOfTwoNum(int fNum, int sNum){
 	int sum = fNum + sNum;
 	
 	return sum;
 	
 }
 
 void sumOfThreeNum(int fNum, int sNum, int tNum){
 	std::cout<<"sum:"<<fNum+sNum+tNum<<std::endl;
 }
    
