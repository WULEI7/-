#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int a[100005],num[11],pos[11],mov[11][11],ans=1999999999,len;
void fun()
{
	int res=0;
	for(int i=1;i<=9;i++)
		pos[num[i]]=i;
	for(int i=1;i<=9;i++)
	for(int j=1;j<=9;j++)
		res+=abs(pos[i]-pos[j])*mov[i][j];//移动步数*重复次数 
		//res+=abs(pos[a[i-1]]-pos[a[i]]);
	res+=abs(pos[a[0]]-1)+len;
	ans=min(ans,res);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++)
		a[i]=s[i]-'0';
	for(int i=1;i<len;i++)
		mov[a[i-1]][a[i]]++;//计算相同移动的重复次数，预先处理，降低时间复杂度 
	for(int i=1;i<=9;i++)
		num[i]=i;
	do{fun();}while(next_permutation(num+1,num+10));
	cout<<ans<<endl;
	return 0;
}
