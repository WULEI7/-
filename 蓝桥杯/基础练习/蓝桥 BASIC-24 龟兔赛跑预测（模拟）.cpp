#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int v1,v2,t,s,L,L1=0,L2=0,time=0,flag=-1;
	cin>>v1>>v2>>t>>s>>L;
	while(L1<L&&L2<L)
	{
		if(L1-L2>=t&&flag==-1)
			flag=0;//兔子停下来 
		time++;
		if(flag==-1)
			L1+=v1;
		else
		{
			flag++;
			if(flag==s)
				flag=-1;
		}
		L2+=v2;
		if(L1==L&&L2<L)
		{
			cout<<"R"<<endl;
			break;
		}//兔子赢 
		if(L1<L&&L2==L)
		{
			cout<<"T"<<endl;
			break;
		}//乌龟赢 
		if(L1==L&&L2==L)
		{
			cout<<"D"<<endl;
			break;
		}//平局 
	}
	cout<<time<<endl;
	return 0;
}
