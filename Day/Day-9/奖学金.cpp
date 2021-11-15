#include<iostream>
#include<algorithm>
using namespace std; 
struct student {
	int id;
	int a;
	int b;
	int c;
	int sum;
};
bool cmp(student x,student y) {
	if(x.sum!=y.sum)
		return x.sum>y.sum;
	else if(x.a!=y.a)
		return x.a>y.a;
	else
		return x.c>y.c;
}
int main() {
	student stu[310];
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		stu[i].id=i;
		cin>>stu[i].a>>stu[i].b>>stu[i].c;
		stu[i].sum=stu[i].a+stu[i].b+stu[i].c;
	}
	sort(stu+1,stu+n+1,cmp);
	for(int i=1;i<=5;i++)
	{
		cout<<stu[i].id<<' '<<stu[i].sum<<endl;
	}
	return 0;
}
