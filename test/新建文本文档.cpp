#include <iostream>
using namespace std;
/* ����򴴽�һ����ģ�壬���ԶԲ�ͬ���������͵�����
�ֱ���г�ʼ����������ݡ���͡���ƽ��ֵ����ʾ����ȹ��ܡ�*/
template<typename T, int MAXSIZE>
class Array
{
private:
	T array[MAXSIZE];
public:

	void Tianjia()//������ݺ���
	{
		T b;
		for (int i = 0; i < MAXSIZE; i++)
		{

			cin >> b; array[i] = b;
		}
		cout << "����������" << endl;
	};
	void Add()//��͡���ƽ��ֵ����
	{
		T sum = 0;
		for (int i = 0; i < MAXSIZE; i++)
		{
			sum += array[i];
		}
		cout << "��͵Ľ����" << sum << endl;
		cout << "����Ĵ�С��" << MAXSIZE << endl;
		cout << "ƽ��ֵ��" << sum / MAXSIZE << endl;
	}
	void Print()
	{
		cout << "�������飺" << endl;
		for (int i = 0; i < MAXSIZE; i++)
		{
			cout << array[i] << '\0';
		}
		cout << "�������" << endl;
	};
};
int main()
{
	Array<int, 5> A;
	A.Tianjia();
	A.Add();
	A.Print();
}
