#include <iostream>
using namespace std; 
class TEST
{public:
	TEST() { cout<< "���ù��캯��" << endl;
			 x = 2; y = 50; z = 9; }
	TEST(int a,int b,int c ) 
	{
		cout << "�������ع��캯��"<< endl;
		x = a; y = b; z = c; 
	}
    void display()
	{ 
		cout << "x=" << x << '\t' << "y=" << y <<'\t' << "z=" << z << endl;
	}
	int max( int a,int b )
	{ 
		if ( a>b ) return a;  else return b;
	}
	~TEST( )
	{ 
		cout << "������������" << endl;
		cout << x << "," << y <<"��" << z << "���ֵ��:" << max( max( x,y ),z) << endl;
	} 
	private:
	int x,y,z;
};

int main()
{
	TEST obj1;
	obj1.display() ;
	TEST obj2(33, 20, 80);
	obj2.display();
}

