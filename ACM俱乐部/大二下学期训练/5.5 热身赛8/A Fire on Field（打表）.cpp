#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a[1005];
	a[0]=1,a[1]=1;
	for(int i=2;i<=1000;i++)
	{
		int temp=1;
		while(1)
		{
			int flag=1;
			for(int k=1;;k++)
			{
				if(i-2*k>=0)
				{
					if(a[i-2*k]+temp==2*a[i-k])
					{
						flag=0;
						break;
					}
				}
				else
					break;
			}
			if(flag==1)
				break;
			else
				temp++;
		}
		a[i]=temp;
	}
	cin>>n;
	cout<<a[n]<<endl;
	return 0;
}
