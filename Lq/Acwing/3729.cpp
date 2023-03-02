#include<iostream>
#include<cstring>
using namespace std;

int add[200005];
int arr[200005];

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		memset(arr,0,(n+1)*4);
		for(int i=1;i<=n;i++){
			cin>>add[i];
		}
		for(int i=1;i<=n;i++){
			int len;
			if(add[i]>i){
				len=i;
			}else{
				len=add[i];
			}
			arr[i-len+1]+=1;
			arr[i+1]-=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=arr[i];
			cout<<(ans>1?1:ans)<<" ";
		}
		cout<<endl;
	}
} 
