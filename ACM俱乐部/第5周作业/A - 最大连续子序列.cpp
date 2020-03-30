#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int k,a[10005];
	while(cin>>k)
	{
		if(k==0) break;
		for(int i=0;i<k;i++)
			cin>>a[i];
		int flag=1;
		for(int i=0;i<k;i++)
			if(a[i]>=0)
			{flag=0;break;}
		if(flag)
		{
			cout<<0<<" "<<a[0]<<" "<<a[k-1]<<endl;
			continue;
		}//如果所有数字都为负数，则按要求输出0和首尾元素 
		int temp=0,ans=-1,l=0,r=0,lt=0,rt=0;
		for(int i=0;i<k;i++)
		{
			if(temp>=0)
			{
				temp+=a[i];
				rt=i;
			}
			else
			{
				temp=a[i];
				lt=i;
				rt=i;
			}
			if(temp>ans)
			{
				ans=temp;
				l=lt;
				r=rt;
			}//如果最大连续子序列不唯一，则输出l和r最小的那个 
		}
		cout<<ans<<" "<<a[l]<<" "<<a[r]<<endl;
	}
	return 0;
}
