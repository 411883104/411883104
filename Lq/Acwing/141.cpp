#include<iostream>
#include<cstring>
using namespace std;

int nextval[1000005];

int n;
string s;
void next()
{
	int j=1,k=0;
	while(j<=n) {
		if(k==0||s[j-1]==s[k-1]) {
			nextval[++j]=++k;
		} else {
			k=nextval[k];
		}
	}
}

int main()
{
	while(cin>>n&&n) {
		cin>>s;
		next();
		for(int i=2; i<=n+1; i++) {
//			cout<<nextval[i]<<endl;
			if(nextval[i]>=2) {
				cout<<i-1<< ' '<<nextval[i]<<endl;
			}
		}
		memset(nextval,0,n*4);
	}
}
