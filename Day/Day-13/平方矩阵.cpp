#include<iostream>
#include<algorithm>
using namespace std;
const int c=110;
int arr[c][c];
int main() {
	int n;
	while(cin>>n&&n) {
		for(int i=1; i<=n; i++) {
			for(int j=i,k=1; j<=n; j++,k++) {
				arr[i][j]=k;
				arr[j][i]=k;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		cout<<endl;
	}
	return 0;
}
