#include <iostream>
#include <cstdio>
using namespace std;
template<class T>
class SqList
{
	public:
		SqList(int cap=100);//顺序表初始化 
		bool insert(int i,T e);//插入元素 
		bool remove(int i);//删除元素 
		bool push_back(T e);//尾部插入 
		bool pop_back();//尾部删除 
		bool insert_front(T e);//头部插入 
		bool remove_front();//头部删除 
		bool get(int i,T &e);//获取元素的值 
		bool set(int i,T e);//修改元素的值 
		int size();//获取表的大小 
		int find(T e);//查找元素 
		void traverse();//遍历顺序表 
	private:
		T *data;
		int capacity,n;
		bool realloc();//分配空间 
};//顺序表 

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
		return false;//检查i是否合法 
	if(n>=capacity)
		if(!realloc()) return false;//分配更大内存块 
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
			return i+1;//找到返回位置 
	return 0;//未找到返回0 
}

template<class T>
void SqList<T>::traverse()
{
	if(n==0)
	{
		cout<<"表是空的"<<endl;
		return;
	}
	cout<<"表中元素：";
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
	//数据测试 
	SqList<int> L;
	int n,val;
	n=5;
	for(int i=1;i<=n;i++)
	{
		L.insert(i,i);
	}//n=5,依次插入元素1,2,3,4,5 
	cout<<"表的大小："<<L.size()<<endl;
	L.traverse();
	L.push_back(6);//尾部插入元素6 
	cout<<"表的大小："<<L.size()<<endl;
	L.traverse();
	L.insert_front(0);//首部插入元素0 
	cout<<"表的大小："<<L.size()<<endl;
	L.traverse();
	L.remove(3);//删除第3个元素 
	cout<<"表的大小："<<L.size()<<endl;
	L.traverse();
	L.set(1,1);//将第1个元素的值修改为1 
	L.set(2,2);//将第2个元素的值修改为2 
	cout<<"查找元素位置（0表示未找到）："<<endl;
	cout<<"元素2："<<L.find(2)<<endl;
	cout<<"元素3："<<L.find(3)<<endl;
	cout<<"元素4："<<L.find(4)<<endl;
	cout<<"表的大小："<<L.size()<<endl;
	L.traverse();
	L.get(3,val);//获取第3个元素的值 
	cout<<"第3个元素的值："<<val<<endl;
	L.pop_back();//删除尾部元素 
	cout<<"表的大小："<<L.size()<<endl;
	L.traverse();
	L.remove_front();//删除首部元素 
	cout<<"表的大小："<<L.size()<<endl;
	L.traverse();
	for(int i=1;i<=4;i++)
	{
		L.pop_back();//删除尾部元素 
		cout<<"表的大小："<<L.size()<<endl;
		L.traverse();
	}
	return 0;
}
