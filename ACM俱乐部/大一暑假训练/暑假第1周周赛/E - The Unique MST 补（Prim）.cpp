#include <iostream>
#include <cstring>
#define inf 99999999
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,p,r,vis[105],dis[105],map[105][105];
	cin>>t;
	while(t--)
	{
		int ans=0,flag=1;
		cin>>p>>r;
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		for(int i=1;i<=p;i++)
			for(int j=1;j<=p;j++)
				if(i==j) map[i][j]=0;
				else map[i][j]=inf;//ͼ�ĳ�ʼ�� 
		for(int i=1;i<=r;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			if(map[a][b]>c)
				map[a][b]=map[b][a]=c;
		}
		for(int i=1;i<=p;i++)
			dis[i]=map[1][i];
		vis[1]=1;//��1�㿪ʼ���� 
		for(int i=1;i<=p;i++)
		{
			int minn=inf,k=0;
			for(int j=1;j<=p;j++)
				if(vis[j]==0&&dis[j]<minn)
				{
					minn=dis[j];
					k=j;
				}
			//ans+=minn;Ҳ�������������ans 
			int check=0;
			for(int j=1;j<=p;j++)
				if(vis[j]&&map[k][j]==minn)
					check++;
			if(check>1) flag=0;//�����С�������Ƿ�Ψһ 
			vis[k]=1;//������ڼ��ĺ��棬����ʹ��� 
			for(int j=1;j<=p;j++)
				if(vis[j]==0&&dis[j]>map[k][j])
					dis[j]=map[k][j];
			if(flag==0) break;
		}
		for(int i=1;i<=p;i++)
			ans+=dis[i];//Ҳ�������������ans 
		if(flag)
			cout<<ans<<endl;
		else
			cout<<"Not Unique!"<<endl;
	}
	return 0;
}
