#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long n,ans=0,a[10];
void fun()
{
	int s1=0,s2,s3;
	for(int i=0;i<7;i++)
	{
		s1=s1*10+a[i];
		if(s1>=n) break;
		s2=0;
		for(int j=i+1;j<8;j++)
		{
			s2=s2*10+a[j];
			s3=0;
			for(int k=j+1;k<9;k++)
			{
				s3=s3*10+a[k];
				if(s3>s2) break;
			}
			if(s2%s3==0&&n==s1+s2/s3) ans++;//注意是在第二层for循环中判断 
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<9;i++)
		a[i]=i+1;
	do{fun();}while(next_permutation(a,a+9));//全排列 
	cout<<ans<<endl;
	return 0;
}
