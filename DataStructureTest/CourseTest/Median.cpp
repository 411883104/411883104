/*
 * @Author: Outsider
 * @Date: 2022-01-04 10:53:56
 * @LastEditors: Outsider
 * @LastEditTime: 2022-01-06 20:04:23
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\CourseTest\Median.cpp
 */


#include<iostream>
#include<thread>
#include<stdlib.h>
#include<ctime>

using namespace std;


/**
 * @description: 交换数
 * @param {int&} a 待交换节点
 * @param {int&} b 带交换节点
 * @return {*}
 */
void swap(int& a,int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

/**
 * @description: 
 * 定义一个堆，内含大根堆和小根堆
 */
class Heap{
private:
    /**
     * @description: 私有成员变量定义
     * @param arr 数组首地址
     * @param length 数组已存元素长度
     * @param max_length 数组最大存储长度
     */
    int* arr;
    int length;
    int max_length;//堆最大长度，满后扩容

public:
    /**
     * @description: 公有成员函数定
    */
    Heap();

    /**
     * @description:重载运算符[] 
     * @param {*}
     * @return {*}
     */
    int& operator[](int i){
        return *(this->arr+i);
    }

    /**
     * @description: 返回数组已存元素长度 
     * @param {*}
     * @return {*}
     */    
    int size(){
        return length; //返回堆长度
    }

    void max_push_back(int);//大根堆添加节点
    void max_pop_back();//大根堆删除节点
    void max_Sink(int k);//大根堆节点下沉
    void max_Float(int);//大根堆节点上浮
    
    void min_push_back(int);//小根堆添加节点
    void min_pop_back();//小根堆删除节点
    void small_Sink(int k);//小根堆节点下沉
    void small_Float(int);//小根堆节点上浮
    void resize();//堆扩容
    int& top(); //获取堆顶元素
};

/**
 * @description: 节点下沉
 * @param {int} k 节点的下标
 * @return {*}
 */
void Heap::max_Sink(int k)//将小的节点下沉
{
    while (2 * k + 1 < length) {  //2*k为左孩子，2*k+1为右孩子,有左孩子则循环
        int j = 2 * k + 1; //如果数组从0开始，则2K+1为左孩子，2K+2为右孩子
        if (j + 1 < length && arr[j] < arr[j + 1]) {//如果有右孩子且右孩子比左孩子大
            j++;
        }
        if (arr[k] >= arr[j]) {     //父节点比较大的孩子节点大，则已满足堆
            break;
        }
        else {
            //交换
            int temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
        }
        k = j;//往下比较，一直下沉到叶子
    }
}

/**
 * @description: 大根堆节点上浮
 * @param {int} k 节点下标
 * @return {*} 
 */
void Heap::max_Float(int k)
{
    while(k>0){ //如果当前节点的值比父节点大，则节点上浮
        int j=(k-1)/2;       //父节点下标
        if(arr[k]>arr[j]){
            //交换值
            swap(arr[k],arr[j]);
        }
        k=j;  //继续往堆顶访问下去
    }
}

//构造函数
Heap::Heap()
{
    length=0;
    max_length=10000;
    arr=new int[max_length];
}

/**
 * @description: 数组长度不够，重新分配空间
 * @param size 数组长度
 * @return {*}
 */
void Heap::resize()
{
    int* new_arr=new int[2*(max_length)];
    for(int i=0;i<max_length;i++){
        new_arr[i]=arr[i];
    }
    delete []this->arr;
    this->arr=new_arr;
    this->max_length=2*(this->max_length);
}

/**
 * @description: 大根堆加入元素
 * @param {int} num 待加入数值
 * @return {*}
 */
void Heap::max_push_back(int num)
{
    if(length<max_length){
        arr[length++]=num;
        //调整堆，节点上浮
        max_Float(length-1);
    }
    else{
        //扩容
        resize();
        max_push_back(num);
    }
}

/**
 * @description: 将堆的堆顶元素删除
 * @param {*} 
 * @return {*}
 */
void Heap::max_pop_back()
{
    int temp=arr[0];
    arr[0]=arr[--length];
    arr[length]=temp;
    //调整堆，节点下沉
    max_Sink(0);
}

/**
 * @description: 获取堆顶元素
 * @param {*}
 * @return {*} 堆顶元素
 */
int& Heap::top()
{
    return *(this->arr);
}


/**
 * @description: 节点下沉
 * @param {int} k 节点的下标
 * @return {*}
 */
void Heap::small_Sink(int k)//将小的节点下沉
{
    while (2 * k + 1 < length) {  //2*k为左孩子，2*k+1为右孩子,有左孩子则循环
        int j = 2 * k + 1; //如果数组从0开始，则2K+1为左孩子，2K+2为右孩子
        if (j + 1 < length && arr[j] > arr[j + 1]) {
            j++;
        }
        if (arr[k] <= arr[j]) {     //父节点比比较小的孩子节点小，则已满足堆
            break;
        }
        else {
            //交换
            swap(arr[k],arr[j]);
        }
        k = j;//往下比较，一直下沉到叶子
    }
}

void Heap::small_Float(int k)
{
    while(k>0){ //如果当前节点的值比父节点小，则节点上浮
        int j=(k-1)/2;       //父节点下标
        if(arr[k]<arr[j]){
            //交换值
            swap(arr[k],arr[j]);
        }
        else{
            break;
        }
        k=j;  //继续往堆顶访问下去
    }
}

/**
 * @description: 向数组中加入元素
 * @param {int} num 待加入数值
 * @return {*}
 */
void Heap::min_push_back(int num)
{
    if(length<max_length){
        arr[length++]=num;
        small_Float(length-1);
    }
    else{
        //扩容
        resize();
        min_push_back(num);
    }
}

/**
 * @description: 小根堆删除操作
 * @param {*}
 * @return {*}
 */
void Heap::min_pop_back()
{
    swap(arr[0],arr[--length]);
    small_Sink(0);
}


class MedianHolder{
public:
    Heap maxHeap; //大根堆
    Heap minHeap; //小根堆
public:

    /**
     * @description: 添加数据流中的数
     * @param {int} num 待添加数据
     * @return {*}
     */    
    void addNum(int num) {
        //大根堆为空或待加入数据比大根堆堆顶元素小时加入大根堆
        if(maxHeap.size()==0||num<=maxHeap.top())
        {
            maxHeap.max_push_back(num);
            //如果大根堆比小根堆多2个元素，则将大根堆的堆顶元素加到小根堆
            //同时删除大根堆堆顶元素
            if (minHeap.size() + 1 < maxHeap.size()) {
                    minHeap.min_push_back(maxHeap.top());
                    maxHeap.max_pop_back();
                }
        }
        else {//待加入数据比大根堆堆顶元素大时加入大根堆
            minHeap.min_push_back(num);
            //小根堆元素个数比大根堆小时将小根堆的堆顶元素加到大根堆
            //同时删除小根堆堆顶元素
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.max_push_back(minHeap.top());
                minHeap.min_pop_back();
            }
        }
    }
    
    /**
     * @description: 返回中位数
     * @param {*}
     * @return {*} 中位数
     */    
    double findMedian() {
        if(maxHeap.size()>minHeap.size())
        {
            return maxHeap.top();
        }
        return (minHeap.top()+maxHeap.top())/2.0;
    }
};

int main()
{
    MedianHolder medianHolder;

    time_t tt;
    srand((unsigned)time(&tt));
    // thread t(&MedianHolder::addNum,medianHolder,rand()%100);
    // t.detach();
    
    char x;
    while(cin>>x&&x!='q'){
        for(int i=0;i<rand()%20;i++){
            medianHolder.addNum(rand()%1000);
        }
        cout<<"MaxHeap: ";
        for(int i=0;i<medianHolder.maxHeap.size();i++){
            cout<<medianHolder.maxHeap[i]<<" ";
        }
        cout<<endl;
        cout<<"MinHeap: ";
        for(int i=0;i<medianHolder.minHeap.size();i++){
            cout<<medianHolder.minHeap[i]<<" ";
        }
        cout<<endl;
        cout<<"Median: "<<medianHolder.findMedian()<<endl;
    }
    
    system("pause");
}