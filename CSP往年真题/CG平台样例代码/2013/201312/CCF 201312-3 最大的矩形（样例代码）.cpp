#include<bits/stdc++.h>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
int a[1050];
int main()
{
	IO;
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int nowmin=a[i];
        for(int j=i+1;j<=n;j++)
        {
            if(nowmin>a[j])nowmin=a[j];
            ans=max(ans,(j-i+1)*nowmin);
        }
    }
    cout<<ans;
    return 0;
}
