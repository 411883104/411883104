#include<iostream>
using namespace std;
class score
{
	private:
		int num;
		double math;
		double english;
		double programming;
		double average;
	public:
		void inscore()
		{
			cin>>num>>math>>english>>programming;
			average=(math+english+programming)/3;
		}
		void showscore()
		{
			cout<<num<<"\t"<<math<<"\t"<<english<<"\t"<<programming<<"\t"<<average<<endl;
		}
};
int main()
{
	int n;
	cin>>n;
	score*student=new score[n];
	cout<<"num"<<"\t"<<"math"<<"\t"<<"english"<<"\t"<<"programming"<<endl;
	for(int i=0;i<n;i++)
	{
		student[i].inscore();
	}
	cout<<"num"<<"\t"<<"math"<<"\t"<<"english"<<"\t"<<"programming"<<"\t"<<"average"<<endl;
	for(int i=0;i<n;i++)
	{
		student[i].showscore();
	} 
	return 0;
}
