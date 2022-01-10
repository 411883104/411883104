/*
 * @Author: Outsider
 * @Date: 2021-11-18 21:17:46
 * @LastEditors: Outsider
 * @LastEditTime: 2021-11-18 21:25:25
 * @Description: In User Settings Edit
 * @FilePath: \C++\Multithread\basic.cpp
 */
#include<iostream>
#include<thread>

using namespace std;

void thread_1()
{
    for(int i=0;i<100000;i++)
        cout<<"thread_1!"<<endl;
}

int main()
{
    thread* t_1=new thread(thread_1);
    t_1->join();
    for(int i=0;i<100000;i++)
        cout<<"main!"<<endl;
    delete t_1;
    system("pause");
}