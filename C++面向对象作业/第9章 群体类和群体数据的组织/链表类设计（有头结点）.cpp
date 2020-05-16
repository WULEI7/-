#include <iostream>
#include <iomanip>
using namespace std;

typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

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
    bool remove( int pos, int& value );
    void print();//˳���ӡ����������ǵ�����Ϊ�գ������ Empty
    int Length();//���ص������ȡ�����ǵ�����Ϊ�գ��򷵻�-1
private:
    LList *head;
    int len;
};


linkedList::linkedList(){}

linkedList::~linkedList()
{
	LList *t,*p=head->next;
	while(p!=nullptr)
	{
		t=p->next;
		delete p;
		p=t;
	}
	delete head;
}

void linkedList::insert(int value)
{
	LList *p=head;
	while(p->next!=nullptr)
		p=p->next;
	p->next=new LList;
	p=p->next;
	p->data=value;
	p->next=nullptr;
	len++;
}

bool linkedList::initiate()
{
	head=new LList;
	if(head==nullptr)
		return false;
	len=0;
	head->next=nullptr;
	return true;
}

bool linkedList::isEmpty()
{
	if(len==0)
		return true;
	else
		return false;
}

bool linkedList::remove(int pos,int &value)
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
			LList *p=head;
			while(temp<pos-1)
			{
				p=p->next;
				temp++;
			}
			LList *q=p;
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

int linkedList::Length()
{
	return len;
}


void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp!=nullptr)
    {
        cout <<tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}


int main() 
{
    linkedList L1;
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
