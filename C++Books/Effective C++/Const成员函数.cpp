#include<iostream>
using namespace std;
//������Ա�������ֻ�ǳ����Բ�ͬ�����Ա����� 
class TextBlock 
{
	public:
		//size_t��һ���������ص�unsigned����
		//sizeof���صľ���size_t���ͣ������±�Ҳ��size_t���� 
		const char& operator[](std::size_t position) const
		{
			return text[position];
		}
		char& operator[](std::size_t position)
		{
			return text[position];
		}
		//����������char*,�޷���char*ת��Ϊstring
		TextBlock(string s):text(s){
		}
		private:
			std::string text;
}; 
int main()
{
	TextBlock tb("Hello");
	std::cout<<tb[0]<<endl;//����non-const 
	const TextBlock ctb("World");
	std::cout<<ctb[0]<<endl;//����const 
} 
