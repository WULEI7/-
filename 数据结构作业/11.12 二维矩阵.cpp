#include <iostream>
#include <cstdio>
#include <memory>//包含unique_ptr的头文件 
using namespace std;

template <class T> 
class Matrix
{
	public:
		Matrix()=default;//默认构造函数 
		Matrix(int a1,int a2);//含行列数的构造函数 
		T operator()(int i,int j) const;//重载()，用来获取元素的值 
		T& operator()(int i,int j);//重载()，用来修改元素的值 
		int getb1();//获取行数b1 
		int getb2();//获取列数b2 
		void print();//打印矩阵各元素 
		Matrix operator +(Matrix &B);//重载运算符+，矩阵相加 
		Matrix operator -(Matrix &B);//重载运算福-，矩阵相减 
		Matrix operator *(Matrix &B);//重载运算福*，矩阵相乘 
	private:
		int b1,b2;
		unique_ptr<T[]> pointer;
};

template <class T>
Matrix<T>::Matrix(int a1,int a2)//含行列数的构造函数 
{
	b1=a1;b2=a2;
	pointer=unique_ptr<T[]>(new int[b1*b2]);
}

template <class T>
T Matrix<T>::operator()(int i,int j) const//重载()，用来获取元素的值 
{
	return pointer[i*b2+j];
}

template <class T>
T& Matrix<T>::operator()(int i,int j)//重载()，用来修改元素的值 
{
	return pointer[i*b2+j];
}

template <class T>
int Matrix<T>::getb1()//获取行数b1 
{
	return b1;
}

template <class T>
int Matrix<T>::getb2()//获取列数b2 
{
	return b2;
}

template <class T>
void Matrix<T>::print()//打印矩阵各元素 
{
	for(int i=0;i<b1;i++)
	{
		for(int j=0;j<b2;j++)
			printf("%d ",pointer[i*b2+j]);
		printf("\n");
	}
}

template <class T>
Matrix<T> Matrix<T>::operator +(Matrix &B)//重载运算符+，矩阵相加 
{
	if(b1!=B.getb1()||b1!=B.getb2())
		return Matrix();
	Matrix C(b1,b2);
	for(int i=0;i<b1;i++)
		for(int j=0;j<b2;j++)
			C(i,j)=pointer[i*b2+j]+B(i,j);
	return C;
}

template <class T>
Matrix<T> Matrix<T>::operator -(Matrix &B)//重载运算福-，矩阵相减 
{
	if(b1!=B.getb1()||b1!=B.getb2())
		return Matrix();
	Matrix C(b1,b2);
	for(int i=0;i<b1;i++)
		for(int j=0;j<b2;j++)
			C(i,j)=pointer[i*b2+j]-B(i,j);
	return C;
}

template <class T>
Matrix<T> Matrix<T>::operator *(Matrix &B)//重载运算福*，矩阵相乘 
{
	if(b2!=B.getb1())//第二个矩阵的行数等于第一个矩阵的列数时才可以相乘 
		return Matrix();
	Matrix C(b1,b2);
	for(int i=0;i<b1;i++)
		for(int j=0;j<b2;j++)
			C(i,j)=0;
	for(int i=0;i<b1;i++)
		for(int j=0;j<B.getb2();j++)
			for(int k=0;k<b2;k++)
				C(i,j)+=pointer[i*b2+k]*B(k,j);
	return C;
}


int main()
{
	//数据测试 
	Matrix<int> A(2,2);
	int k=0;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
		A(i,j)=++k;
	printf("矩阵A各元素的值为：\n");
	A.print();
	Matrix<int> B(2,2);
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
		B(i,j)=2;
	printf("矩阵B各元素的值为：\n");
	B.print();
	Matrix<int> C=A+B;
	Matrix<int> D=A-B;
	Matrix<int> E=A*B;
	printf("矩阵C各元素的值为：\n");
	C.print();
	printf("矩阵D各元素的值为：\n");
	D.print();
	printf("矩阵E各元素的值为：\n");
	E.print();
	return 0;
}

