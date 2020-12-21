#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef int T;

void print(T a[],const int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void insert_sort(T a[],int n)//ֱ�Ӳ������� 
{
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			T t=a[i];
			a[i]=a[i-1];
			int j;
			for(j=i-2;j>=0&&t<a[j];j--)
				a[j+1]=a[j];
			a[j+1]=t;
		}
	print(a,n);
	}
}


void binary_insert_sort(T a[],int n)//�۰�������� 
{
	int l,h,m,j;
	for(int i=1;i<n;i++)
	{
		T t=a[i];
		if(a[i]<a[i-1])
		{
			l=0;h=i-1;
			while(l<=h)
			{
				m=(l+h)/2;
				if(t<a[m])
					h=m-1;
				else
					l=m+1;
			}
			for(j=i-1;j>=h+1;j--)
				a[j+1]=a[j];
			a[h+1]=t;
		}
		print(a,n);
	}
}//���ֲ��� 


void shell_insert(T a[],int n,int d)
{
	for(int i=d;i<n;i++) 
	{
		if(a[i]<a[i-d])
		{
			T t=a[i];
			a[i]=a[i-d];
			int j;
			for (j=i-2*d;j>=0&&t<a[j];j-=d)
				a[j+d]=a[j];
			a[j+d]=t;
		}
	}//��˳���a��һ��ϣ���������򣬺�ֱ�Ӳ��������������ǰ���¼λ�õ�������d������1 
}

void shell_sort(T a[], int n)//ϣ������ 
{
	int d[]={5,3,1};//�������� 
	for(int i=0;i<3;i++)
	{
		shell_insert(a,n,d[i]);
		print(a,n);
	}
}


void swap(T &a, T &b)
{
	//T t=a;a=b;b=t;
	a=a^b;
	b=a^b;
	a=a^b;//��λ���㽻������������ֵ������Ҫ�õ�����ı���t 
}

void bubble_sort(T a[],int n)//ð������ 
{
	for(int i=n-1;i>0;i--)
	{
		int flag=0;
		for(int j=0;j<i;j++)
			if(a[j+1]<a[j])
			{
				swap(a[j+1],a[j]);
				flag=1;
			}
		if(flag==0) break;
		print(a,n);
	}
}


int partition(T a[],int L,int H)
{
	T t=a[L];
	while(L<H)//�ӱ�����˽�������м�ɨ�� 
	{
		while(L<H&&a[H]>=t)
			H--;
		a[L]=a[H];//���������¼С�ļ�¼�Ƶ��Ͷ� 
		while(L<H&&a[L]<=t)
			L++;
		a[H]=a[L];//���������¼��ļ�¼�Ƶ��߶� 
	}
	a[L]=t;
	return L;
}//����˳���a���ӱ�a[L-H]�ļ�¼�������¼��λ��������������λ�� 

void Qsort(T a[],int L,int H)
{
	if(L<H)
	{
		int loc=partition(a,L,H);//����λ�ã�����ǰ����һ��Ϊ�� 
		Qsort(a,L,loc-1);//�Ե��ӱ�ݹ����� 
		Qsort(a,loc+1,H);//�Ը��ӱ�ݹ����� 
	}
}

void quick_sort(T a[],int n)//�������� 
{
	Qsort(a,0,n-1);
}


void select_sort(T a[], int n)//ѡ������ 
{
	int minn=0;
	for (int i=0;i<n-1;i++)
	{
		minn=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[minn]) minn=j;
		if (minn!=i)
			swap(a[i],a[minn]);
		print(a,n);
	}
}


void merge(const T data[],T out[],int s,int M,int N)
{
	int i=s,j=M+1,k=s;
	while (i<=M&&j<=N)
	{
		if(data[i]<data[j])
			out[k++]=data[i++];
		else 
			out[k++]=data[j++];
	}
	while(i<=M) out[k++]=data[i++];
	while(j<=N) out[k++]=data[j++];
}

int min(int a,int b)
{
	return a<b?a:b;
}

void copy(T A[],T B[],int n)
{
	for(int i=0;i<n;i++)
		B[i]=A[i];
}

void merge_sort_iter(T A[],T B[],int n)//�����鲢���� 
{
	for(int width=1;width<n;width*=2)
	{
		for(int i=0;i<n;i=i+2*width)
			merge(A,B,i,i+width-1,min(i+2*width-1,n-1));
		copy(B,A,n);
		print(B,n);
	}
}

void copy2(T A[],T B[],const int s,const int t)
{
	for(int i=s;i<=t;i++)
		B[i]=A[i];
}

void merge_sort_recursive(T A[],T B[],const int s,const int t)//�ݹ�鲢���� 
{
	if(s==t) return;
	merge_sort_recursive(A,B,s,(s+t)/2);
	merge_sort_recursive(A,B,(s+t)/2+1,t);
	merge(A,B,s,(s+t)/2,t);
	copy2(B,A,s,t);
}


void heap_adjust(T data[],int s,int n)
{
	if(2*s+1>=n) return;
	T t=data[s];
	int m=n-1;
	for(int j=2*s+1;j<n;)
	{
		if(j<m&&data[j]<data[j+1])
			j++;//jָ��ϴ�ĺ��� 
		if(!(t<data[j])) break;
		data[s]=data[j];
		s=j;j=2*j+1;
	}
	data[s]=t;
}

void heap_sort(T a[],int n)
{
	for(int i=floor((n-1-1)/2);i>=0;i--)
		heap_adjust(a,i,n);
	for(int i=n-1;i>0;i--)
	{
		swap(a[0],a[i]);//��a[0]��a[i]���� 
		heap_adjust(a,0,i);
	}
}

int main()
{
	int num[]={49,38,65,97,76,13,27};//���ݲ��� 
	int arr[7];
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("ֱ�Ӳ�������\n");
	insert_sort(arr,7);//ֱ�Ӳ������� 
	printf("ֱ�Ӳ�������Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("�۰��������\n");
	binary_insert_sort(arr,7);//�۰�������� 
	printf("�۰��������Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("ϣ������\n");
	shell_sort(arr,7);//ϣ������ 
	printf("ϣ������Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("ð������\n");
	bubble_sort(arr,7);//ð������ 
	printf("ð������Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("��������\n");
	quick_sort(arr,7);//�������� 
	printf("��������Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("ѡ������\n");
	select_sort(arr,7);//ѡ������ 
	printf("ѡ������Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	T out[7];
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("�����鲢����\n");
	merge_sort_iter(arr,out,7);//�����鲢���� 
	printf("�����鲢����Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	merge_sort_recursive(arr,out,0,6);//�ݹ�鲢���� 
	printf("�ݹ�鲢����Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("ԭ����Ϊ��");
	print(arr,7);
	printf("������\n");
	heap_sort(arr,7);//������ 
	printf("������Ľ��Ϊ��");
	print(arr,7);
	printf("\n");
	
	return 0;
}
