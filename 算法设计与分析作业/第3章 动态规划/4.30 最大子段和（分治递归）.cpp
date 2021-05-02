#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
int a[100],t,n=0,ans=0,ansleft=0,ansright=0;
int Maxsum(int left,int right,int &ansl,int &ansr)
{
	int l1=1,r1=1,l2=1,r2=1,l3=1,r3=1;
	if(left==right)
	{
		if(a[left]>0)
		{
			ansl=ansr=left;
			return a[left];
		}
		else
			return 0;
	}
	else
	{
		int mid=left+(right-left)/2;
		int sum1=Maxsum(left,mid,l1,r1);//���1������Ӷ�����벿����ͬ 
		int sum2=Maxsum(mid+1,right,l2,r2);//���2������Ӷ����Ұ벿����ͬ 
		int sum3=0,s1=0,s2=0,temp1=0,temp2=0;//���3������Ӷο�Խ������������ 
		for(int i=mid;i>=left;i--)
		{
			temp1+=a[i];
			if(temp1>s1)
			{
				s1=temp1;
				l3=i;
			}
		}
		for(int i=mid+1;i<=right;i++)
		{
			temp2+=a[i];
			if(temp2>s2)
			{
				s2=temp2;
				r3=i;
			}
		}
		sum3=s1+s2;
		ansl=l3;
		ansr=r3;
		if(sum3<=sum1)
		{
			sum3=sum1;
			ansl=l1;
			ansr=r1;
		}
		if(sum3<=sum2)//ϸ�ڣ�����Ҫ��<= 
		{
			sum3=sum2;
			ansl=l2;
			ansr=r2;
		}
		return sum3;//����Ӷ�����ѡ����>��>�� 
	}
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stringstream scin;
	string s;
	getline(cin,s);
	scin<<s;
	while(scin>>t)
		a[++n]=t;
	ans=Maxsum(1,n,ansleft,ansright);
	cout<<ans<<endl<<ansleft<<endl<<ansright<<endl;
	return 0;
}
