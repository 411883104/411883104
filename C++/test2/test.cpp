#include<iostream>
using namespace std;
class student
{
	public:
		int id;
		double math;
		friend istream& operator>>(istream&,student&);
		friend ostream& operator<<(ostream&,student&);
};
istream& operator>>(istream& input,student& a)
{
	input>>a.id>>a.math;
	return input;
}
ostream& operator<<(ostream& output,student& a)
{
	output<<a.id<<"\t"<<a.math<<endl;
	return output;
}
int main()
{
	student stu;
	cin>>stu;
	cout<<stu<<endl; 
	return 0;
} 
