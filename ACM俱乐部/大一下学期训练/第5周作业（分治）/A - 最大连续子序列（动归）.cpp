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
		}//����������ֶ�Ϊ��������Ҫ�����0����βԪ�� 
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
			}//���������������в�Ψһ�������l��r��С���Ǹ� 
		}
		cout<<ans<<" "<<a[l]<<" "<<a[r]<<endl;
	}
	return 0;
}
