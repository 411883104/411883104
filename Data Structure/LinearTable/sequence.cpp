//
// Created by LWZ on 2021/9/25.
//

#include<iostream>
using namespace std;

template<typename T>
struct SqList    //定义顺序表
{
private:
    T * elem;  //线性表的首地址
    int length; //线性表的长度
    int maxLength;
public:
    //初始化
    SqList(int length):maxLength(length)
    {
        this->elem=new T[maxLength];
        length=0;  //初始长度为0
    };

    //判断初始化是否成功
    bool Init()
    {
        if(!this->elem)
            return false;
        return true;
    }

    //创建顺序表
    bool Create()
    {
        int cnt;
        T in;
        while(cin>>cnt&&cnt)
        {
            if(length==maxLength)
            {
                return false;
            }
            else
            {
                elem[length++]=cnt;
            }
        }
        return true;
    }

    //输出顺序表
    void Output()
    {
        for(int i=0;i<length;i++)
        {
            cout<<elem[i]<<endl;
        }
    }

};


int main()
{
    SqList<int> sqList(100);
    cout<<sqList.Init()<<endl;
//    ConnectMysql();
////
////    }
    sqList.Create();
    sqList.Output();
}

