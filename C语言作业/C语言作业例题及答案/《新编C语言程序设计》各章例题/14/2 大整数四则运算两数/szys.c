#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 256
int min(int x, int y)
{
return x<y?x:y;
}
void c_to_d(char str[N], char d[N], int *start)
{   /*��str�ĸ�λת��ɶ�Ӧ�������Ҷ������d, *startΪ���λ�±�*/
	int len,i,j;
	for(i=0;i<N;i++) d[i]=0;
	len=strlen(str); 
	/* *startΪ�Ҷ����Ŀ�ʼλ������strlen(str)=5 N=10 *start=10-5=5*/
	*start=N-len;
	for(i=0,j=*start;i<len;i++,j++) d[j]=str[i]-'0'; /*�ַ�������*/
}
void d_to_c(char d[N], char str[N], int start)
{	/*��d������d[start...N-1]ת��Ϊ�ַ���������str*/
	int i,j,len=N-start;
	if (start==N) {str[0]='0';str[1]='\0';return;} /*start==N,�ǽ��Ϊ0�����*/
	if (d[start]=='-') str[0]=d[start];  /* ���ǵ�һλ�Ƿ���'-'��*/
	else str[0]=d[start]+'0';
	for(i=1,j=start+1;i<len;i++,j++) str[i]=d[j]+'0';
	str[len]='\0';
}
int compare(char str1[N],char str2[N])/*str1,str2�ڴ����Ҫ���бȽϵĴ�����*/
{ /*���ǰ�ߴ��ں��ߣ���������������ȷ���0�����򷵻ظ���*/
	int len1,len2;
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1<len2) return -1;
	else if(len1>len2) return 1;
	     else return strcmp(str1,str2);
}
/*�ӷ� addition�������Ҷ������*/
void add(char str_a[N], char str_b[N], char str_c[N])
{
	char a[N],b[N],c[N];        /*���Ҷ���ķ�ʽ�洢��λ��*/
	int i;
	int start_a,start_b,start_c;/*�ֱ�洢a,b,c�����λ���±�*/
	int carry; /*��λ*/
	/*��str_a,str_b�ĸ�λת��ɶ�Ӧ�������Ҷ������a,b*/
	c_to_d(str_a, a, &start_a);
	c_to_d(str_b, b, &start_b);
	i=N-1;                        /*�ӵ�λ����λ����Ӧλ���*/
	carry=0;
	start_c=min(start_a,start_b); /*�Ҷ��룬Ϊ��ȡС�ĵ�start_c*/
	while(i>=start_c)  /* i>=start_c�費���������*/
	{
		c[i]=a[i]+b[i]+carry;
		carry=c[i]/10;
		c[i]=c[i]%10;
		i--;
	}
	if(carry>0) /*����н�λ*/
	{
		start_c--;
		c[start_c]=carry;
	}
	d_to_c(c, str_c, start_c);  /*��cת��Ϊ�ַ���str_c*/
}
/* ������subtration�������Ҷ������*/
void sub(char str_a[N], char str_b[N], char str_c[N])
{
	char a[N], b[N],c[N]; /*���Ҷ���ķ�ʽ�洢��λ��*/
	int i;
	int start_a,start_b;  /*�ֱ�洢a,b,c�����λ���±�*/
	int borrow;/*��λ*/
	/*��str_a,str_b�ĸ�λת��ɶ�Ӧ�������Ҷ������a,b*/
	c_to_d(str_a, a, &start_a);
	c_to_d(str_b, b, &start_b);	
	memset(c,0,sizeof(c)); /* ��ʼ��*/
	i=N-1;                 /*�ӵ�λ����λ����Ӧλ�����ע���λ*/
	borrow=0;
	while((compare(str_a,str_b)>=0)?(i>=start_a):(i>=start_b))
	/* �������������str_a��str_b ���ܴ�С��û������*/
	{
		if (compare(str_a,str_b)>=0) c[i]=a[i]-b[i]-borrow;/* ���������ڼ���ʱ*/
		else c[i]=b[i]-a[i]-borrow;  /* ���������ڼ���ʱ*/
		if(c[i]<0) /*��λ*/
		{
			borrow=1;
			c[i]+=10;
		}
		else borrow=0;/*ע�ⲻ��ȱʡ*/
		i--;
	}
	/* i=0; */
	while(i<N && c[i]==0 ) i++;  /*ȥ�����ǰ���0����λ�µ�i������ */
	/*��cת��Ϊ�ַ���str_c*/
	if (compare(str_a,str_b)<0 && i>=1) c[--i]='-';
	d_to_c(c, str_c, i);   /*i��c�����λ�±�*/
}
/*�˷�multiplication*/
void mul(char str_a[N], char str_b[N], char str_c[N])
{
	int len1, len2,i,j,k,carry;
	char a[N], b[N], c[N], d[N];
	int start_a, start_b, start_c, start_d;
	len1=strlen(str_a);
	len2=strlen(str_b);
	/*��str_a,str_b�ĸ�λת��ɶ�Ӧ�������Ҷ������a,b*/
	c_to_d(str_a, a, &start_a);
	c_to_d(str_b, b, &start_b);
	memset(c, 0, sizeof(c));
	/*��b[j](j=N-1,N-2....,) ��a������d���ٰ�d�ۼӵ�c�У�ע���λ���⣬d�����λ�±겻��N-1������j*/
	for(j=N-1;j>=start_b;j--)
	{
		memset(d, 0, sizeof(d));
		carry=0;
		for(i=N-1,k=j;i>=start_a;i--,k--) 
		/*ע��d�����λ�±��j��ʼ�������Ǵ�N-1��ʼ*/
		{
			d[k]=a[i]*b[j]+carry; /* Ҫ����ǰһ����˵Ľ�λ*/
			carry=d[k]/10;
			d[k]=d[k]%10;
		}
		/*����н�λ*/
		if(carry>0)
		{
			d[k]=carry;
			k--;
		}
		start_d=k+1;
		/*��d�ۼӵ�c��*/
		carry=0;
		for(i=N-1;i>=start_d;i--)
		{
			c[i]=c[i]+d[i]+carry;
			carry=c[i]/10;
			c[i]=c[i]%10;
		}
		/*����н�λ*/
		if(carry>0)
		{
			c[i]=carry;
			i--;
		}
	}
	start_c=i+1;
	/*��cת��Ϊ�ַ���str_c*/
	d_to_c(c, str_c, start_c);
}
/*/������division*/
void divd(char str_a[N], char str_b[N], char str_c[N])
{/*�Ѽ���a>b*/
	char c[N]; /*�������ķ�ʽ�洢��λ��*/
	char rmd[N];/*�洢����*/
	char temp[N];
	int i,k,len_rmd, len1,len2,cur;
	memset(c,0,sizeof(c));
    if (compare(str_a,str_b)<0) {str_c[0]='0';str_c[1]='\0';return;}/*���������С�ڳ���������Ϊ0*/

	/*׼������,���ڱ�������ȡ�ͳ���ͬ�����λ��*/
	len1=strlen(str_a);
	len2=strlen(str_b);
	strcpy(rmd, str_a);
	rmd[len2]='\0';
	cur=len2-1; /*cur���µ�ǰ�̶�Ӧ��a�е��±�*/
	/*�����������������ȡ1λ*/
	if(compare(rmd, str_b)<0)
	{
		cur++;
		rmd[cur]=str_a[cur];
		rmd[cur+1]='\0';
	}
	/*���̵Ĺ����ǴӸ�λ����λ���У��̵�ÿһλ���㣺��Ҫ���ִ�м���,�����������̵�һλ��*/
	k=0;
	while(str_a[cur]!='\0')
	{
		while(compare(rmd,str_b)>=0) /*��ѭ��ȷ��str_a[cur]��Ӧλ�õ���*/
		{
			sub(rmd, str_b, temp);
			c[k]++;
			strcpy(rmd, temp);
		}
		/*����һλ�������������*/
		cur++;
		len_rmd=strlen(rmd);
		rmd[len_rmd]=str_a[cur];/*�ճ���������һλ*/
		rmd[len_rmd+1]='\0';
		k++;
	}
	for(i=0;i<k;i++) str_c[i]=c[i]+'0'; /*��c[0...k-1]ת�����ַ�����str_c*/
	str_c[i]='\0';
}
int main()
{
	char str_a[N],str_b[N],str_c[N];short a_pn=0,b_pn=0,i;
    printf("�������һ�������������ӡ������ˡ���������");
	scanf("%s",str_a);
	 // �����ַ�Ԥ����
	if(str_a[0]=='-') a_pn=-1;
	for(i=0;i<(int)strlen(str_a);i++)
	{
       if(!isdigit(str_a[i])) str_a[i]='0';
	}
	while(str_a[0]=='0'){ // �Ƴ��׵�'0'
	  for(i=0;i<(int)strlen(str_a);i++) str_a[i]=str_a[i+1];
	}
    printf("������ڶ������������ӡ������ˡ���������");
	scanf("%s",str_b);
	 // �����ַ�Ԥ����
	if(str_b[0]=='-') b_pn=-1;
	for(i=0;i<(int)strlen(str_b);i++)
	{
       if(!isdigit(str_b[i])) str_b[i]='0';
	}
	while(str_b[0]=='0'){ // �Ƴ��׵�'0'
	  for(i=0;i<(int)strlen(str_b);i++) str_b[i]=str_b[i+1];
	}

    printf("\n������ĵ�һ�������������ӡ������ˡ�������Ϊ��%c%s\n",(a_pn)?'-':' ',str_a);
    printf("������ĵڶ������������ӡ������ˡ�������Ϊ��%c%s\n\n",(b_pn)?'-':' ',str_b);

    // �����ŵ������������
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
    printf("����������ӽ����%s\n\n",str_c);
 
	// �����ŵ������������
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
    printf("����������������%s\n\n",str_c);

	// �����ŵ������������
	mul(str_a,str_b,str_c); 
	if(a_pn==0&&b_pn||a_pn&&b_pn==0)  // + -   - +
       printf("����������˽����%c%s\n\n",'-',str_c);// ���������һ��'-'��
	else  // + +   - -
       printf("����������˽����%s\n\n",str_c);

    // �����ŵ������������
	divd(str_a,str_b,str_c); 
	if(a_pn==0&&b_pn||a_pn&&b_pn==0)  // + -   - +
       printf("����������������%c%s\n\n",'-',str_c);// ���������һ��'-'��
	else  // + +   - -
       printf("����������������%s\n\n",str_c);
	return 0;
}
