#include <iostream>
#include <cstdio>
#include <vector>
#define base 261
#define mod 23333
using namespace std;
int n,ans=0;
string s;
vector<string> linker[mod+1];
inline void insert(string s)//¹şÏ£±í²åÈë²Ù×÷ 
{
	int hash=1;
	int len=s.length();
	for(int i=0;i<len;i++)
		hash=(hash*1ll*base+s[i])%mod;
	int size=linker[hash].size();
	for(int i=0;i<size;i++)
		if(linker[hash][i]==s)
			return;
	linker[hash].push_back(s);
	ans++;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--)
	{
		cin>>s;
		insert(s);
	}
	cout<<ans<<endl;
	return 0;
}
