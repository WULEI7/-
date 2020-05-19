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
    linkedList();//���캯��
    virtual ~linkedList();//����������ע��Ҫ���������нڵ����Դ
    void insert( int value );//���棺�����ʼ������ʹ�ã�
    bool initiate();//��ʼ��������ʹ��new��������ͷ��㡣�������ʧ�ܣ��򷵻�false�����򷵻�true
    bool isEmpty();//�жϵ������Ƿ�Ϊ��
    //ɾ���������е�pos��Ԫ�ؽ�㣬����ɾ���Ľڵ��ֵ����value�С�
    //ע�⣺�������Ϊ�ա�ɾ��λ�ô��������ȡ��Լ�ɾ��λ��Ϊ0���������Ҫ��ֹɾ���������Ӧ��Ϣ
    bool remove( int pos, T& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
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
			int temp=0;//��ͷ��㣬����ֵ 
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
    //��ʼ������
    if(!L1.initiate())
        return 0;

    cin>>n;//�������������ݸ���
    for(int i=0; i<n; i++) //����n����������������
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��" ;
    L1.print();//��ӡ����

    cin>>n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n,val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }

    return 0;
}
