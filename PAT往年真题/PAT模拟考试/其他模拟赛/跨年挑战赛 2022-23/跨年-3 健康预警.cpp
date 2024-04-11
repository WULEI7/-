#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,n,ans=0;
	cin>>m>>n;
	cout<<"Age: "<<m<<endl;
	cout<<"Healthy Index: "<<n<<endl;
	if(m>=1&&m<60)
	{
		if(n>=0&&n<30)
			ans=1;
		else if(n>=30&&n<60)
			ans=2;
		else
			ans=3;
	}
	else if(m>=60&&m<80)
	{
		if(n>=0&&n<50)
			ans=1;
		else if(n>=50&&n<70)
			ans=2;
		else
			ans=3;
	}
	else
	{
		if(n>=0&&n<60)
			ans=1;
		else if(n>=60&&n<75)
			ans=2;
		else
			ans=3;
	}
	if(ans==1)
		cout<<"Red Alert!!"<<endl;
	else if(ans==2)
		cout<<"Yellow Alert!"<<endl;
	else
		cout<<"Green ^_^"<<endl;
	return 0;
}
