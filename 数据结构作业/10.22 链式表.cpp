#include <iostream>
#include <cstdio> 
#include <iomanip>
using namespace std;

template<class T> struct node
{
	T data;
	node<T>* next;
};

template<class T>
class linkedList
{
	public:
		linkedList();//构造函数 
		virtual ~linkedList();//析构函数 
		bool initiate();//初始化链表，注意必须初始化后才能使用 
		bool insert(int i,T e);//插入元素 
		bool remove(int i);//删除元素 
		bool insert_front(T e);//首部插入元素 
		bool push_back(T e);//尾部插入元素 
		bool remove_front();//首部删除元素 
		bool pop_back();//尾部删除元素 
		bool get(int i,T &e);//获取元素的值 
		bool set(int i,T e);//修改元素的值 
		int find(T e);//查找元素位置 
		int Length();//获取链表长度 
		void traverse();//顺序打印链表，如果链表为空，则输出 Empty 
	private:
		node<T> *head;
		int len;
};

template<class T>
linkedList<T>::linkedList(){}//构造函数 

template<class T>
linkedList<T>::~linkedList()
{
	node<T> *t,*p=head->next;
	while(p!=nullptr)
	{
		t=p->next;
		delete p;
		p=t;
	}
	delete head;
}//析构函数 

template<class T>
bool linkedList<T>::initiate()
{
	head=new node<T>;
	if(head==nullptr)
		return false;
	len=0;
	head->next=nullptr;
	return true;
}//初始化链表，注意链表必须初始化后才能使用 

template<class T>
bool linkedList<T>::insert(int i,T e)
{
	if(i<=0)
	{
		cout<<"pos <= 0, failed"<<endl;
		return false;
	}
	else if(i>len+1)
	{
		cout<<"pos > len+1, failed"<<endl;
		return false;
	}
	else if(i==len+1)
	{
		push_back(e);
		return true;
	}
	else
	{
		int temp=0;
		node<T> *p=head;
		while(temp<i-1)
		{
			p=p->next;
			temp++;
		}
		node<T> *q=p->next;
		p->next=new node<T>;
		p=p->next;
		p->data=e;
		p->next=q;
		len++;
		return true;
	}
}//插入元素 

template<class T>
bool linkedList<T>::remove(int i)
{
	if(i<=0)
	{
		cout<<"pos <= 0, failed"<<endl;
		return false;
	}
	else if(i>len)
	{
		cout<<"pos > len, failed"<<endl;
		return false;
	}
	else
	{
		int temp=0;
		node<T> *p=head;
		while(temp<i-1)
		{
			p=p->next;
			temp++;
		}
		node<T> *q=p;
		q=q->next;
		p->next=q->next;
		len--;
		return true;
	}
}//删除元素 

template<class T>
bool linkedList<T>::insert_front(T e)
{
	node<T> *p=head,*q=head->next;
	p->next=new node<T>;
	p=p->next;
	p->data=e;
	p->next=q;
	len++;
	return true;
}//首部插入元素 

template<class T>
bool linkedList<T>::push_back(T e)
{
	node<T> *p=head;
	while(p->next!=nullptr)
		p=p->next;
	p->next=new node<T>;
	p=p->next;
	p->data=e;
	p->next=nullptr;
	len++;
	return true;
}//尾部插入元素 

template<class T>
bool linkedList<T>::remove_front()
{
	if(len==0)
		return false;
	node<T> *p=head,*q=head;
	q=q->next;
	p->next=q->next;
	len--;
	return true;
}//删除首部元素 

template<class T>
bool linkedList<T>::pop_back()
{
	if(len==0)
	return false;
	int temp=0;
	node<T> *p=head;
	while(temp<len-1)
	{
		p=p->next;
		temp++;
	}
	p->next=nullptr;
	len--;
	return true;
}//删除尾部元素 

