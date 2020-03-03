#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int mindis(char a[],char b[])
{
	int ans=25;
	int k1=strlen(a),k2=strlen(b); 
	for(int i=0;i<k1;i++)
		for(int j=0;j<k2;j++)
			if(abs(a[i]-b[j])<ans)
				ans=abs(a[i]-b[j]);
	return ans;
}
int main()
{
	char a[11],b[11];
	cin>>a>>b;
	int k1=strlen(a),k2=strlen(b);
	for(int i=0;i<k1;i++)
		a[i]=tolower(a[i]);
	for(int i=0;i<k2;i++)
		b[i]=tolower(b[i]);
	cout<<mindis(a,b);
	return 0;
}
