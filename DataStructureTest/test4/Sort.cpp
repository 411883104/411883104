/*
 * @Author: Outsider
 * @Date: 2021-12-13 13:57:15
 * @LastEditors: Outsider
 * @LastEditTime: 2021-12-26 16:02:24
 * @Description: 排序算法实现
 * 1、数组长度16
 * 2、数组元素类int
 * @FilePath: \DataStructureTest\test4\Sort.cpp
 */

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;



const int c = 16;
int arr[c];

/**
 * @description: 插入排序
 * @param {int} *arr 待排数组
 * @return {*}
 */
void InsertSort(int* arr)
{
    for (int i = 1; i < c; i++)//第一个元素作为标准，从第二个元素开始
    {
        int CountContrast = 0;//记录比较次数
        int CountMove = 0;//记录移动次数

        int cur = i - 1; //指向要比较元素
        int flag = 1;      //判断是否发生过交换

        cout << "关键字" << arr[i];
        while (flag && cur >= 0) //与前面的元素比较后插入
        {
            flag = 0;
            CountContrast++;
            if (arr[cur + 1] < arr[cur])//前后两记录进行比较插入
            {
                //交换元素
                int temp = arr[cur];
                arr[cur] = arr[cur + 1];
                arr[cur + 1] = temp;
                CountMove++;
                flag = 1;
            }
            cur--;
        }
        //输出排序的中间过程
        cout << "比较" << CountContrast << "次交换" << CountMove << "次" << endl;
        cout << "第" << i << "次交换: ";
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

/**
 * @description: 冒泡排序
 * 将大的数向数组的后方移
 * 1.第一个记录和第二给记录比较，如果逆序则交换，一直遍历到数组后方n，最大的数存到n位置上。
 * 2.第二次遍历到数组n-1处，将次大的数存到n-1位置上。
 * 3.重复上述步骤，直至没有进行交换为止。
 * @param {int} arr 待排数组
 * @return {*}
 */
void BubbleSort(int arr[])
{
    int CountContrast = 0;//记录比较次数
    int CountMove = 0;//记录移动次数

    int i = c - 1; //最后一个元素开始
    int flag = 1;

    int cnt = 1;
    for (; i > 0 && flag; i--)//数组没越界并且上一轮进行的交换
    {
        flag = 0;
        for (int j = 0; j < i; j++)
        {
            CountContrast++;
            if (arr[j] > arr[j + 1])
            {
                //交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                CountMove++;
                flag = 1; //还存在交换，则可能还是无序
            }
        }
        //输出排序的中间过程
        cout << "第" << cnt++ << "次排序: ";
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    cout << "关键字比较次数:" << CountContrast << " 移动次数:" << CountMove << endl;
}

/**
 * @description: 希尔排序
 * 1.将待排数组分组，分组的数据由小变多，先排完小的分组然后扩大分组再排。
 * 2.每一个分组间可以使用插入排序方法排序。
 * @param {int} arr 待排数组
 * @return {*}
 */
void ShellSort(int arr[])
{
    int CountContrast = 0;//记录比较次数
    int CountMove = 0;//记录移动次数

    int group = c / 2; //将待排数组分组
    int cnt = 1;//记录第几次排序
    while (group >= 1)
    {
        for (int i = 0; i < c; i++)
        {
            int flag = 1;      //判断是否发生过交换

            int cur = i - group;
            while (flag && cur >= 0)
            {
                //组内插入排序
                flag = 0;
                CountContrast++;
                if (arr[cur + group] < arr[cur])
                {
                    //交换元素
                    int temp = arr[cur + group];
                    arr[cur + group] = arr[cur];
                    arr[cur] = temp;
                    CountMove++;
                    flag = 1;
                }
                cur -= group;
            }
        }
        group /= 2;
        //输出排序的中间过程
        cout << "第" << cnt++ << "次希尔排序: ";
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    cout << "关键字比较次数:" << CountContrast << " 移动次数:" << CountMove << endl;
}

/**
 * @description: 选择排序
 * 1.每一次从无序的数组序列中选出最小的一个记录。
 * 2.将找到的记录交换到已经有序的序列的最后。
 * 3.经过n-1趟得到有序数组。
 * @param {int} arr 待排数组
 * @return {*}
 */
void SelectSort(int arr[])
{
    int CountContrast = 0;//记录比较次数
    int CountMove = 0;//记录移动次数
    for (int i = 0; i < c - 1; i++)
    {
        int minn = 0xffffff;//初始化数值，寻找最小值
        int k = i;
        for (int j = i; j < c; j++)
        {
            CountContrast++;
            //寻找从i开始的最小值
            if (minn > arr[j])
            {
                minn = arr[j];
                k = j;
            }
        }
        //交换数值
        minn = arr[k];
        arr[k] = arr[i];
        arr[i] = minn;
        CountMove++;

        //输出排序的中间过程
        cout << "第" << i + 1 << "次排序: ";
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    cout << "关键字比较次数:" << CountContrast << " 移动次数:" << CountMove << endl;
}

/**
 * @description:快速排序
 * @param {int} arr 待排数组
 * @param {int} start 排序的起点
 * @param {int} end 排序的终点
 * @return {*}
 */
int QuickSortCountContrast = 0;//记录比较次数
int QuickSortCountMove = 0;//记录移动次数
int QuickCnt = 1;//记录快速排序的排序次数
void QuickSort(int arr[], int start, int end) {
    if (start >= end) {  //递归终点
        return;
    }
    int left = start;
    int right = end;
    int cur = arr[start]; //记录基准
    while (left < right) {//前后指针不相碰继续寻找
        while (arr[right] >= cur && left < right) {
            QuickSortCountContrast++;
            right--;   //寻找比基准小的数
        }
        QuickSortCountMove++;
        arr[left] = arr[right];
        while (arr[left] <= cur && left < right) {
            QuickSortCountContrast++;
            left++;   //寻找比基准大的数
        }
        QuickSortCountMove++;
        arr[right] = arr[left];
    }
    QuickSortCountMove++;
    arr[left] = cur;//基准在数组中的位置，将数组分成了大小两部分
    //输出排序的中间过程
    cout << "第" << QuickCnt++ << "次排序: ";
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    QuickSort(arr, start, left - 1);//递归进行子序列的快速排序
    QuickSort(arr, left + 1, end);
}

/**
 * @description: 调整堆，即将小的节点下沉
 * 堆顶与左右孩子比较，如果比孩子大，则已是堆。
 * 如果比孩子小，则与较大的孩子交换。
 * 交换到新的位置后继续向下比较
 * @param {int} arr 待调整数组
 * @param {int} k 要调整节点的位置
 * @param {int} n 数组长度
 * @return {*}
 */
int HeapSortCountContrast = 0;//记录比较次数
int HeapSortCountMove = 0;//记录移动次数
int HeapCnt = 1;//记录堆排序的排序次数
void Sink(int arr[], int k, int n)//将小的节点下沉
{
    while (2 * k + 1 <= n) {  //2*k为左孩子，2*k+1为右孩子,有左孩子则循环
        int j = 2 * k + 1; //如果数组从0开始，则2K+1为左孩子，2K+2为右孩子
        HeapSortCountContrast++;
        if (j + 1 <= n && arr[j] < arr[j + 1]) {//如果有右孩子且右孩子比左孩子大
            j++;
        }
        HeapSortCountContrast++;
        if (arr[k] >= arr[j]) {     //父节点比较大的孩子节点大，则已满足堆
            break;
        }
        else {
            //交换
            int temp = arr[k];
            arr[k] = arr[j];
            arr[j] = temp;
            HeapSortCountMove++;
        }
        k = j;//往下比较，一直下沉到叶子
    }
}

/**
 * @description: 堆排序
 * 1.构造初始堆
 * 2.堆顶元素和最后一个记录交换，然后除最后一个元素外调整堆
 * 3.堆顶元素和倒数第二个记录交换，然后除最后两个元素外构造堆。
 * 4.循环上述步骤，得到有序数组
 * @param {int} arr 待排数组
 * @return {*}
 */
void HeapSort(int arr[]) {
    for (int i = (c - 1) / 2; i >= 0; i--) {//构造大根堆，从最后的非叶子节点开始
        Sink(arr, i, c - 1);
    }

    /*for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;*/
    int n = c - 1;
    while (n > 0) {
        //堆顶和最后元素佳欢
        int temp = arr[n];
        arr[n] = arr[0];
        arr[0] = temp;
        HeapSortCountMove++;
        Sink(arr, 0, --n);//调整堆

        //输出排序的中间过程
        cout << "第" << HeapCnt++ << "次排序: ";
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

/**
 * @description: 归并两子序列
 * 两个指针分别指向两个有序序列，一个指针指向辅助数组初始位置
 * 比较有序子序列指针所指元素
 * 小的加入辅助数组，辅助数组和选取了元素的数组的指针同时向后移
 * @param {int} arr 待排数组
 * @param {int} left 要归并数组的左端
 * @param {int} mid  将数组分割为两个子序列的位置
 * @param {int} right 要归并数组的右端
 * @return {*}
 */
int MergeSortCountContrast = 0;//记录比较次数
int MergeSortCountMove = 0;//记录移动次数
int MergeSortCnt = 1;//记录归并排序的排序次数
void Merge(int arr[], int left, int mid, int right)
{
    int* num = new int[right - left + 1];//申请一个辅助数组
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        //从小到大存放到辅助数组中
        MergeSortCountContrast++;
        MergeSortCountMove++;
        if (arr[i] <= arr[j]) {
            num[k++] = arr[i++];
        }
        else {
            num[k++] = arr[j++];
        }
    }
    //将剩余的元素进行处理
    while (i <= mid) {
        num[k++] = arr[i++];
        MergeSortCountMove++;
    }
    //将剩余的元素进行处理
    while (j <= right) {
        num[k++] = arr[j++];
        MergeSortCountMove++;
    }
    for (i = left, k = 0; i <= right; i++) {
        //将合并后的序列放回到原数组中
        arr[i] = num[k++];
        MergeSortCountMove++;
    }
    delete[]num;
}

/**
 * @description: 归并排序
 * 1.将待排数组分成规模大致相同的两个子序列
 * 2.借用辅助数组将两个子序列进行合并排序。
 * 3.将排好序的有序子序列进行合并得到最终的有序序列
 * @param {int} arr 待排数组
 * @param {int} left 待排数组左端
 * @param {int} right 待排数组右端
 * @return {*}
 */
void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);

        //输出排序的中间过程
        cout << "第" << MergeSortCnt++ << "次排序: ";
        for (int i = 0; i < c; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
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
    cout << "arr: ";
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //InsertSort(arr);
    //ShellSort(arr);
    //SelectSort(arr);
    //BubbleSort(arr);
    QuickSort(arr,0,c-1);
    cout << "关键字比较次数:" << QuickSortCountContrast << " 移动次数:" << QuickSortCountMove << endl;
    //HeapSort(arr);
    //cout << "关键字比较次数:" << HeapSortCountContrast << " 移动次数:" << HeapSortCountMove << endl;
    //MergeSort(arr,0,c-1);
    //cout << "关键字比较次数:" << MergeSortCountContrast << " 移动次数:" << MergeSortCountMove << endl;

    cout << "Sortedarr: ";
    for (int i = 0; i < c; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    system("pause");
}