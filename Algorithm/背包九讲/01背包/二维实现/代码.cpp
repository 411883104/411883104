#include<iostream>
#include<algorithm>
using namespace std;
const int c=1005;
int bag[c][c];//��ά��ʾ 
int main()
{
	int num,cap;//numΪ��Ʒ������capΪ��������� �� 
	cin>>num>>cap;
	//�����һ��ʼ������ 
	for(int i=1;i<=num;i++)
	{
		int vol,val;//vol��val�ֱ�Ϊ��i����Ʒ������ͼ�ֵ�� 
		cin>>vol>>val;//Ҳ�����������ʾ��Ʒ������ͼ�ֵ�� 
		for(int j=1;j<=cap;j++)
		{
			//bag[i][j]��ʾֻ��ǰi����Ʒ���������j��������ܼ�ֵ����Ƕ��١�
			if(j>=vol)
			{
				bag[i][j]=max(bag[i-1][j],bag[i-1][j-vol]+val);//��װ�¸���Ʒ��
			}
			else
				bag[i][j]=bag[i-1][j];//����װ�¸���Ʒ�� 
		}
	}
	cout<<bag[num][cap]<<endl;//������ֵ�� 
	return 0; 
}
