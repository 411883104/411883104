#include<iostream>
#include<algorithm>
using namespace std;
const int c=20050;
int bag[c];//һά��ʾ
//int vol[c],val[c];//vol��val�ֱ�Ϊ��i����Ʒ������ͼ�ֵ��sum��ʾ����Ʒ�ж��ټ��� 
int main()
{
	int num,cap,cnt=0;//numΪ��Ʒ������capΪ�����������cnt��¼����Ʒ�ֿ��������� 
	cin>>num>>cap;
//	int vo,va,sum;//voΪ��Ʒ�����vaΪ��Ʒ��ֵ��sumΪ��Ʒ������ 
	//����Ʒ�ֿ� 
	for(int i=1;i<=num;i++)
	{
		int vol,val,sum;
		cin>>vol>>val>>sum;
		//��¼�ֿ��������ͼ�ֵ�� 
		for(int j=1;j<=sum;j*=2)
		{
			sum-=j;
			for(int k=cap;k>=vol*j;k--) 
			{
				bag[k]=max(bag[k],bag[k-vol*j]+val*j);
			}
		}
		if(sum>0)
		{
			for(int k=cap;k>=vol*sum;k--) 
			{
				bag[k]=max(bag[k],bag[k-vol*sum]+val*sum);
			}
		}
	}
	cout<<bag[cap]<<endl;//������ֵ�� 
	return 0; 
}
