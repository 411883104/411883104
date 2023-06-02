#include <iostream>
#include<fstream>
using namespace std;
const int c=10000000;
int prime[c];
int vis[c];
ofstream out;
int main()
{
	out.open("prime.txt");
	int cnt=0;
	for(int i=2;i<=c;i++){
		if(vis[i]==0){
			prime[cnt++]=i;
			out<<i<<endl;
		}
		for(int j=0;j<cnt&&prime[j]*i<=c;i++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0){
				break;
			}
		}
	}
  return 0;
}
