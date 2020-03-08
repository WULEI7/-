#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0,num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
	char str[201];
	cin.getline(str,201);
	int k=strlen(str);
	for(int i=0;i<k;i++)
		if(str[i]>='a'&&str[i]<='z') ans+=num[str[i]-'a'];
		else if(str[i]==' ') ans++;
	cout<<ans;
	return 0;
}
