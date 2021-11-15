#include<iostream> 
using namespace std;

class Point
{  int x , y ;
public:
	Point(){};
    friend istream & operator >> (istream &in, Point &p) ;    //重载运算符">>"
    friend ostream & operator << (ostream &out, Point &p) ;  //重载运算符"<<"
} ;
istream & operator >> ( istream & in , Point & p )
{
        cout<<"请输入x, y的值："<<endl ;
        cout<<"x＝";
        in>>p.x;
        cout <<"y＝";
        in>>p.y;
        return in;
}
ostream & operator << ( ostream & out , Point & p )
{
          out <<"输出x, y的值"<< endl ;
          out<<"x＝"<<p.x<<"   y=" << p.y<<endl;
          return out;
}

int main()
{  
	Point P;
	cin>>P;
	cout<<P;
}