template<class T>
bool linkedList<T>::get(int i,T &e)
{
	if(i<=0||i>len)
		return false;
	node<T> *p=head;
	for(int j=0;j<i;j++)
		p=p->next;
	e=p->data;
	return true;
}//获取元素的值 

template<class T>
bool linkedList<T>::set(int i,T e)
{
	if(i<=0||i>len)
		return false;
	node<T> *p=head;
	for(int j=0;j<i;j++)
		p=p->next;
	p->data=e;
	return true;
}//修改元素的值 

template<class T>
int linkedList<T>::find(T e)
{
	if(len==0)
		return 0;
	int temp=1;
	node<T> *p=head->next;
	while(temp<len-1)
	{
		if(p->data==e)
			return temp;//找到返回位置 
		p=p->next;
		temp++;
	}
	return 0;//未找到返回0 
}//查找元素位置 

template<class T>
int linkedList<T>::Length()
{
	return len;
}//获取链表长度 

template<class T>
void linkedList<T>::traverse()
{
	if(len==0)
	{
		cout<<"Empty"<<endl;
		return;
	}
	node<T>* tmp=head->next;
	while(tmp!=nullptr)
	{
		cout<<tmp->data<<" ";
		tmp=tmp->next;
	}
	cout<<endl;
}//顺序打印链表，如果链表为空，则输出 Empty 


int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	//测试数据 
	linkedList<int> L1;
	int n,val;
	if(!L1.initiate())
		return 0;//初始化链表 
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		L1.push_back(val);
	}//依次在尾部插入n个元素 
	cout << "Length：" << L1.Length() << endl;
	cout << "data：" ;
	L1.traverse();
	if(L1.insert_front(0))//在首部插入元素0 
	{
		cout<<"在首部插入元素0"<<endl; 
		cout << "Length：" << L1.Length() << endl;
	    cout << "data：" ;
	    L1.traverse();
	}
	if(L1.push_back(6))//在尾部插入元素6 
	{
		cout<<"在尾部插入元素6"<<endl;
	    cout << "Length：" << L1.Length() << endl;
	    cout << "data：" ;
	    L1.traverse();
	}
	if(L1.remove_front())//删除首部元素 
	{
		cout<<"删除首部元素"<<endl; 
		cout << "Length：" << L1.Length() << endl;
	    cout << "data：" ;
	    L1.traverse();
	}
	if(L1.pop_back())//删除尾部元素 
	{
		cout<<"删除尾部元素"<<endl;
		cout << "Length：" << L1.Length() << endl;
	    cout << "data：" ;
	    L1.traverse();
	}
	cin>>n;
	if(L1.remove(n))//删除位置为n的元素 
	{
		cout<<"删除位置为"<<n<<"的元素"<<endl;
	    cout<< "Length：" << L1.Length()<< endl;
	    cout<< "data：" ;
	    L1.traverse();
	}
	cin>>n>>val;
	if (L1.insert(n,val))//在位置n插入元素val 
	{
		cout<<"在位置"<<n<<"插入元素"<<val<<endl;
	    cout<< "Length：" << L1.Length()<< endl;
	    cout<< "data：" ;
	    L1.traverse();
	}
	if(L1.find(2))//查找元素2 
		cout<<"在位置"<<L1.find(2)<<"找到元素2"<<endl;
	else
		cout<<"未找到元素2"<<endl;
	if(L1.find(6))//查找元素6 
		cout<<"在位置"<<L1.find(6)<<"找到元素6"<<endl;
	else
		cout<<"未找到元素6"<<endl;
	if(L1.get(4,val))//获取位置4元素的值 
		cout<<"位置4元素的值为"<<val<<endl;
	if(L1.set(5,9))//将位置5元素的值修改为9 
	{
		cout<<"将位置5元素的值修改为9"<<endl;
	    cout<< "Length：" << L1.Length()<< endl;
	    cout<< "data：" ;
	    L1.traverse();
	}
	return 0;
}
