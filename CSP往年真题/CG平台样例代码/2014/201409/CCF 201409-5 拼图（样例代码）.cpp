#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
#define MAX_COL 7
#define ll long long
ll n;
int m;
int status[1<<MAX_COL][1<<MAX_COL]; 
int res[1<<MAX_COL][1<<MAX_COL];
int put(int S,int col1,int col2){
	S|=1<<col1;
	if(col2!=-1) S|=1<<col2;
	return S;
}
int check(int S,int col){
	if(col>=0&&col<m&&(S&(1<<col))==0) return 1;
	return 0;
}
void search(int S,int S1,int S2,int col){
	if(S1==(1<<m)-1){
		status[S][S2]++;
		return; 
	}
	if(!check(S1,col)){
		search(S,S1,S2,col+1); 
	}else{
		if(check(S1,col+1)&&check(S2,col)) //"ǹ"
			search(S,put(S1,col,col+1),put(S2,col,-1),col+2);
		if(check(S1,col+1)&&check(S2,col+1)) //"7"
			search(S,put(S1,col,col+1),put(S2,col+1,-1),col+2);
		if(check(S2,col-1)&&check(S2,col)) //"J"
			search(S,put(S1,col,-1),put(S2,col-1,col),col+1);
		if(check(S2,col)&&check(S2,col+1)) //"L"
			search(S,put(S1,col,-1),put(S2,col,col+1),col+1);
	}
}

void mat_mul(int A[1<<MAX_COL][1<<MAX_COL],int B[1<<MAX_COL][1<<MAX_COL]){
	long long matrix[1<<MAX_COL][1<<MAX_COL]={0};
	for(int i=0;i<(1<<MAX_COL);i++)
		for(int j=0;j<(1<<MAX_COL);j++)
			for(int k=0;k<(1<<MAX_COL);k++)
				matrix[i][j]=(matrix[i][j]+(long long)A[i][k]*(long long)B[k][j])%MOD;
	for(int i=0;i<(1<<MAX_COL);i++)
		for(int j=0;j<(1<<MAX_COL);j++)
			A[i][j]=(int)matrix[i][j];
}
int main(void){
	scanf("%lld %d",&n,&m);
	for(int i=0;i<(1<<m);i++)
		search(i,i,0,0);
	
	for(int i=0;i<(1<<MAX_COL);i++)
		for(int j=0;j<(1<<MAX_COL);j++)
			res[i][j]=(i==j)?1:0;	 
	n--;
	while(n){
		if(n%2) mat_mul(res,status);
		mat_mul(status,status);	
		n/=2;
	}
	printf("%d",res[0][(1<<m)-1]);
}

