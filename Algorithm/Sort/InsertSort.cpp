/*
 * @Author: Outsider
 * @Date: 2022-01-10 20:25:16
 * @LastEditors: Outsider
 * @LastEditTime: 2022-01-10 21:22:36
 * @Description: In User Settings Edit
 * @FilePath: \C++\Algorithm\Sort\InsertSort.cpp
 */

#include<iostream>


#include <stdlib.h>
#include <ctime>

using namespace std;


const int c = 16;
int arr[c];

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void insertSort()
{
    for(int i=1;i<c;i++)
    {
        int j=i-1;
        while(j>=0&&arr[j+1]<arr[j])//小于使算法稳定
        {
            swap(arr[j+1],arr[j]);
            j--;
        }
    }
}

// void binaryInsertSort()
// {
//     for(int i=1;i<c;i++)
//     {
//         int right=i-1;
//         int left=0;
//         while(left<=right)//小于使算法稳定
//         {
//             int mid=(left+right)/2;
//             if(arr[mid]<arr[i]){
//                 left=mid+1;
//             }
//             else{
//                 right=mid-1;
//             }
//         }
//         int j=i-1;
//         while(j>=right){
//             swap(arr[j+1],arr[j]);
//             j--;
//         }
//     }
// }

int main()
{
    time_t t;
    srand((unsigned)time(&t));
    for(int i=0;i<c;i++)
    {
        arr[i]=rand()%100;
    }
    for(int i=0;i<c;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    insertSort();

    for(int i=0;i<c;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    system("pause");
}