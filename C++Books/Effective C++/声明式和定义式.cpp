/*ע��: 
1)���ڵ��������������const�����enums����#defines��
2)�������ƺ����ĺ�(macros),��ø���inline�����滻#defines�� 
*/

#include<iostream>
using namespace std;
class Gameplay
{
	public:
		const int num=5;//constԼ������������ʽ��ʼ��
		static const int cnt=2;
		/*Ҳ�����ó�ʼʽ��num��ʼ�� 
		const int num;
		Gameplay(int x):num(x){}  
		*/ 
		static const int ans;//�����⸳ֵ 
};
//cnt�Ķ���ʽ 
const int Gameplay::cnt; 
const int Gameplay::ans=10; //����ʱֻ��ȥ��static 
int main()
{
	Gameplay one;
	cout<<one.num<<endl;
	cout<<&(one.num)<<endl; 
	cout<<one.cnt<<endl;//û�ж�cnt��ַ������û�ж���ʽ����ȷ�� 
	cout<<&(one.cnt)<<endl;//���û��cnt�Ķ���ʽ���ᱨ��
	cout<<one.ans<<endl; 
}
