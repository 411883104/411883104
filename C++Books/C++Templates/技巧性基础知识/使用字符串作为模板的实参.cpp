
//#include<iostream>
//using namespace std;
//
//template<typename T>
//inline T const& max(T const& a, T const& b)
//{
//	return a < b ? b : a;
//}
//
//
//int main()
//{
//	std::string s;
//	
//	//�ں���maxǰ��::˵�����ڶ��������ռ䣨�൱��ȫ�ֱ������е���
//	//���û�м�::,��Ϊʹ����std����ֵ��ö����Ա������
//	std::cout << ::max("apple", "peach") << std::endl;
//
//	//"apple"����Ϊchar const[6],"tomata"����Ϊchar const[7]
//	//::max("apple", "tomato");  //���󣬲�ͬ���͵�ʵ��
//	//::max("apple", s);         //���󣬲�ͬ���͵�ʵ��
//}
//
//#include<iostream>
//using namespace std;
//
////�����ò���
//template<typename T>
//inline T max(T a, T b)
//{
//	return a < b ? b : a;
//}
//int main()
//{
//	string s;
//
//	::max("apple", "peach");
//
//	//���ڷ��������͵Ĳ�������ʵ������Ĺ����У���������鵽ָ�������ת��(decay)  
//	::max("apple", "tomato");//ͨ���������˻�(decay)Ϊ��ͬ������ 
//	//::max("apple",s);//���󣬲�ͬ������ 
//}

#include<iostream>
#include<typeinfo>

template<typename T>
void ref(T const& x)
{
	std::cout << "x in ref(T const&): " << typeid(x).name() << std::endl;
}

template<typename T>
void nonref(T x)
{
	std::cout << "x in nonref(T x): " << typeid(x).name() << std::endl;
}

int main()
{
	ref("hello");
	nonref("hello");
	std::cout << typeid(2).name() << std::endl;//�鿴��������
}
