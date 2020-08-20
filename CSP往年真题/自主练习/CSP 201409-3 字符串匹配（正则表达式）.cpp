#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int f,n;
	cin>>s;
	scanf("%d%d",&f,&n);
	regex r("[[:alpha:]]*"+s+"[[:alpha:]]*");
	if(f==0)
		r=regex("[[:alpha:]]*"+s+"[[:alpha:]]*",regex::icase);//忽略大小写 
	while(n--)
	{
		cin>>s;
		if(regex_match(s,r))//匹配成功 
			cout<<s<<endl;
	}
	return 0;
}
