#include <iostream>
#include <cmath>
using namespace std;

int isPrime(long num)
{
	for(long i=2;i*i<=num;i++)
		if(num%i==0) return 0;
	return 1;
}

void factorization(long n,long a[],int &b)//用 & 否则形参无法传递给实参 
{
	while(n>1)
		for(long i=2;;i++)
			if(isPrime(i)&&n%i==0)
			{
				a[b++]=i;
				n/=i;
				break;
			}
	return;
}

int main()
{
	long n;
	long factor[100];
	int numofFactor=0;
	cin>>n;
	factorization(n,factor,numofFactor);
	for(int i=0;i<numofFactor;i++)
		cout<<factor[i]<<" ";
	cout<<endl;
	return 0;
}
