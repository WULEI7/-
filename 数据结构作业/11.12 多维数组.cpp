#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>//用于存取变长参数表 

#define MAX_DIM 8//假设数组维数的最大值为8 

typedef struct
{
	int *base;//数组元素基址 
	int dim;//数组维数 
	int *bounds;//数组维数基址,例如维数dim=3，bounds[0]=2，bounds[1]=3，bounds[2]=4，表示2页3行4列的数组 
	int *constants;//数组映像函数常量基址 
	/*  例如对于2页3行4列的数组,有constants[2]=1，constants[1]=4，constants[0]=12， 
	    给定一个下标A[0][1][2]，0*12+1*4+2*1=6，元素存取在当前数组的第6个位置，再加上base即可找到它的地址 
	*/ 
}Array;


bool init(Array &A,int dim,...)//构造数组 
{
	if(dim<1||dim>MAX_DIM)
		return false;
	A.dim=dim;
	A.bounds=(int *)malloc(dim*sizeof(int));
	if(!A.bounds) return false;
	int total=1;//求元素总数 
	va_list list;//存放变长参数表信息的数组list 
	va_start(list,dim);
	for(int i=0;i<dim;i++)
	{
		A.bounds[i]=va_arg(list,int);
		if(A.bounds[i]<=0)
			return false;
		total*=A.bounds[i];
	}
	va_end(list);
	A.base=(int *)malloc(total*sizeof(int));
	if(!A.base) return false;
	A.constants=(int *)malloc(dim*sizeof(int));
	if(!A.constants) return false;
	A.constants[dim-1]=1;//最后一维为1，指针的增减以元素的大小为单位 
	for(int i=dim-2;i>=0;i--)
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];
	return true;
}

bool destroy(Array &A)//销毁数组 
{
	if(!A.base) return false;
	free(A.base); A.base=NULL;
	if(!A.bounds) return false;
	free(A.bounds); A.bounds=NULL;
	if(!A.constants) return false;
	free(A.constants); A.constants=NULL;
	return true;
}

bool locate(Array &A,va_list list,int &off)//求元素在数组A中的相对地址off 
{
	off=0;
	for(int i=0;i<A.dim;i++)
	{
		int temp=va_arg(list,int);
		if(temp<0||temp>=A.bounds[i]) return false;
		off+=A.constants[i]*temp;
	}
	return true;
}

bool value(Array &A,int &e,...)//将e赋值为所指定的A的元素值 
{
	va_list list;
	va_start(list,e);
	int off=0;
	if(!locate(A,list,off)) return false;
	e=*(A.base+off);
	va_end(list);
	return true;
}

bool assign(Array &A,int e,...)//将e赋值给所指定的A的元素 
{
	va_list list;
	va_start(list,e);
	int off=0;
	if(!locate(A,list,off)) return false;
	*(A.base+off)=e;
	va_end(list);
	return true;
}

void print(Array &A)//打印数组各元素的值 
{
	int total=1;
	for(int i=0;i<A.dim;i++)
		total*=A.bounds[i];
	for(int i=0;i<total;i++)
	{
		printf("%d\t",*(A.base+i));
		if((i+1)%A.bounds[A.dim-1]==0)
			printf("\n");
	}
}


int main()
{
	//数据测试 
	Array A;
	init(A,3,2,3,4);//构造数组：3维数组，2页3行4列 
	int temp=0;
	for(int i=0;i<2;i++)
	for(int j=0;j<3;j++)
	for(int k=0;k<4;k++)
		assign(A,++temp,i,j,k);
	printf("数组各元素的值为：\n");
	print(A);//打印数组各元素的值 
	int e;
	value(A,e,0,1,3);
	printf("元素(0,1,3)的值为%d\n",e);
	e=99;
	for(int i=0;i<4;i++)
		assign(A,e,1,2,i);//将第1页第2行中的所有元素值修改为99 
	printf("将第1页第2行中的所有元素值修改为99\n");
	printf("数组各元素的值为：\n");
	print(A);//打印数组各元素的值 
	destroy(A);//销毁数组 
	return 0;
}

