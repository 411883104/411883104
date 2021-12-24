/*
 * @Author: Outsider
 * @Date: 2021-12-13 13:57:15
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-24 19:36:56
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test4\Sort.cpp
 */

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int c = 16;
int arr[c];

/**
 * @description: 
 * @param {int} *arr
 * @return {*}
 */
void InsertSort(int *arr)
{
    for (int i = 1; i < c; i++)
    {                    //从第二个元素开始
        int cur = i - 1; //指向要比较元素
        while (cur >= 0)
        {
            if (arr[cur + 1] < arr[cur])
            {
                //交换元素
                int temp = arr[cur];
                arr[cur] = arr[cur + 1];
                arr[cur + 1] = temp;
            }
            cur--;
        }
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void BubbleSort(int arr[])
{
    int i = c - 1;
    int flag = 1;
    for (; i > 0 && flag; i--)
    {
        flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void ShellSort(int arr[])
{
    int group = c / 2;
    while (group >= 1)
    {
        for (int i = 0; i < c; i++)
        {
            int cur = i - group;
            while (cur >= 0)
            {
                if (arr[cur + group] < arr[cur])
                {
                    int temp = arr[cur + group];
                    arr[cur + group] = arr[cur];
                    arr[cur] = temp;
                }
                cur -= group;
            }
        }
        group /= 2;
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void SelectSort(int arr[])
{
    for (int i = 0; i < c; i++)
    {
        int minn = 0xffffff;
        int k = i;
        for (int j = i; j < c; j++)
        {
            if (minn > arr[j])
            {
                minn = arr[j];
                k = j;
            }
        }
        minn = arr[k];
        arr[k] = arr[i];
        arr[i] = minn;
    }
}


void QuickSort(int arr[],int start,int end){
    if(start>=end){
        return;
    }
    int left=start;
    int right=end;
    int cur=arr[start];
    cout<<cur<<endl;
    while(left<right){
        while(arr[right]>=cur&&left<right){
            right--;
        }
        arr[left]=arr[right];
        while(arr[left]<=cur&&left<right){
            left++;
        }
        arr[right]=arr[left];
    }
    arr[left]=cur;
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    QuickSort(arr,start,left-1);
    QuickSort(arr,left+1,end);
}

void Sink(int arr[],int k,int n)//将小的节点下沉
{
    while(2*k+1<=n){  //2*k为左孩子，2*k+1为右孩子,有左孩子则循环
        int j=2*k+1;
        if(j+1<=n&&arr[j]<arr[j+1]){//如果有右孩子且右孩子比左孩子大
            j++;
        }
        if(arr[k]>=arr[j]){     //父节点比较大的孩子节点大，则已满足堆
            break;
        }
        else{
            //交换
            int temp=arr[k];
            arr[k]=arr[j];
            arr[j]=temp;
        }
        k=j;//往下比较，一直下沉到叶子
    }
}

void HeapSort(int arr[]){
    for(int i=(c-1)/2;i>=0;i--){//构造大根堆
        Sink(arr,i,c-1);
    }

    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    int n=c-1;
    while(n>0){
        int temp=arr[n];
        arr[n]=arr[0];
        arr[0]=temp;
        Sink(arr,0,--n);
    }
}

void Merge(int arr[],int left,int mid,int right)
{
    int* num=new int[right-left+1];//申请一个辅助数组
    int i=left,j=mid+1,k=0;
    while(i<=mid&&j<=right){
        if(arr[i]<=arr[j]){
            num[k++]=arr[i++];
        }
        else{
            num[k++]=arr[j++];
        }
    }
    while(i<=mid){
        num[k++]=arr[i++];
    }
    while(j<=right){
        num[k++]=arr[j++];
    }
    for(i=left,k=0;i<=right;i++){
        arr[i]=num[k++];
    }
    
    delete []num;
}

void MergeSort(int arr[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merge(arr,left,mid,right);
        for (int i = 0; i < c; i++)
        {
        cout << arr[i] << " ";
        }
        cout<<endl;
    }
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    for (int i = 0; i < c; i++)
    {
        arr[i] = rand() % 89 + 10;
    }

    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //InsertSort(arr);
    //BubbleSort(arr);
    //SelectSort(arr);
    //ShellSort(arr);
    //QuickSort(arr,0,c-1);
    //HeapSort(arr);
    MergeSort(arr,0,c-1);

    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
}