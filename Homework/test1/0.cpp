#include<iostream>
#include<iomanip>
using namespace std;
struct score
{
	int num;
	double math;
	double english;
};
void inscore(score& a) 
{
	cin>>a.num>>a.math>>a.english;
} 
double showscore(const score a)
{
	cout<<a.num<<"\t"<<a.math<<"\t"<<a.english<<"\t";
	return (a.num+a.math+a.english)/3; 
}
int main()
{
	int n;//学生数
	cin>>n;
	score*student=new score[n];//动态内存分配
	cout<<"num"<<"\t"<<"math"<<"\t"<<"english"<<endl;
	for(int i=0;i<n;i++)
	{
		inscore(student[i]);
	}
	cout<<"num"<<"\t"<<"math"<<"\t"<<"english"<<"\t"<<"average"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<showscore(student[i])<<endl;
	}
	return 0;
} 
