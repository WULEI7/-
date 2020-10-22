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
		linkedList();//���캯�� 
		virtual ~linkedList();//�������� 
		bool initiate();//��ʼ������ע������ʼ�������ʹ�� 
		bool insert(int i,T e);//����Ԫ�� 
		bool remove(int i);//ɾ��Ԫ�� 
		bool insert_front(T e);//�ײ�����Ԫ�� 
		bool push_back(T e);//β������Ԫ�� 
		bool remove_front();//�ײ�ɾ��Ԫ�� 
		bool pop_back();//β��ɾ��Ԫ�� 
		bool get(int i,T &e);//��ȡԪ�ص�ֵ 
		bool set(int i,T e);//�޸�Ԫ�ص�ֵ 
		int find(T e);//����Ԫ��λ�� 
		int Length();//��ȡ������ 
		void traverse();//˳���ӡ�����������Ϊ�գ������ Empty 
	private:
		node<T> *head;
		int len;
};

template<class T>
linkedList<T>::linkedList(){}//���캯�� 

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
}//�������� 

template<class T>
bool linkedList<T>::initiate()
{
	head=new node<T>;
	if(head==nullptr)
		return false;
	len=0;
	head->next=nullptr;
	return true;
}//��ʼ������ע����������ʼ�������ʹ�� 

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
}//����Ԫ�� 

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
}//ɾ��Ԫ�� 

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
}//�ײ�����Ԫ�� 

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
}//β������Ԫ�� 

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
}//ɾ���ײ�Ԫ�� 

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
}//ɾ��β��Ԫ�� 

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
}//��ȡԪ�ص�ֵ 

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
}//�޸�Ԫ�ص�ֵ 

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
			return temp;//�ҵ�����λ�� 
		p=p->next;
		temp++;
	}
	return 0;//δ�ҵ�����0 
}//����Ԫ��λ�� 

template<class T>
int linkedList<T>::Length()
{
	return len;
}//��ȡ������ 

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
}//˳���ӡ�����������Ϊ�գ������ Empty 


int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	//�������� 
	linkedList<int> L1;
	int n,val;
	if(!L1.initiate())
		return 0;//��ʼ������ 
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		L1.push_back(val);
	}//������β������n��Ԫ�� 
	cout << "Length��" << L1.Length() << endl;
	cout << "data��" ;
	L1.traverse();
	if(L1.insert_front(0))//���ײ�����Ԫ��0 
	{
		cout<<"���ײ�����Ԫ��0"<<endl; 
		cout << "Length��" << L1.Length() << endl;
	    cout << "data��" ;
	    L1.traverse();
	}
	if(L1.push_back(6))//��β������Ԫ��6 
	{
		cout<<"��β������Ԫ��6"<<endl;
	    cout << "Length��" << L1.Length() << endl;
	    cout << "data��" ;
	    L1.traverse();
	}
	if(L1.remove_front())//ɾ���ײ�Ԫ�� 
	{
		cout<<"ɾ���ײ�Ԫ��"<<endl; 
		cout << "Length��" << L1.Length() << endl;
	    cout << "data��" ;
	    L1.traverse();
	}
	if(L1.pop_back())//ɾ��β��Ԫ�� 
	{
		cout<<"ɾ��β��Ԫ��"<<endl;
		cout << "Length��" << L1.Length() << endl;
	    cout << "data��" ;
	    L1.traverse();
	}
	cin>>n;
	if(L1.remove(n))//ɾ��λ��Ϊn��Ԫ�� 
	{
		cout<<"ɾ��λ��Ϊ"<<n<<"��Ԫ��"<<endl;
	    cout<< "Length��" << L1.Length()<< endl;
	    cout<< "data��" ;
	    L1.traverse();
	}
	cin>>n>>val;
	if (L1.insert(n,val))//��λ��n����Ԫ��val 
	{
		cout<<"��λ��"<<n<<"����Ԫ��"<<val<<endl;
	    cout<< "Length��" << L1.Length()<< endl;
	    cout<< "data��" ;
	    L1.traverse();
	}
	if(L1.find(2))//����Ԫ��2 
		cout<<"��λ��"<<L1.find(2)<<"�ҵ�Ԫ��2"<<endl;
	else
		cout<<"δ�ҵ�Ԫ��2"<<endl;
	if(L1.find(6))//����Ԫ��6 
		cout<<"��λ��"<<L1.find(6)<<"�ҵ�Ԫ��6"<<endl;
	else
		cout<<"δ�ҵ�Ԫ��6"<<endl;
	if(L1.get(4,val))//��ȡλ��4Ԫ�ص�ֵ 
		cout<<"λ��4Ԫ�ص�ֵΪ"<<val<<endl;
	if(L1.set(5,9))//��λ��5Ԫ�ص�ֵ�޸�Ϊ9 
	{
		cout<<"��λ��5Ԫ�ص�ֵ�޸�Ϊ9"<<endl;
	    cout<< "Length��" << L1.Length()<< endl;
	    cout<< "data��" ;
	    L1.traverse();
	}
	return 0;
}
