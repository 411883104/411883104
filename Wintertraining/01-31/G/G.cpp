#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string str,str1,str2;
	cin>>str;
	str1=str.substr(0,2);
	str2=str.substr(2,2);
	string s1="12",s2="01";
	if((str2<=s1&&str2>=s2)||(str1>=s2&&str1<=s1))
	{
		if((str2<=s1&&str2>=s2)&&!(str1>=s2&&str1<=s1))
			cout<<"YYMM"<<endl; 
		if(!(str2<=s1&&str2>=s2)&&(str1>=s2&&str1<=s1))
			cout<<"MMYY"<<endl;
		if((str2<=s1&&str2>=s2)&&(str1>=s2&&str1<=s1))
			cout<<"AMBIGUOUS"<<endl; 
	}
	else
	{
		cout<<"NA"<<endl;
	}
	return 0;
}
