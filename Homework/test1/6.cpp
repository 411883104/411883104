#include<iostream>
#include<algorithm>
#include<iomanip> 
using namespace std;
class student
{
	public:
		void inScore();
		void ShowScore();
	private:
		int mId;
		double mMath;
		double mEnglish;
		double mProgramming;
};
void student::inScore()
{
	cin>>mId>>mMath>>mEnglish>>mProgramming;
}
void student::ShowScore()
{
	cout<<right<<mId<<setw(8)<<mMath<<setw(8)<<mEnglish<<setw(12)<<mProgramming<<endl;
}
int main()
{
	int n;
	cout<<"The number of student:";
	cin>>n;
	student *stu=new student[n];
	cout<<"mId"<<setw(8)<<"mMath"<<setw(12)<<"mEnglish"<<setw(16)<<"mProgramming"<<endl;
	for(int i=0;i<n;i++)
	{
		stu[i].inScore();
	}
	cout<<"mId"<<setw(8)<<"mMath"<<setw(12)<<"mEnglish"<<setw(16)<<"mProgramming"<<endl;
	for(int i=0;i<n;i++)
	{
		stu[i].ShowScore();
	}
	return 0;
}
