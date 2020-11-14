#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>//���ڴ�ȡ�䳤������ 

#define MAX_DIM 8//��������ά�������ֵΪ8 

typedef struct
{
	int *base;//����Ԫ�ػ�ַ 
	int dim;//����ά�� 
	int *bounds;//����ά����ַ,����ά��dim=3��bounds[0]=2��bounds[1]=3��bounds[2]=4����ʾ2ҳ3��4�е����� 
	int *constants;//����ӳ����������ַ 
	/*  �������2ҳ3��4�е�����,��constants[2]=1��constants[1]=4��constants[0]=12�� 
	    ����һ���±�A[0][1][2]��0*12+1*4+2*1=6��Ԫ�ش�ȡ�ڵ�ǰ����ĵ�6��λ�ã��ټ���base�����ҵ����ĵ�ַ 
	*/ 
}Array;


bool init(Array &A,int dim,...)//�������� 
{
	if(dim<1||dim>MAX_DIM)
		return false;
	A.dim=dim;
	A.bounds=(int *)malloc(dim*sizeof(int));
	if(!A.bounds) return false;
	int total=1;//��Ԫ������ 
	va_list list;//��ű䳤��������Ϣ������list 
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
	A.constants[dim-1]=1;//���һάΪ1��ָ���������Ԫ�صĴ�СΪ��λ 
	for(int i=dim-2;i>=0;i--)
		A.constants[i]=A.bounds[i+1]*A.constants[i+1];
	return true;
}

bool destroy(Array &A)//�������� 
{
	if(!A.base) return false;
	free(A.base); A.base=NULL;
	if(!A.bounds) return false;
	free(A.bounds); A.bounds=NULL;
	if(!A.constants) return false;
	free(A.constants); A.constants=NULL;
	return true;
}

bool locate(Array &A,va_list list,int &off)//��Ԫ��������A�е���Ե�ַoff 
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

bool value(Array &A,int &e,...)//��e��ֵΪ��ָ����A��Ԫ��ֵ 
{
	va_list list;
	va_start(list,e);
	int off=0;
	if(!locate(A,list,off)) return false;
	e=*(A.base+off);
	va_end(list);
	return true;
}

bool assign(Array &A,int e,...)//��e��ֵ����ָ����A��Ԫ�� 
{
	va_list list;
	va_start(list,e);
	int off=0;
	if(!locate(A,list,off)) return false;
	*(A.base+off)=e;
	va_end(list);
	return true;
}

void print(Array &A)//��ӡ�����Ԫ�ص�ֵ 
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
	//���ݲ��� 
	Array A;
	init(A,3,2,3,4);//�������飺3ά���飬2ҳ3��4�� 
	int temp=0;
	for(int i=0;i<2;i++)
	for(int j=0;j<3;j++)
	for(int k=0;k<4;k++)
		assign(A,++temp,i,j,k);
	printf("�����Ԫ�ص�ֵΪ��\n");
	print(A);//��ӡ�����Ԫ�ص�ֵ 
	int e;
	value(A,e,0,1,3);
	printf("Ԫ��(0,1,3)��ֵΪ%d\n",e);
	e=99;
	for(int i=0;i<4;i++)
		assign(A,e,1,2,i);//����1ҳ��2���е�����Ԫ��ֵ�޸�Ϊ99 
	printf("����1ҳ��2���е�����Ԫ��ֵ�޸�Ϊ99\n");
	printf("�����Ԫ�ص�ֵΪ��\n");
	print(A);//��ӡ�����Ԫ�ص�ֵ 
	destroy(A);//�������� 
	return 0;
}

