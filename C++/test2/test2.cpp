#include<iostream>
using namespace std;
class matrix
{
	private:
		int arr[3][3];
	public:
		matrix& operator+(matrix& a)
		{
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					arr[i][j]+=a.arr[i][j];
				}
			}
			return *this;
		}
		friend istream& operator>>(istream&,matrix&);
		friend ostream& operator<<(ostream&,matrix&);
};
istream& operator>>(istream& input,matrix& a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			input>>a.arr[i][j];
		}
	}
	return input;
}
ostream& operator<<(ostream& output,matrix& a)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			output<<a.arr[i][j]<<' ';
		}
		output<<endl; 
	}
	return output; 
}
int main()
{
	matrix A,B;
	cin>>A>>B;
	A=A+B;
	cout<<endl;
	cout<<A<<endl;
	return 0;
} 
