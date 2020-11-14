#include <iostream>
#include <cstdio>
#include <memory>//����unique_ptr��ͷ�ļ� 
using namespace std;

template <class T> 
class Matrix
{
	public:
		Matrix()=default;//Ĭ�Ϲ��캯�� 
		Matrix(int a1,int a2);//���������Ĺ��캯�� 
		T operator()(int i,int j) const;//����()��������ȡԪ�ص�ֵ 
		T& operator()(int i,int j);//����()�������޸�Ԫ�ص�ֵ 
		int getb1();//��ȡ����b1 
		int getb2();//��ȡ����b2 
		void print();//��ӡ�����Ԫ�� 
		Matrix operator +(Matrix &B);//���������+��������� 
		Matrix operator -(Matrix &B);//�������㸣-��������� 
		Matrix operator *(Matrix &B);//�������㸣*��������� 
	private:
		int b1,b2;
		unique_ptr<T[]> pointer;
};

template <class T>
Matrix<T>::Matrix(int a1,int a2)//���������Ĺ��캯�� 
{
	b1=a1;b2=a2;
	pointer=unique_ptr<T[]>(new int[b1*b2]);
}

template <class T>
T Matrix<T>::operator()(int i,int j) const//����()��������ȡԪ�ص�ֵ 
{
	return pointer[i*b2+j];
}

template <class T>
T& Matrix<T>::operator()(int i,int j)//����()�������޸�Ԫ�ص�ֵ 
{
	return pointer[i*b2+j];
}

template <class T>
int Matrix<T>::getb1()//��ȡ����b1 
{
	return b1;
}

template <class T>
int Matrix<T>::getb2()//��ȡ����b2 
{
	return b2;
}

template <class T>
void Matrix<T>::print()//��ӡ�����Ԫ�� 
{
	for(int i=0;i<b1;i++)
	{
		for(int j=0;j<b2;j++)
			printf("%d ",pointer[i*b2+j]);
		printf("\n");
	}
}

template <class T>
Matrix<T> Matrix<T>::operator +(Matrix &B)//���������+��������� 
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
Matrix<T> Matrix<T>::operator -(Matrix &B)//�������㸣-��������� 
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
Matrix<T> Matrix<T>::operator *(Matrix &B)//�������㸣*��������� 
{
	if(b2!=B.getb1())//�ڶ���������������ڵ�һ�����������ʱ�ſ������ 
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
	//���ݲ��� 
	Matrix<int> A(2,2);
	int k=0;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
		A(i,j)=++k;
	printf("����A��Ԫ�ص�ֵΪ��\n");
	A.print();
	Matrix<int> B(2,2);
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++)
		B(i,j)=2;
	printf("����B��Ԫ�ص�ֵΪ��\n");
	B.print();
	Matrix<int> C=A+B;
	Matrix<int> D=A-B;
	Matrix<int> E=A*B;
	printf("����C��Ԫ�ص�ֵΪ��\n");
	C.print();
	printf("����D��Ԫ�ص�ֵΪ��\n");
	D.print();
	printf("����E��Ԫ�ص�ֵΪ��\n");
	E.print();
	return 0;
}

