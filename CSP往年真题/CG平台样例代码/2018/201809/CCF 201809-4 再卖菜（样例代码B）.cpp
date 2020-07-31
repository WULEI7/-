#include <bits/stdc++.h>
using namespace std;
int a[305],b[305];int n;
int dp[305][305][305]; //第i位置和i-1位置的数 

int main(){
	cin>>n;int start=1000; //第一位数可以选到几 
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<3*a[n]-1;i++){
		int l=2*a[n]-i;
		int r=l+1;
		for(int j=max(l,1);j<=r;j++){
			if(n==2) start=min(start,j);
			dp[n][i][j]=1;
		}
	}for(int i=n-1;i>1;i--){
		for(int j=1;j<=3*a[i];j++){
			for(int k=1;j+k<=3*a[i]+1;k++){
				if(dp[i+1][k][j]){
					int l=3*a[i]-j-k;
					int r=l+2;
					for(int p=max(1,l);p<=r;p++){
						if((p+j+k)/3!=a[i]) continue;
						if(i==2){
							if((p+j)/2==a[1]) dp[i][j][p]=1,start=min(start,p);
						}else dp[i][j][p]=1;
					} 
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			b[i]=start;cout<<b[i]<<' ';
		}else{
			for(int j=1;;j++){
				if(dp[i][j][b[i-1]]){
					if(i==2){
						if((j+b[i-1])/2==a[i-1]){
							b[i]=j;break;
						}
					}else{
						if((j+b[i-1]+b[i-2])/3==a[i-1]){
							b[i]=j;break;
						}
					}
				}
			}cout<<b[i]<<' ';
		}
	}
}

