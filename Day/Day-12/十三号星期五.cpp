#include<iostream>
#include<algorithm>
using namespace std;
int month[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
void bo(int n) {
	if((n%4==0&&n%100!=0)||(n%100==0&&n%400==0)) {
		month[2]=29;
	}
}
int sum[7];
int main() {
	int n;
	cin>>n;
	int k=0;
	for(int i=0; i<=n; i++) {
		bo(1900+i-1);
		for(int j=0; j<=11; j++) {
			k+=(month[j]+13);
			sum[k%7]++;
			k-=13;
			if(j==11)
			{
				k+=31;
			}
		}
	}
	
	cout<<sum[6]<<' '<<sum[0]<<' '<<sum[1]<<' '<<sum[2]<<' '<<sum[3]<<' '<<sum[4]<<' '<<sum[5]<<endl;
	return 0;
}
