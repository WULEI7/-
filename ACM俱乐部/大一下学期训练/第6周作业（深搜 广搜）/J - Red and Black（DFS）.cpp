#include <cstdio>
#include <iostream>
using namespace std;
int w,h,r,c,ans;
char x[22][22];
void dfs(int r,int c)
{
	if(r<0||r>=h||c<0||c>=w||x[r][c]=='#') return;
	ans++;
	x[r][c]='#';
	dfs(r-1,c);
	dfs(r+1,c);
	dfs(r,c-1);
	dfs(r,c+1);
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>w>>h)//注意w是列，h是行 
	{
		if(w==0&&h==0) break;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
			{
				cin>>x[i][j];
				if(x[i][j]=='@')
				{r=i;c=j;}
			}
		ans=0;
		dfs(r,c);
		cout<<ans<<endl;
	}
	return 0;
}
