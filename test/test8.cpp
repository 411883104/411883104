#include<iostream> 
using namespace std;

class Point
{  int x , y ;
public:
	Point(){};
    friend istream & operator >> (istream &in, Point &p) ;    //���������">>"
    friend ostream & operator << (ostream &out, Point &p) ;  //���������"<<"
} ;
istream & operator >> ( istream & in , Point & p )
{
        cout<<"������x, y��ֵ��"<<endl ;
        cout<<"x��";
        in>>p.x;
        cout <<"y��";
        in>>p.y;
        return in;
}
ostream & operator << ( ostream & out , Point & p )
{
          out <<"���x, y��ֵ"<< endl ;
          out<<"x��"<<p.x<<"   y=" << p.y<<endl;
          return out;
}

int main()
{  
	Point P;
	cin>>P;
	cout<<P;
}

