#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const double c=1e-6;
int n,sum;
int arr1[110];
int arr2[110];
int x1[]= {0,0,1,-1};
int x2[]= {1,-1,0,0};
double fun(double x,double y) {
	double ans=0;
	for(int i=0; i<n; i++) {
		ans+=sqrt((x-arr1[i])*(x-arr1[i])+(y-arr2[i])*(y-arr2[i]));
	}
	return ans;
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>arr1[i]>>arr2[i];
	}
	double x=arr1[0],y=arr2[0],sum=1e9;
	double t=1;
	while(t>c) {
		int f=1;
		for(int i=0; i<4; i++) {
			double nx=x+x1[i]*t,ny=y+x2[i]*t;
			double v=fun(nx,ny);
			if(v<sum) {
				sum=v;
				x=nx;
				y=ny;
				f=0;
			}
		}
		if(f) {
			t*=0.9;
		}
	}
	cout<<setprecision(0)<<fixed<<sum<<endl;
	return 0;
}
