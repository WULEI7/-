#include <bits/stdc++.h>
using namespace std;
char s[100001];
int main()
{
	int place=0,west=0,east=0;
	cin>>s;
	int k=strlen(s);
	for(int i=0;i<k;i++)
	{
		if(s[i]=='E') place++;
		if(s[i]=='W') place--;
		if(place>east) east=place;
		if(place<west) west=place;
	}
	cout<<east-west;
	return 0;
}
