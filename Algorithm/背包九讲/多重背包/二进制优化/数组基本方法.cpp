#include<iostream>
#include<algorithm>
using namespace std;
const int c=20050;
int bag[c];//һά��ʾ
int vol[c],val[c];//vol��val�ֱ�Ϊ��i����Ʒ������ͼ�ֵ��sum��ʾ����Ʒ�ж��ټ��� 
int main()
{
	int num,cap,cnt=0;//numΪ��Ʒ������capΪ�����������cnt��¼����Ʒ�ֿ��������� 
	cin>>num>>cap;
	int vo,va,sum;//voΪ��Ʒ�����vaΪ��Ʒ��ֵ��sumΪ��Ʒ������ 
	//����Ʒ�ֿ� 
	for(int i=1;i<=num;i++)
	{
		cin>>vo>>va>>sum;
		//��¼�ֿ��������ͼ�ֵ�� 
		for(int j=1;j<=sum;j*=2)
		{
			vol[++cnt]=j*vo;
			val[cnt]=j*va;
			sum-=j;
		}
		if(sum>0)
		{
			vol[++cnt]=sum*vo;
			val[cnt]=sum*va; 
		}
	}
	//ת��Ϊ01�������� 
	for(int i=1;i<=cnt;i++)
	{
		for(int j=cap;j>=vol[i];j--)
		{
			bag[j]=max(bag[j],bag[j-vol[i]]+val[i]);
		}
	}
	cout<<bag[cap]<<endl;//������ֵ�� 
	return 0; 
}
