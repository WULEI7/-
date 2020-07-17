#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,l,r,c,col[8005],cnt[8005][2];
	while(cin>>n)
	{
		for(int i=0;i<8005;i++)
		col[i]=-1,cnt[i][0]=i,cnt[i][1]=0;
		for(int i=0;i<n;i++)
		{
			cin>>l>>r>>c;
			for(int j=l;j<r;j++)
				col[j]=c;
		}
		for(int i=0;i<=8000;i++)
			if(col[i]!=-1&&col[i]!=col[i+1])
				cnt[col[i]][1]++;
		for(int i=0;i<=8000;i++)
			if(cnt[i][1]>0)
				cout<<cnt[i][0]<<" "<<cnt[i][1]<<endl;
		cout<<endl;
	}
	return 0;
}
