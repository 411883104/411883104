#include<iostream>
using namespace std;
class Matrix
{
public:
 Matrix(int a=1,int b=1) //构造函数，a为行，b为列
 { 
 m = a; n = b;
 
 c=new int [a*b+2];//用数组来记载矩阵
 
 };
 ~Matrix() {delete[] c;}
 void setMatrix()//矩阵赋值函数
 {
  //this->c = new int[a* b];
  for (int i = 0; i < m* n; i++)//逐一给矩阵赋值
   cin >> c[i];
 };
// Matrix(const Matrix&s)
// {
// 	c=s.c;
// }
 void print() //矩阵打印函数
 { 
  int* p = c;
  for (int i = 0; i < m * n; i++)
  {
   cout << *p << ' '; p++;
  }; 
 }
 Matrix operator +(const Matrix& c1);//重载+运算符函数
private:
 int* c; 
 int m;
 int n;
};
Matrix Matrix::operator +(const Matrix &c1)
{
 for (int i = 0; i < m * n; i++)
  this->c[i] = this->c[i]+c1.c[i];
 return *this;
};
int main()
{
 Matrix A(2, 2), B(2, 2),C(2,2);
 A.setMatrix();
 B.setMatrix();
 A.print();
 B.print();
 C = A + B;//C= A.operator+(B);
 C.print();

}
