#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int qipan[10]={0},flag=0;
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		if(i%2==0)
			qipan[s[i]-'0']=1;
		if(i%2==1)
			qipan[s[i]-'0']=2;
	}
	if(qipan[1]==1&&qipan[2]==1&&qipan[3]==1||qipan[4]==1&&qipan[5]==1&&qipan[6]==1||qipan[7]==1&&qipan[8]==1&&qipan[9]==1
	 ||qipan[1]==1&&qipan[4]==1&&qipan[7]==1||qipan[2]==1&&qipan[5]==1&&qipan[8]==1||qipan[3]==1&&qipan[6]==1&&qipan[9]==1
	 ||qipan[1]==1&&qipan[5]==1&&qipan[9]==1||qipan[3]==1&&qipan[5]==1&&qipan[7]==1)
	 	flag=1;
	if(qipan[1]==2&&qipan[2]==2&&qipan[3]==2||qipan[4]==2&&qipan[5]==2&&qipan[6]==2||qipan[7]==2&&qipan[8]==2&&qipan[9]==2
	 ||qipan[1]==2&&qipan[4]==2&&qipan[7]==2||qipan[2]==2&&qipan[5]==2&&qipan[8]==2||qipan[3]==2&&qipan[6]==2&&qipan[9]==2
	 ||qipan[1]==2&&qipan[5]==2&&qipan[9]==2||qipan[3]==2&&qipan[5]==2&&qipan[7]==2)
	 	flag=2;
	if(flag==0)
		cout<<"drew."<<endl;
	else if(flag==1)
		cout<<"xiaoa wins."<<endl;
	else if(flag==2)
		cout<<"uim wins."<<endl;
	return 0;
}
