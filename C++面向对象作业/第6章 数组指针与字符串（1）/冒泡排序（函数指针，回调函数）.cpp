#include <iostream>
#include <cstring>
using namespace std;

int cmpGT(const int *p1,const int *p2)
{
//ʵ�������Ƚϣ�������ڣ��򷵻�1�������򷵻�0��С���򷵻�-1 
	if(*p1>*p2) return 1;
	else if(*p1==*p2) return 0;
	else return -1;
}

int cmpLT(const int *p1,const int *p2)
{
//ʵ�������Ƚϣ�������ڣ��򷵻�-1�������򷵻�0��С���򷵻�1 
	if(*p1>*p2) return -1;
	else if(*p1==*p2) return 0;
	else return 1;
}

void swap(int *p1,int *p2)
{
//ʵ���������α�����ֵ���� 
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}

void bubble(int *base,int (*cmp)(const int *,const int *))
{
//�������ﲹ��ð�����������main�����ж�bubble�����ĵ��ã������βε����� 
	for(int t=0;t<10-1;t++)
		for(int i=0;i<10-1-t;i++)
			if(cmp(base+i,base+i+1)==1)
				swap(base+i,base+i+1);
}

int main()
{
	int arr[]={1,3,5,7,9,2,4,6,8,0};
	int i=0;
	bubble(arr,cmpGT);
	for(i=0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	bubble(arr,cmpLT);
	for(i=0;i<10;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
