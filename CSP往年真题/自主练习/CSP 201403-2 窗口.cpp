#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct window
{
	int x1,y1,x2,y2,num;
};
vector<window> win;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		window t;
		cin>>t.x1>>t.y1>>t.x2>>t.y2;
		t.num=i;
		win.push_back(t);
	}
	while(m--)
	{
		int i,x,y;
		cin>>x>>y;
		for(i=n-1;i>=0;i--)
		{
			window t=win[i];
			if(x>=t.x1&&x<=t.x2&&y>=t.y1&&y<=t.y2)
			{
				printf("%d\n",t.num);
				win.erase(win.begin()+i);
				win.push_back(t);
				break;
			}
		}
		if(i==-1)
			printf("IGNORED\n");
	}
	return 0;
}
