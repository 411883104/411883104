/*
 * @Author: Outsider
 * @Date: 2022-01-10 20:25:16
 * @LastEditors: Outsider
 * @LastEditTime: 2022-01-10 20:39:16
 * @Description: In User Settings Edit
 * @FilePath: \C++\Algorithm\Sort\InsertSort.cpp
 */

#include<iostream>

#include<SortHead.h>

#include <stdlib.h>
#include <ctime>

using namespace std;


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