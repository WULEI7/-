#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
void fun(int n)
{
	if(n==0) return;
	int temp;
	for(int i=0;i<=15;i++)
		if(pow(2,i)>n)
		{
			temp=i-1;
			break;
		}
	if(temp==0)
		printf("2(0)");
	if(temp==1)
		printf("2");
	if(temp>=2)
	{
		printf("2(");
		fun(temp);
		printf(")");
	}
	n-=pow(2,temp); 
	if(n==0) return;
	printf("+");
	fun(n);
}
int main()
{
	int n;
	scanf("%d",&n);
	fun(n);
	return 0;
}
