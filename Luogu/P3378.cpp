/*
 * @Author: Outsider
 * @Date: 2022-03-06 09:37:50
 * @LastEditors: Outsider
 * @LastEditTime: 2022-03-06 10:36:07
 * @Description: In User Settings Edit
 * @FilePath: \C++\Luogu\P3378.cpp
 */

#include<iostream>
#include<vector>
using namespace std;

vector<int>v;

void Sink()
{
    int i=0;
  
    int k=v.size()-1;
    while(i<=k){
        int j=2*i+1;
        if((j+1)<=k&&v[j]>v[j+1]){
            j++;
        }
        if(j>k){
            break;
        }
        if(v[i]>v[j]){
            int temp=v[i];
            v[i]=v[k];
            v[k]=temp;
        }
        else{
            break;
        }
        i=j;
    }
}

void Float()
{
    int k=v.size()-1;
    while(k>0){
        int i=(k-1)/2;
        if(i>=0&&v[i]>v[k]){
            int temp=v[i];
            v[i]=v[k];
            v[k]=temp;
        }
        else{
            break;
        }
        k=i;
    }
}

int main()
{
    int n;
    cin>>n;
    int op;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>op;
        switch (op)
        {
        case 1:
            cin>>x;
            v.push_back(x);
            Float();
            break;
        case 2:
            cout<<v[0]<<endl;
            break;

        case 3:
            v[0]=v[v.size()-1];
            v.pop_back();
            Sink();
            break;
        default:
            break;
        }
    }

    system("pause");
}