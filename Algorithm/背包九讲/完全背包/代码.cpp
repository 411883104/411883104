#include<iostream>
#include<algorithm>
using namespace std;
const int c=1005;
int bag[c];//һά��ʾ 
int main()
{
	int num,cap;//numΪ��Ʒ������capΪ��������� �� 
	cin>>num>>cap;
	//�����һ��ʼ���� ������Ϊ��ʱֵΪ�㡣 
	for(int i=1;i<=num;i++)
	{
		int vol,val;//vol��val�ֱ�Ϊ��i����Ʒ������ͼ�ֵ�� 
		cin>>vol>>val;//Ҳ�����������ʾ��Ʒ������ͼ�ֵ��
		for(int j=vol;j<=cap;j++)//��vol��ʼ��cap�����˶��vol������� 
		{
			//bag[i]��ʾ�������iʱ����ֵ�Ƕ��١� 
			bag[j]=max(bag[j],bag[j-vol]+val);
		}
	}
	cout<<bag[cap]<<endl;//������ֵ�� 
	return 0; 
}
