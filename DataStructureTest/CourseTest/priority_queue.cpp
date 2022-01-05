#include<iostream>
using namespace std;
#include<queue>
//思路：
//1、使用两个堆结构，一个大根堆一个小根堆。
//2、将接收的所有数的较小的一半放入大根堆，将接收的所有数的较大的一半放入小根堆
//3、如果接收的总数为奇数，中位数就是小根堆和大根堆中数量多的那个堆的堆顶
//   如果接收的总数为偶数，中位数就是两个堆顶相加除以2
class MedianHolder
{
private:
	int size;     //记录数组大小

public:	
	int* smallHeap;
	int* bigHeap ;
	int lenOfsmallHeap;        //小根堆数据个数
	int lenOfbigHeap;          //大根堆数据个数

	//初始化数据个数
	MedianHolder()
	{
		lenOfsmallHeap = 0;
		lenOfbigHeap = 0;
		this->size = 1;
        this->smallHeap = new int[size]; //小根堆
        this->bigHeap = new int[size];   //大根堆
	}


	//调整大根堆
	void adjustbigHeap(int index)
	{
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int maxIndex = index;

		if (left < lenOfbigHeap && bigHeap[maxIndex] < bigHeap[left])
			maxIndex = left;

		if (right < lenOfbigHeap && bigHeap[maxIndex] < bigHeap[right])
			maxIndex = right;

		if (maxIndex != index)
		{
			//交换，把大的数放上面
			int temp = bigHeap[index];
			bigHeap[index] = bigHeap[maxIndex];
			bigHeap[maxIndex] = temp;

			//递归调整
			adjustbigHeap(maxIndex);
		}
		return;
	}

	//调整小根堆
	void adjustsmallHeap(int index)
	{
		int left = index * 2 + 1;
		int right = index * 2 + 2;
		int minIndex = index;

		if (left < lenOfsmallHeap && smallHeap[minIndex]>smallHeap[left])
			minIndex = left;

		if (right < lenOfsmallHeap && smallHeap[minIndex]>smallHeap[right])
			minIndex = right;

		if (minIndex != index)
		{
			//交换，把小的数字放上面
			int temp = smallHeap[index];
			smallHeap[index] = smallHeap[minIndex];
			smallHeap[minIndex] = temp;

			//递归调整
			adjustsmallHeap(minIndex);
		}
		return;
	}

	//插入数据到大根堆并调节大根堆
	void insertbigHeap(int num)
	{
		//先判断当时数组是否已经满了
		if (lenOfbigHeap == size)
		{
			size = size * 2;
			int* newHeap = new int[size+4];
			for (int i = 0; i < lenOfbigHeap; i++)
				newHeap[i] = bigHeap[i];
			delete[] bigHeap;
			bigHeap = newHeap;
		}
		bigHeap[lenOfbigHeap++] = num;

		//从最后一个非叶子结点开始调节大根堆
		for (int i = lenOfbigHeap / 2 - 1; i >= 0; i--)
			adjustbigHeap(i);
	}

	//插入数据到小根堆并调节小根堆
	void insertsmallHeap(int num)
	{
		//先判断当时数组是否已经满了
		if (lenOfsmallHeap == size)
		{
			size = size * 2;
			int* newHeap = new int[size + 4];
			for (int i = 0; i < lenOfsmallHeap; i++)
				newHeap[i] = smallHeap[i];
			delete[] smallHeap;
			smallHeap = newHeap;
		}
		smallHeap[lenOfsmallHeap++] = num;

		//从最后一个非叶子结点开始调节小根堆
		for (int i = lenOfsmallHeap / 2 - 1; i >= 0; i--)
			adjustsmallHeap(i);
	}

	//弹出大根堆的堆顶
	void movebigVector()
	{
		//把一号位置下方的元素向前移动一位，相当于弹出堆顶
		for (int i = 1; i < lenOfbigHeap; i++)
			bigHeap[i - 1] = bigHeap[i];
		//弹出堆顶，前面元素整体左移一位，少了一个元素，尾部不要
		lenOfbigHeap--;
	}

	//弹出小根堆的堆顶
	void movesmallVector()
	{
		//把一号位置下方的元素向前移动一位，相当于弹出堆顶
		for (int i = 1; i < lenOfsmallHeap; i++)
			smallHeap[i - 1] = smallHeap[i];
		//弹出堆顶，前面元素整体左移一位，少了一个元素，尾部不要
		lenOfsmallHeap--;
	}

	//插入数据
	void solve(int num)
	{
		int length = lenOfbigHeap + lenOfsmallHeap;

		//奇数个数，插入大根堆
		if (length % 2 == 1)
		{
			//如果插入的数大于小根堆的堆顶
			if (lenOfsmallHeap > 0 && num > smallHeap[0])
			{
				insertsmallHeap(num);      //插入小根堆并调整最小堆
				int temp = smallHeap[0];   //获取小根堆的堆顶
				movesmallVector();         //弹出小根堆堆顶
				//弹出小根堆的堆顶后重新调整小根堆
				for (int i = lenOfsmallHeap / 2 - 1; i >= 0; i--)
					adjustsmallHeap(i);
				//插入大根堆并调整大根堆
				insertbigHeap(temp);
			}
			else
				insertbigHeap(num);
		}
		//偶数个数，插入小根堆
		else
		{
			//如果插入的数小于大根堆的堆顶
			if (lenOfbigHeap > 0 && num < bigHeap[0])
			{
				insertbigHeap(num);      //插入大根堆并调整最小堆
				int temp = bigHeap[0];   //获取大根堆的堆顶
				movebigVector();         //弹出大根堆堆顶
				//弹出大根堆的堆顶后重新调整大根堆
				for (int i = lenOfbigHeap / 2 - 1; i >= 0; i--)
					adjustbigHeap(i);
				//插入小根堆并调整小根堆
				insertsmallHeap(temp);
			}
			else
				insertsmallHeap(num);
		}
	}

	//获取当前数据流的中位数
	double getMedian()
	{
		int length = lenOfsmallHeap + lenOfbigHeap;
		if (length == 0)
			return 0;

		//如果接收的总数为奇数，中位数就是小根堆和大根堆中数量多的那个堆的堆顶
		if (length % 2 == 1)
			return smallHeap[0];
		//如果接收的总数为偶数，中位数就是两个堆顶相加除以2
		else
			return (smallHeap[0] + bigHeap[0]) * 1.0 / 2.0;
	}

	//输出当前序列数据
	void show()
	{
		//输出大根堆数据
		for (int i = 0; i < lenOfbigHeap; i++)
			cout << bigHeap[i] << "  ";
		//输出小根堆数据
		for (int i = 0; i < lenOfsmallHeap; i++)
			cout << smallHeap[i] << "  ";
	}
};

int main()
{
	MedianHolder M;
	int num;

	while (true)
	{
		//插入数据
		cout << "请输入加入的数据：";
		cin >> num;
		M.solve(num);

		//输出当前序列数据
		cout << "当前序列数据：";
		M.show();
		cout << "中位数：" << M.getMedian() << '\n';
	}
	system("pause");
	return 0;
}