#include <iostream>
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
    virtual ~linkedList();//析构函数，注意要链表中所有节点的资源
    void insert( int value );//警告：必须初始化才能使用！
    bool initiate();//初始化单链表，使用new操作创建头结点。如果创建失败，则返回false，否则返回true
    bool isEmpty();//判断单链表是否为空
    //删除单链表中第pos个元素结点，并将删除的节点的值存在value中。
    //注意：如果链表为空、删除位置大于链表长度、以及删除位置为0的情况，需要终止删除并输出相应信息
    bool remove( int pos, T& value );
    void print();//顺序打印单链表，如果是单链表为空，则输出 Empty
    int Length();//返回单链表长度。如果是单链表为空，则返回-1
private:
    node<T> *head;
    int len;
};

template<class T>
linkedList<T>::linkedList(){}

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
}

template<class T>
void linkedList<T>::insert(int value)
{
	node<T> *p=head;
	while(p->next!=nullptr)
		p=p->next;
	p->next=new node<T>;
	p=p->next;
	p->data=value;
	p->next=nullptr;
	len++;
}

template<class T>
bool linkedList<T>::initiate()
{
	head=new node<T>;
	if(head==nullptr)
		return false;
	len=0;
	head->next=nullptr;
	return true;
}

template<class T>
bool linkedList<T>::isEmpty()
{
	if(len==0)
		return true;
	else
		return false;
}

template<class T>
bool linkedList<T>::remove(int pos,T &value)
{
	if(!isEmpty())
	{
		if(pos<=0)
		{
			cout<<"pos <= 0, failed"<<endl;
			return false;
		}
		else if(pos>len)
		{
			cout<<"pos > len, failed"<<endl;
			return false;
		}
		else
		{
			int temp=0;//有头结点，不存值 
			node<T> *p=head;
			while(temp<pos-1)
			{
				p=p->next;
				temp++;
			}
			node<T> *q=p;
			q=q->next;
			value=q->data;
			p->next=q->next;
			delete q;
			len--;
			return true;
		}
	}
	return false;
}

template<class T>
int linkedList<T>::Length()
{
	return len;
}

template<class T>
void linkedList<T>::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    node<T>* tmp = head->next;
    while(tmp!=nullptr)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main() 
{
    linkedList<int> L1;
    int n;
    int val;
    //初始化链表
    if(!L1.initiate())
        return 0;

    cin>>n;//输入链表中数据个数
    for(int i=0; i<n; i++) //输入n个数，并插入链表
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length：" << L1.Length() << endl;//输出链表长度
    cout << "data：" ;
    L1.print();//打印链表

    cin>>n;//输入需要删除的数据的位置
    if (L1.remove(n,val))
    {
        //删除位置n的数据，并将删除的数据值放在val中
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length：" << L1.Length()<< endl;//输出链表长度
        cout<< "data：" ;
        L1.print();//打印链表
    }

    return 0;
}
