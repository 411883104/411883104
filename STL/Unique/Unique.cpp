/*
unique��������STL�бȽϳ��ú��������Ĺ�����Ԫ��ȥ�ء�
����ɾ�����������������ڵ��ظ�Ԫ��(ֻ����һ��)��
�˴���ɾ�������������ɾ��������ָ�ظ�Ԫ�ص�λ�ñ����ظ���Ԫ�ظ�ռ���ˡ�
��������ɾ�����������ڵ��ظ�Ԫ�أ�������ʹ��unique����֮ǰ��һ�㶼�ὫĿ�����н�������
unique������ȥ�ع���ʵ���Ͼ��ǲ�ͣ�İѺ��治�ظ���Ԫ���Ƶ�ǰ������Ҳ����˵���ò��ظ���Ԫ��ռ���ظ�Ԫ�ص�λ�á�
*/

/*
unique�����ĺ���ԭ��:(����������)
iterator unique(iterator it_1,iterator it_2);
����������������ʾ��������[it_1��it_2)��Χ��Ԫ�ؽ���ȥ��
(ע��������ǰ�պ󿪣���������it_2��ָ��Ԫ��)
����ֵ��һ������������ָ�����ȥ�غ������в��ظ����е����һ��Ԫ�ص���һ��Ԫ�ء�
*/

#include<iostream>
#include<algorithm>//unique������algorithm��ͷ�ļ���
#include<vector>
using namespace std;
int main()
{
	int arr[]={1,4,2,1,5,6,3,4,2,4,1};
	vector<int>v;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		v.push_back(arr[i]);
	cout<<"����ȥ��ǰ��" ; 
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"����ȥ��ǰ��";
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<v.at(i)<<" ";
	cout<<endl;
	
	//ȥ��ǰ������ 
	sort(arr,arr+sizeof(arr)/sizeof(int));
	int *p=unique(arr,arr+sizeof(arr)/sizeof(int));
	sort(v.begin(),v.end());
	auto q=unique(v.begin(),v.end());
	
	cout<<"����ȥ�غ�" ;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"����ȥ�غ�";
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<v.at(i)<<" ";
	cout<<endl;
	
	cout<<"����ȥ�غ�" ;
	for(int i=0;i<p-arr;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"����ȥ�غ�";
	for(int i=0;i<q-v.begin();i++)
		cout<<v.at(i)<<" ";
	return 0;
} 
