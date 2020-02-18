#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 256
int min(int x, int y)
{
return x<y?x:y;
}
void c_to_d(char str[N], char d[N], int *start)
{   /*把str的各位转变成对应整数，右对齐存入d, *start为最高位下标*/
	int len,i,j;
	for(i=0;i<N;i++) d[i]=0;
	len=strlen(str); 
	/* *start为右对齐后的开始位，例如strlen(str)=5 N=10 *start=10-5=5*/
	*start=N-len;
	for(i=0,j=*start;i<len;i++,j++) d[j]=str[i]-'0'; /*字符到数字*/
}
void d_to_c(char d[N], char str[N], int start)
{	/*把d中数字d[start...N-1]转变为字符左对齐存入str*/
	int i,j,len=N-start;
	if (start==N) {str[0]='0';str[1]='\0';return;} /*start==N,是结果为0的情况*/
	if (d[start]=='-') str[0]=d[start];  /* 考虑第一位是否是'-'号*/
	else str[0]=d[start]+'0';
	for(i=1,j=start+1;i<len;i++,j++) str[i]=d[j]+'0';
	str[len]='\0';
}
int compare(char str1[N],char str2[N])/*str1,str2内存的是要进行比较的大整数*/
{ /*如果前者大于后者，返回正数，若相等返回0，否则返回负数*/
	int len1,len2;
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1<len2) return -1;
	else if(len1>len2) return 1;
	     else return strcmp(str1,str2);
}
/*加法 addition，数组右对齐相加*/
void add(char str_a[N], char str_b[N], char str_c[N])
{
	char a[N],b[N],c[N];        /*以右对齐的方式存储各位数*/
	int i;
	int start_a,start_b,start_c;/*分别存储a,b,c中最高位的下标*/
	int carry; /*进位*/
	/*把str_a,str_b的各位转变成对应整数，右对齐存入a,b*/
	c_to_d(str_a, a, &start_a);
	c_to_d(str_b, b, &start_b);
	i=N-1;                        /*从低位到高位，对应位相加*/
	carry=0;
	start_c=min(start_a,start_b); /*右对齐，为此取小的到start_c*/
	while(i>=start_c)  /* i>=start_c需不断两两相加*/
	{
		c[i]=a[i]+b[i]+carry;
		carry=c[i]/10;
		c[i]=c[i]%10;
		i--;
	}
	if(carry>0) /*如果有进位*/
	{
		start_c--;
		c[start_c]=carry;
	}
	d_to_c(c, str_c, start_c);  /*把c转化为字符串str_c*/
}
/* 减法，subtration，数组右对齐相减*/
void sub(char str_a[N], char str_b[N], char str_c[N])
{
	char a[N], b[N],c[N]; /*以右对齐的方式存储各位数*/
	int i;
	int start_a,start_b;  /*分别存储a,b,c中最高位的下标*/
	int borrow;/*借位*/
	/*把str_a,str_b的各位转变成对应整数，右对齐存入a,b*/
	c_to_d(str_a, a, &start_a);
	c_to_d(str_b, b, &start_b);	
	memset(c,0,sizeof(c)); /* 初始化*/
	i=N-1;                 /*从低位到高位，对应位相减，注意借位*/
	borrow=0;
	while((compare(str_a,str_b)>=0)?(i>=start_a):(i>=start_b))
	/* 利用条件运算后，str_a与str_b 不管大小都没问题了*/
	{
		if (compare(str_a,str_b)>=0) c[i]=a[i]-b[i]-borrow;/* 被减数大于减数时*/
		else c[i]=b[i]-a[i]-borrow;  /* 被减数大于减数时*/
		if(c[i]<0) /*借位*/
		{
			borrow=1;
			c[i]+=10;
		}
		else borrow=0;/*注意不可缺省*/
		i--;
	}
	/* i=0; */
	while(i<N && c[i]==0 ) i++;  /*去掉结果前面的0，定位新的i就行了 */
	/*把c转化为字符串str_c*/
	if (compare(str_a,str_b)<0 && i>=1) c[--i]='-';
	d_to_c(c, str_c, i);   /*i是c中最高位下标*/
}
/*乘法multiplication*/
void mul(char str_a[N], char str_b[N], char str_c[N])
{
	int len1, len2,i,j,k,carry;
	char a[N], b[N], c[N], d[N];
	int start_a, start_b, start_c, start_d;
	len1=strlen(str_a);
	len2=strlen(str_b);
	/*把str_a,str_b的各位转变成对应整数，右对齐存入a,b*/
	c_to_d(str_a, a, &start_a);
	c_to_d(str_b, b, &start_b);
	memset(c, 0, sizeof(c));
	/*用b[j](j=N-1,N-2....,) 乘a，存入d，再把d累加到c中，注意错位问题，d的最低位下标不是N-1，而是j*/
	for(j=N-1;j>=start_b;j--)
	{
		memset(d, 0, sizeof(d));
		carry=0;
		for(i=N-1,k=j;i>=start_a;i--,k--) 
		/*注意d的最低位下标从j开始，而不是从N-1开始*/
		{
			d[k]=a[i]*b[j]+carry; /* 要加上前一次相乘的进位*/
			carry=d[k]/10;
			d[k]=d[k]%10;
		}
		/*如果有进位*/
		if(carry>0)
		{
			d[k]=carry;
			k--;
		}
		start_d=k+1;
		/*把d累加到c中*/
		carry=0;
		for(i=N-1;i>=start_d;i--)
		{
			c[i]=c[i]+d[i]+carry;
			carry=c[i]/10;
			c[i]=c[i]%10;
		}
		/*如果有进位*/
		if(carry>0)
		{
			c[i]=carry;
			i--;
		}
	}
	start_c=i+1;
	/*把c转化为字符串str_c*/
	d_to_c(c, str_c, start_c);
}
/*/除法。division*/
void divd(char str_a[N], char str_b[N], char str_c[N])
{/*已假设a>b*/
	char c[N]; /*以左对齐的方式存储各位数*/
	char rmd[N];/*存储余数*/
	char temp[N];
	int i,k,len_rmd, len1,len2,cur;
	memset(c,0,sizeof(c));
    if (compare(str_a,str_b)<0) {str_c[0]='0';str_c[1]='\0';return;}/*如果被除数小于除数，则商为0*/

	/*准备工作,先在被除数中取和除数同样多的位数*/
	len1=strlen(str_a);
	len2=strlen(str_b);
	strcpy(rmd, str_a);
	rmd[len2]='\0';
	cur=len2-1; /*cur记下当前商对应的a中的下标*/
	/*如果不够除，再向右取1位*/
	if(compare(rmd, str_b)<0)
	{
		cur++;
		rmd[cur]=str_a[cur];
		rmd[cur+1]='\0';
	}
	/*求商的过程是从高位到低位进行，商的每一位计算：需要多次执行减法,减法次数即商的一位。*/
	k=0;
	while(str_a[cur]!='\0')
	{
		while(compare(rmd,str_b)>=0) /*本循环确定str_a[cur]对应位置的商*/
		{
			sub(rmd, str_b, temp);
			c[k]++;
			strcpy(rmd, temp);
		}
		/*右移一位后继续上述过程*/
		cur++;
		len_rmd=strlen(rmd);
		rmd[len_rmd]=str_a[cur];/*照抄被除数的一位*/
		rmd[len_rmd+1]='\0';
		k++;
	}
	for(i=0;i<k;i++) str_c[i]=c[i]+'0'; /*将c[0...k-1]转换成字符存入str_c*/
	str_c[i]='\0';
}
int main()
{
	char str_a[N],str_b[N],str_c[N];short a_pn=0,b_pn=0,i;
    printf("请输入第一个大整数（被加、减、乘、除数）：");
	scanf("%s",str_a);
	 // 输入字符预处理
	if(str_a[0]=='-') a_pn=-1;
	for(i=0;i<(int)strlen(str_a);i++)
	{
       if(!isdigit(str_a[i])) str_a[i]='0';
	}
	while(str_a[0]=='0'){ // 移除首导'0'
	  for(i=0;i<(int)strlen(str_a);i++) str_a[i]=str_a[i+1];
	}
    printf("请输入第二个大整数（加、减、乘、除数）：");
	scanf("%s",str_b);
	 // 输入字符预处理
	if(str_b[0]=='-') b_pn=-1;
	for(i=0;i<(int)strlen(str_b);i++)
	{
       if(!isdigit(str_b[i])) str_b[i]='0';
	}
	while(str_b[0]=='0'){ // 移除首导'0'
	  for(i=0;i<(int)strlen(str_b);i++) str_b[i]=str_b[i+1];
	}

    printf("\n你输入的第一个大整数（被加、减、乘、除数）为：%c%s\n",(a_pn)?'-':' ',str_a);
    printf("你输入的第二个大整数（加、减、乘、除数）为：%c%s\n\n",(b_pn)?'-':' ',str_b);

    // 带符号的两大整数相加
	if (a_pn==0&&b_pn==0||a_pn&&b_pn){  // + +    - -
  	   add(str_a,str_b,str_c); 
	   if (a_pn&&b_pn){        // -  -
          for(i=(int)strlen(str_c);i>=0;i--) str_c[i+1]=str_c[i];
	      str_c[0]='-';
	   }
	}
	if (a_pn==0&&b_pn){     // + -
	   sub(str_a,str_b,str_c); 
	}
	if (a_pn&&b_pn==0){     // - + 
	   sub(str_b,str_a,str_c); 
	}
    printf("两大整数相加结果：%s\n\n",str_c);
 
	// 带符号的两大整数相减
	if (a_pn==0&&b_pn||a_pn&&b_pn==0){    // + -   - +
	   add(str_a,str_b,str_c); 
	   if (a_pn&&b_pn==0){    // - + 
          for(i=(int)strlen(str_c);i>=0;i--) str_c[i+1]=str_c[i];
          str_c[0]='-';
	   }
	}
	if (a_pn==0&&b_pn==0){ // + +
	   sub(str_a,str_b,str_c); 
	}
	if (a_pn&&b_pn){       // - -
	   sub(str_b,str_a,str_c); 
	}
    printf("两大整数相减结果：%s\n\n",str_c);

	// 带符号的两大整数相乘
	mul(str_a,str_b,str_c); 
	if(a_pn==0&&b_pn||a_pn&&b_pn==0)  // + -   - +
       printf("两大整数相乘结果：%c%s\n\n",'-',str_c);// 负数，输出一个'-'号
	else  // + +   - -
       printf("两大整数相乘结果：%s\n\n",str_c);

    // 带符号的两大整数相除
	divd(str_a,str_b,str_c); 
	if(a_pn==0&&b_pn||a_pn&&b_pn==0)  // + -   - +
       printf("两大整数相除结果：%c%s\n\n",'-',str_c);// 负数，输出一个'-'号
	else  // + +   - -
       printf("两大整数相除结果：%s\n\n",str_c);
	return 0;
}
