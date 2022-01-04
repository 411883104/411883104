/*
 * @Author: Outsider
 * @Date: 2022-01-04 09:42:37
 * @LastEditors: Outsider
 * @LastEditTime: 2022-01-04 15:23:21
 * @Description: In User Settings Edit
 * @FilePath: \DataStructureTest\CourseTest\priority_queue.cpp
 */


#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    priority_queue<int> q;
    vector<int>v;
    v.push_back(2);
    q.push(12);
    q.push(17);
    q.push(5);
    cout<<q.top()<<endl;
}