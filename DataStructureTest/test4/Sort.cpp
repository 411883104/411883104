/*
 * @Author: Outsider
 * @Date: 2021-12-13 13:57:15
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-13 14:23:11
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test4\Sort.cpp
 */


#include<iostream>
#include<stdlib.h>
#include<ctime>

using namespace std;

const int c=16;
int arr[c];

void InsertSort(int *arr){
    for(int i=1;i<c;i++){
        int cur=i-1;
        while(cur>=0){
            if(arr[i]>arr[cur]){
                int temp=arr[cur];
                arr[cur]=arr[i];
                arr[i]=temp;
                break;
            }
            cur--;
        }
    }
}

int main(){
    time_t t;
    srand((unsigned)time(&t));

    for(int i=0;i<c;i++){
        arr[i]=rand()%89+10;
    }

    for(int i=0;i<c;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    InsertSort(arr);

    for(int i=0;i<c;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    system("pause");
}