#include<iostream>
#include<cmath>
using namespace std;

int main(){
	for(double x=1;x<=13333333;x+=1){
		double dx=-(x*x/23333333)*log2(x/23333333);
		double dy=-((23333333-x)*(23333333-x)/23333333)*log2((23333333-x)/23333333);
		if(fabs(dx+dy-11625907.5798)<0.0001){
			cout<<(int)x<<endl;
		}
	}
} 
