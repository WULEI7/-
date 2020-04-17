#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,x[10005],ans;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>x[i];
		ans=0;
		for(int i=0;i<n;i++)
		{
			if(x[i]==0) continue;
			ans++;
			int temp=x[i];
			for(int j=i+1;j<n;j++)
				if(x[j]!=0&&x[j]<=temp)
				{
					temp=x[j];
					x[j]=0;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
