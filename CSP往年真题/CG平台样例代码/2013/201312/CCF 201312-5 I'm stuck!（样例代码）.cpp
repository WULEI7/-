#include<bits/stdc++.h>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
char g[60][60];
int vis1[60][60],vis2[60][60];
int r,c;
int edx,edy,stx,sty;
bool check(int nowx,int nowy)
{
	if(nowx<1||nowx>r||nowy<1||nowy>c||g[nowx][nowy]=='#'||vis1[nowx][nowy])return false;
	return true;
}
bool rcheck(int nowx,int nowy)
{
	if(nowx<1||nowx>r||nowy<1||nowy>c||vis2[nowx][nowy])return false;
	return true;
}
void dfs1(int nowx,int nowy)
{
	vis1[nowx][nowy]=1;
	if(g[nowx][nowy]=='S'||g[nowx][nowy]=='+'||g[nowx][nowy]=='T')
	{
		if(check(nowx+1,nowy))dfs1(nowx+1,nowy);
		if(check(nowx-1,nowy))dfs1(nowx-1,nowy);
		if(check(nowx,nowy+1))dfs1(nowx,nowy+1);
		if(check(nowx,nowy-1))dfs1(nowx,nowy-1);
	}
	else if(g[nowx][nowy]=='-')
	{
		if(check(nowx,nowy+1))dfs1(nowx,nowy+1);
		if(check(nowx,nowy-1))dfs1(nowx,nowy-1);
	}
	else if(g[nowx][nowy]=='|')
	{
		if(check(nowx+1,nowy))dfs1(nowx+1,nowy);
		if(check(nowx-1,nowy))dfs1(nowx-1,nowy);
	}
	else if(g[nowx][nowy]=='.')
	{
		if(check(nowx+1,nowy))dfs1(nowx+1,nowy);
	}
}
void dfs2(int nowx,int nowy)
{
	vis2[nowx][nowy]=1;
	char ch=g[nowx-1][nowy];
	if(rcheck(nowx-1,nowy)&&(ch=='+'||ch=='|'||ch=='S'||ch=='T'||ch=='.')) dfs2(nowx-1,nowy);
	ch=g[nowx+1][nowy];
	if(rcheck(nowx+1,nowy)&&(ch=='+'||ch=='|'||ch=='S'||ch=='T')) dfs2(nowx+1,nowy);
	ch=g[nowx][nowy-1];
	if(rcheck(nowx,nowy-1)&&(ch=='+'||ch=='-'||ch=='S'||ch=='T')) dfs2(nowx,nowy-1);
	ch=g[nowx][nowy+1];
	if(rcheck(nowx,nowy+1)&&(ch=='+'||ch=='-'||ch=='S'||ch=='T')) dfs2(nowx,nowy+1);

}
int main()
{
	IO;cin>>r>>c;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
		{
			cin>>g[i][j];
			if(g[i][j]=='S')stx=i,sty=j;
			else if(g[i][j]=='T')edx=i,edy=j;
		}
	//cout<<stx<<" "<<sty<<" "<<edx<<" "<<edy<<"\n";
	dfs1(stx,sty);dfs2(edx,edy);
	if(vis2[stx][sty])
	{
		int ans=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				//cout<<"i="<<i<<" j="<<j<<" vis1[i][j]="<<vis1[i][j]<<" vis2[i][j]="<<vis2[i][j]<<"\n";
				if(vis1[i][j]&&vis2[i][j]==0)ans++;
			}
		cout<<ans;
	}
	else cout<<"I'm stuck!";
    return 0;
}
