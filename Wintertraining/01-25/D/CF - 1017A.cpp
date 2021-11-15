#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
const double pi=3.1415927;
typedef long long ll;
struct student
{
	int sum;
	int id;
	int a;
	int b;
	int c;
	int d;
};
bool cmp(student a,student b);

int main()
{
	student stu[1005];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		stu[i].id=i;
		cin>>stu[i].a>>stu[i].b>>stu[i].c>>stu[i].d;
		stu[i].sum=stu[i].a+stu[i].b+stu[i].c+stu[i].d;
	}
	sort(stu+1,stu+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(stu[i].id==1)
			cout<<i<<endl;
	}
	return 0; 
} 
bool cmp(student a,student b)
{
	if(a.sum!=b.sum)
	{
		return a.sum>b.sum;
	}
	else
	{
		return a.id<b.id;
	}
}
