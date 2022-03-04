#include <stdio.h>
#include <math.h> 
int main()
{
	int i=1;//第i项，奇数项为正，偶数项为负 
	double PI=0.0;//累加PI的值 
	double temp;//当前项的值（不含正负号） 
	while(1)
	{
		temp=1.0/(i*2-1);//注意确保类型和定义的一致，如果i用的是int类型，注意分子写成1.0，或者加上一个(double)强制类型转换 
		if(temp<pow(10,-6))//注意C语言^是位运算符号，指数要用pow函数 
			break;
		/*
		if(i%2==1) 
			PI+=temp;
		else
			PI+=-temp;
		*/
		PI+=pow(-1,i+1)*temp;//以上四行可以合并写成这个 
		i++;
	}
	PI*=4.0;
    printf("PI=%10.8f\n",PI);
    return 0;
}
