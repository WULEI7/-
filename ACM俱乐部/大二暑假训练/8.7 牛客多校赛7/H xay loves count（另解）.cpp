#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=1000005;
int n,x,a[N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&x),++a[x];
	long long ans=0;
	for (int i=1;i<N;i++)
		for (int j=1;j*i<N;j++)
			ans+=1ll*a[i]*a[j]*a[i*j];
	cout<<ans<<endl;
}
