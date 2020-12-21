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

void insert_sort(T a[],int n)//直接插入排序 
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


void binary_insert_sort(T a[],int n)//折半插入排序 
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
}//二分插入 


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
	}//对顺序表a作一趟希尔插入排序，和直接插入排序的区别是前后记录位置的增量是d而不是1 
}

void shell_sort(T a[], int n)//希尔排序 
{
	int d[]={5,3,1};//增量序列 
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
	a=a^b;//用位运算交换两个变量的值，则不需要用到额外的变量t 
}

void bubble_sort(T a[],int n)//冒泡排序 
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
	while(L<H)//从表的两端交替地向中间扫描 
	{
		while(L<H&&a[H]>=t)
			H--;
		a[L]=a[H];//将比枢轴记录小的记录移到低端 
		while(L<H&&a[L]<=t)
			L++;
		a[H]=a[L];//将比枢轴记录大的记录移到高端 
	}
	a[L]=t;
	return L;
}//交换顺序表a中子表a[L-H]的记录，枢轴记录到位，并返回其所在位置 

void Qsort(T a[],int L,int H)
{
	if(L<H)
	{
		int loc=partition(a,L,H);//枢轴位置，将当前数组一分为二 
		Qsort(a,L,loc-1);//对低子表递归排序 
		Qsort(a,loc+1,H);//对高子表递归排序 
	}
}

void quick_sort(T a[],int n)//快速排序 
{
	Qsort(a,0,n-1);
}


void select_sort(T a[], int n)//选择排序 
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

void merge_sort_iter(T A[],T B[],int n)//迭代归并排序 
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

void merge_sort_recursive(T A[],T B[],const int s,const int t)//递归归并排序 
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
			j++;//j指向较大的孩子 
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
		swap(a[0],a[i]);//将a[0]和a[i]交换 
		heap_adjust(a,0,i);
	}
}

int main()
{
	int num[]={49,38,65,97,76,13,27};//数据测试 
	int arr[7];
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("直接插入排序：\n");
	insert_sort(arr,7);//直接插入排序 
	printf("直接插入排序的结果为：");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("折半插入排序：\n");
	binary_insert_sort(arr,7);//折半插入排序 
	printf("折半插入排序的结果为：");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("希尔排序：\n");
	shell_sort(arr,7);//希尔排序 
	printf("希尔排序的结果为：");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("冒泡排序：\n");
	bubble_sort(arr,7);//冒泡排序 
	printf("冒泡排序的结果为：");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("快速排序：\n");
	quick_sort(arr,7);//快速排序 
	printf("快速排序的结果为：");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("选择排序：\n");
	select_sort(arr,7);//选择排序 
	printf("选择排序的结果为：");
	print(arr,7);
	printf("\n");
	
	T out[7];
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("迭代归并排序：\n");
	merge_sort_iter(arr,out,7);//迭代归并排序 
	printf("迭代归并排序的结果为：");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	merge_sort_recursive(arr,out,0,6);//递归归并排序 
	printf("递归归并排序的结果为：");
	print(arr,7);
	printf("\n");
	
	for(int i=0;i<7;i++)
		arr[i]=num[i];
	printf("原数组为：");
	print(arr,7);
	printf("堆排序：\n");
	heap_sort(arr,7);//堆排序 
	printf("堆排序的结果为：");
	print(arr,7);
	printf("\n");
	
	return 0;
}
