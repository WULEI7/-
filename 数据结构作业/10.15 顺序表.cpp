#include <iostream>
#include <cstdio>
using namespace std;
template<class T>
class SqList
{
	public:
		SqList(int cap=100);//˳����ʼ�� 
		bool insert(int i,T e);//����Ԫ�� 
		bool remove(int i);//ɾ��Ԫ�� 
		bool push_back(T e);//β������ 
		bool pop_back();//β��ɾ�� 
		bool insert_front(T e);//ͷ������ 
		bool remove_front();//ͷ��ɾ�� 
		bool get(int i,T &e);//��ȡԪ�ص�ֵ 
		bool set(int i,T e);//�޸�Ԫ�ص�ֵ 
		int size();//��ȡ��Ĵ�С 
		int find(T e);//����Ԫ�� 
		void traverse();//����˳��� 
	private:
		T *data;
		int capacity,n;
		bool realloc();//����ռ� 
};//˳��� 

template<class T>
SqList<T>::SqList(int cap)
{
	data=new T[cap];
	capacity=cap;
	n=0;
}

template<class T>
bool SqList<T>::insert(int i,T e)
{
	if(i<1||i>n+1)
		return false;//���i�Ƿ�Ϸ� 
	if(n>=capacity)
		if(!realloc()) return false;//��������ڴ�� 
	for(int j=n;j>=i;j--)
		data[j]=data[j-1];
	data[i-1]=e;
	n++;
}

template<class T>
bool SqList<T>::remove(int i)
{
	if(i<1||i>n)
		return false;
	for(int j=i;j<n;j++)
		data[j-1]=data[j];
	n--;
	return true;
}

template<class T>
bool SqList<T>::push_back(T e)
{
	if(n>=capacity)
		if(!realloc()) return false;
	data[n++]=e;
	return true;
}

template<class T>
bool SqList<T>::pop_back()
{
	if(n<=0)
		return false;
	n--;
	return true;
}

template<class T>
bool SqList<T>::insert_front(T e)
{
	if(n>=capacity)
		if(!realloc()) return false;
	for(int j=n;j>=1;j--)
		data[j]=data[j-1];
	data[0]=e;
	n++;
}

template<class T>
bool SqList<T>::remove_front()
{
	if(n<=0)
		return false;
	for(int i=0;i<n;i++)
		data[i]=data[i+1];
	n--;
	return true;
}

template<class T>
bool SqList<T>::get(int i,T &e)
{
	if(i<1||i>n)
		return false;
	e=data[i-1];
	return true;
}

template<class T>
bool SqList<T>::set(int i,T e)
{
	if(i<1||i>n)
		return false;
	data[i-1]=e;
	return true;
}

template<class T>
int SqList<T>::size()
{
	return n;
}

template<class T>
int SqList<T>::find(T e)
{
	for(int i=0;i<n;i++)
		if(data[i]==e)
			return i+1;//�ҵ�����λ�� 
	return 0;//δ�ҵ�����0 
}

template<class T>
void SqList<T>::traverse()
{
	if(n==0)
	{
		cout<<"���ǿյ�"<<endl;
		return;
	}
	cout<<"����Ԫ�أ�";
	for(int i=0;i<n;i++)
		cout<<data[i]<<" "; 
	cout<<endl;
}

template<class T>
bool SqList<T>::realloc()
{
	T *p=new T[2*capacity];
	if(!p) return false;
	for(int i=0;i<capacity;i++)
		p[i]=data[i];
	capacity*=2;
	delete[] data;
	data=p;
	return true;
}


int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	//���ݲ��� 
	SqList<int> L;
	int n,val;
	n=5;
	for(int i=1;i<=n;i++)
	{
		L.insert(i,i);
	}//n=5,���β���Ԫ��1,2,3,4,5 
	cout<<"��Ĵ�С��"<<L.size()<<endl;
	L.traverse();
	L.push_back(6);//β������Ԫ��6 
	cout<<"��Ĵ�С��"<<L.size()<<endl;
	L.traverse();
	L.insert_front(0);//�ײ�����Ԫ��0 
	cout<<"��Ĵ�С��"<<L.size()<<endl;
	L.traverse();
	L.remove(3);//ɾ����3��Ԫ�� 
	cout<<"��Ĵ�С��"<<L.size()<<endl;
	L.traverse();
	L.set(1,1);//����1��Ԫ�ص�ֵ�޸�Ϊ1 
	L.set(2,2);//����2��Ԫ�ص�ֵ�޸�Ϊ2 
	cout<<"����Ԫ��λ�ã�0��ʾδ�ҵ�����"<<endl;
	cout<<"Ԫ��2��"<<L.find(2)<<endl;
	cout<<"Ԫ��3��"<<L.find(3)<<endl;
	cout<<"Ԫ��4��"<<L.find(4)<<endl;
	cout<<"��Ĵ�С��"<<L.size()<<endl;
	L.traverse();
	L.get(3,val);//��ȡ��3��Ԫ�ص�ֵ 
	cout<<"��3��Ԫ�ص�ֵ��"<<val<<endl;
	L.pop_back();//ɾ��β��Ԫ�� 
	cout<<"��Ĵ�С��"<<L.size()<<endl;
	L.traverse();
	L.remove_front();//ɾ���ײ�Ԫ�� 
	cout<<"��Ĵ�С��"<<L.size()<<endl;
	L.traverse();
	for(int i=1;i<=4;i++)
	{
		L.pop_back();//ɾ��β��Ԫ�� 
		cout<<"��Ĵ�С��"<<L.size()<<endl;
		L.traverse();
	}
	return 0;
}
