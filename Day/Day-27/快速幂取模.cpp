#include<iostream>
using namespace std;
typedef long long ll; 
int main() {
	ll a,b,p;
	cin>>a>>b>>p;
	ll base=a;
	ll res=1;
	//�ж�ָ���Ƿ�Ϊ0 
	if(b==0) {
		cout<<1%p<<endl;
	} else {

		while(b>0) {
			if(b&1)//�����ǰbΪ��������b��1��������ǰ���ֵ���Եס�
				res=(res*base)%p;
			base=(base*base)%p;//ָ����Ϊԭ����һ�롣
			b>>=1;
		}
		cout<<res<<endl;
	}
	return 0;
}
