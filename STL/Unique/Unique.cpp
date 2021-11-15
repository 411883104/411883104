/*
unique函数属于STL中比较常用函数，它的功能是元素去重。
即”删除”序列中所有相邻的重复元素(只保留一个)。
此处的删除，并不是真的删除，而是指重复元素的位置被不重复的元素给占领了。
由于它”删除”的是相邻的重复元素，所以在使用unique函数之前，一般都会将目标序列进行排序。
unique函数的去重过程实际上就是不停的把后面不重复的元素移到前面来，也可以说是用不重复的元素占领重复元素的位置。
*/

/*
unique函数的函数原型:(两个参数型)
iterator unique(iterator it_1,iterator it_2);
其中这两个参数表示对容器中[it_1，it_2)范围的元素进行去重
(注：区间是前闭后开，即不包含it_2所指的元素)
返回值是一个迭代器，它指向的是去重后容器中不重复序列的最后一个元素的下一个元素。
*/

#include<iostream>
#include<algorithm>//unique包含在algorithm的头文件中
#include<vector>
using namespace std;
int main()
{
	int arr[]={1,4,2,1,5,6,3,4,2,4,1};
	vector<int>v;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		v.push_back(arr[i]);
	cout<<"数组去重前：" ; 
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"容器去重前：";
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<v.at(i)<<" ";
	cout<<endl;
	
	//去重前先排序 
	sort(arr,arr+sizeof(arr)/sizeof(int));
	int *p=unique(arr,arr+sizeof(arr)/sizeof(int));
	sort(v.begin(),v.end());
	auto q=unique(v.begin(),v.end());
	
	cout<<"数组去重后：" ;
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"容器去重后：";
	for(int i=0;i<sizeof(arr)/sizeof(int);i++)
		cout<<v.at(i)<<" ";
	cout<<endl;
	
	cout<<"数组去重后：" ;
	for(int i=0;i<p-arr;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"容器去重后：";
	for(int i=0;i<q-v.begin();i++)
		cout<<v.at(i)<<" ";
	return 0;
} 
