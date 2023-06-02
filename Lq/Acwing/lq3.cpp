#include <iostream>
#include<algorithm>
using namespace std;
int a[100005];
bool cmp(int a,int b){
	return a>b;
}

int main()
{
  // 请在此输入您的代码
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
    a[i]=i;
  }
//  sort(a+1,a+1+n,cmp);
  while(m--){
    int x,y;
    cin>>x>>y;
    if(x==1){
	 	sort(a+y,a+1+n);
    }else{
     	sort(a+1,a+1+y,cmp);
    }
  }
  for(int i=1;i<=n;i++){
    cout<<a[i]<<' ';
  }
  cout<<endl;
  return 0;
}
