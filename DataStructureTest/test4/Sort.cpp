/*
 * @Author: Outsider
 * @Date: 2021-12-13 13:57:15
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-20 14:43:35
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


void QuickSort(int arr[],int low,int higt){
    int cur=arr[low];
    
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
    ShellSort(arr);

    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
}