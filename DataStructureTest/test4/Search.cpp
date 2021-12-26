/*
 * @Author: Outsider
 * @Date: 2021-12-20 13:59:20
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-26 16:46:51
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\test4\Search.cpp
 */

#include<iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

const int c = 17;
char arr[c];


/**
 * @description: 顺序查找
 * 数组从1开始，0位置存储目标值
 * 返回0则查找失败,有相同值时返回数组后方的坐标
 * @param {char} arr 数组
 * @param {char} target 带查找目标
 * @return {*} 带查找目标在数组中的位置（从1开始）
 */
int SequenceSearch(char arr[], char target) {
    int Count = 0;
    // for(int i=0;i<c;i++){
        // if(arr[i]==target)
        // {
        //     return i;
        // }
    // }
    arr[0] = target;
    int i = 0;
    for (i = c - 1; arr[i] != target; i--) {
        Count++;
    }
    cout << "比较次数: " <<Count<< endl;
    return i;
}

/**
 * @description: 二分查找
 * 1.将待排序列进行排序
 * 2.left指向序列左边，right指向序列右边。
 * 3.如果left<=right,则mid=(left+right)/2,指向查找范围的中间元素。
 * 4.判断目标值与arr[mid]关系，相等则查找成功，算法结束。
 * 5.如果目标值小于arr[mid]，则令left=mid+1。否则令right=mid-1并继续循环比较。
 * @param {char} arr 数组
 * @param {char} target 带查找目标
 * @return {*} 带查找目标在数组中的位置
 */
int BinarySearch(char arr[], char targer) {
    int left = 0, right = c - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == targer) {//查找成功
            return mid;
        }
        else {
            if (arr[mid] > targer)
                right = mid - 1;//向左缩小查找范围
            else
                left = mid + 1; //向右缩小查找范围
        }
    }
    return 0; //查找失败返回0
}

/**
 * @description: 快速排序
 * @param {char} arr 待排数组
 * @param {int} start 开始下标
 * @param {int} end 结尾下标
 * @return {*}
 */
void QuickSort(char arr[], int start, int end) {
    if (start >= end) { //递归结束标志
        return;
    }
    int left = start;
    int right = end;
    int cur = arr[start];
    while (left < right) {
        while (arr[right] >= cur && left < right) {
            right--;
        }
        arr[left] = arr[right];
        while (arr[left] <= cur && left < right) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = cur;

    QuickSort(arr, start, left - 1);
    QuickSort(arr, left + 1, end);
}

int main() {
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 1; i < c; i++) {
        arr[i] = rand() % 26 + 97;
    }
    cout << "Arr: ";
    for (int i = 1; i < c; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    char target;
    cout << "intput target: ";
    cin >> target;
    cout << "SequenceSearch: " << SequenceSearch(arr, target) << endl;
    
    QuickSort(arr, 1, c - 1);
    cout << "SortedArr: ";
    for (int i = 1; i < c; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<<"BinarySearch: " << BinarySearch(arr, target) << endl;
    
    system("pause");
}