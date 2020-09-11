#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,v,value[1005],volume[1005],ans[1005]={0};
	cin>>v>>n;
	for(int i=0;i<n;i++)
		cin>>volume[i]>>value[i];
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++)
		for(int j=v;j>=0;j--)
			if(j>=volume[i])
				if(ans[j-volume[i]]+value[i]>ans[j])
					ans[j]=ans[j-volume[i]]+value[i];
	cout<<ans[v]<<endl;
	return 0;
}
