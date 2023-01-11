#include<iostream>
#include<iomanip>
#include<vector>

using namespace std; 

int arr[25]={0};
std::vector<int>v;

void dfs(int cnt,int n,int r,int maxx){
	if(cnt==r){
		for(int i=0;i<v.size();i++){
			cout<<setw(3)<<v[i];
		}
		cout<<endl;
		return;
	}
	for(int i=maxx;i<=n;i++){
		if(arr[i]==0){
			v.push_back(i);
			arr[i]=1;
			dfs(cnt+1,n,r,i+1);
			arr[i]=0;
			v.pop_back();
		}
	}
}


int main(){
	int n,r;
	cin>>n>>r;
	
	dfs(0,n,r,1);	
    
}
