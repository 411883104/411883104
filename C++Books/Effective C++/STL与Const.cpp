#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(5);
	vector<int>::iterator it=v.begin();//������
	//��constԼ��it1��ָ���ܱ䣬��ָ�ı�����ֵ���Ա䣬�൱�� *const 
	const vector<int>::iterator it1=v.begin();	 
	//��const_iteratorԼ����ָ�ı�����ֵ���ɸı䣬�൱��const* 
	vector<int>::const_iterator it2=v.begin();
	//it1=v.end();//����
	//*it2=1; //���� 
	const vector<int>::const_iterator it3=v.begin();//ָ���ָ���ָ����ָ���ֵ���ܱ� 
} 
