#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
int n,q,k,a[1005],b[1005],p[1005];
int aa[1005],bb[1005];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	cin>>q;
	while(q--)
	{
		for(int i=1;i<=n;i++)
		{
			aa[i]=a[i];
			bb[i]=b[i];
		}
		cin>>k;
		while(k--)
		{
			int ii,ai,bi;
			cin>>ii>>ai>>bi;
			a[ii]=ai;
			b[ii]=bi;
		}
		for(int i=1;i<n;i++)
			p[i]=0;
		for(int pos=1;pos<n;pos++)
		{
            int l=pos,r=pos+1;
            int attack=min(a[l],a[r]);
            int sum=attack;
            while(l>=1||r<=n)
            {
            	if(r>n||l>=1&&a[l]<a[r])
            	{
            		if(sum<a[l])
            		{
            			attack+=a[l]-sum;
            			sum=a[l];
            		}
            		sum+=b[l];
					l--;
					continue;
				}
				if(l<1||r<=n&&a[l]>=a[r])
				{
					if(sum<a[r])
					{
            			attack+=a[r]-sum;
            			sum=a[r];
            		}
					sum+=b[r];
					r++;
					continue;
				}
			}
			p[pos]=attack;
        }
        int ans=0;
        for (int i=1;i<n;i++)
        {
        	//cout<<p[i]<<" ";
            ans^=p[i];
    	}
    	//cout<<endl;
        cout<<ans<<endl;
		for(int i=1;i<=n;i++)
		{
			a[i]=aa[i];
			b[i]=bb[i];
		}
	}
	return 0;
}
