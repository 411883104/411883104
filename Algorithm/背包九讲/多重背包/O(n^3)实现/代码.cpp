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
		int vol,val,sum;//vol��val�ֱ�Ϊ��i����Ʒ������ͼ�ֵ��sum��ʾ����Ʒ�ж��ټ��� 
		cin>>vol>>val>>sum;//Ҳ�����������ʾ��Ʒ���������ֵ��������
		for(int j=cap;j>=0;j--) 
		{
			for(int k=1;k<=sum;k++)//�����Ʒ���ӡ� 
			{
				if(j>=k*vol)
				{
					//״̬ת�Ʒ��̣� 
					bag[j]=max(bag[j],bag[j-k*vol]+k*val);
				}
			}
		}
	}
	cout<<bag[cap]<<endl;//������ֵ�� 
	return 0; 
}
