#include <iostream>
using namespace std;
/* 编程序创建一个类模板，可以对不同的数据类型的数组
分别进行初始化、添加数据、求和、求平均值、显示数组等功能。*/
template<typename T, int MAXSIZE>
class Array
{
private:
	T array[MAXSIZE];
public:

	void Tianjia()//添加数据函数
	{
		T b;
		for (int i = 0; i < MAXSIZE; i++)
		{

			cin >> b; array[i] = b;
		}
		cout << "添加数据完毕" << endl;
	};
	void Add()//求和、求平均值函数
	{
		T sum = 0;
		for (int i = 0; i < MAXSIZE; i++)
		{
			sum += array[i];
		}
		cout << "求和的结果：" << sum << endl;
		cout << "数组的大小：" << MAXSIZE << endl;
		cout << "平均值：" << sum / MAXSIZE << endl;
	}
	void Print()
	{
		cout << "遍历数组：" << endl;
		for (int i = 0; i < MAXSIZE; i++)
		{
			cout << array[i] << '\0';
		}
		cout << "遍历完毕" << endl;
	};
};
int main()
{
	Array<int, 5> A;
	A.Tianjia();
	A.Add();
	A.Print();
}
