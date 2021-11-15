#include<iostream>
#include<algorithm>
using namespace std;
const int c=2000005;
int arr[c];
int main() {
	int n,m;
	while(~scanf("%d%d",&n,&m)) {

		for(int i=1; i<=n; i++) {
			cin>>arr[i];
		}
		while(m--) {
			char z;
			scanf("%c",&z);
			int x,y;
			if(z=='Q') {
				scanf("%d%d",&x,&y);
				int maxx=0;
				for(int i=x; i<=y; i++) {
					if(arr[i]>maxx)
						maxx=arr[i];
				}
				printf("%d\n",maxx);
			}
			if(z=='U') {
				scanf("%d%d",&x,&y);
				arr[x]=y;
			}
		}
	}
	return 0;
}
