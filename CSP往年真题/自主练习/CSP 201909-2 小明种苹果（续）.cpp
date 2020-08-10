#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n,m,t=0,d=0,e=0,diao[1005]={0};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		int a,temp=0;//当前树的苹果数量 
		cin>>temp;//第一次输入初始苹果个数 
		for(int j=2;j<=m;j++)
		{
			cin>>a;
			if(a>0)//重新统计 
			{
				if(a<temp)//有掉落 
				{
					diao[i]=1;
					temp=a;
				}	
			}
			else//疏果 
				temp+=a;
		}
		t+=temp;//加入苹果总数 
	}
	for(int i=1;i<=n;i++)//统计掉落情况 
	{
		if(diao[i])
			d++;
		if(diao[(i-1)%n+1]&&diao[i%n+1]&&diao[(i+1)%n+1])
			e++;
	}
	cout<<t<<" "<<d<<" "<<e<<endl;
	return 0; 
}
