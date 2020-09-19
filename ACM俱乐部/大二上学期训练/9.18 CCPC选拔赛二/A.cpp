#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		int sta=0;
		if(a>0&&b>0) sta=1;
		else if(a>0&&b<0) sta=2;
		else if(a<0&&b>0) sta=3;
		else if(a<0&&b<0) sta=4;
		a=abs(a),b=abs(b);
		int c=a,d=b,cnt1=1,cnt2=1,flag=0;
		while(a)
		{
			if(a%10) break;
			a/=10;
			cnt1*=10;
		}
		if(a>=10) flag=1;
		a%=10;
		while(b)
		{
			if(b%10) break;
			b/=10;
			cnt2*=10;
		}
		if(b>=10) flag=2;
		b%=10;
		if(sta==1&&flag==0)
			printf("%d x %d\n",c,d);
		else if(sta==2&&flag==0)
			printf("-%d x %d\n",c,d);
		else if(sta==3&&flag==0)
			printf("-%d x %d\n",c,d);
		else if(sta==4&&flag==0)
			printf("%d x %d\n",c,d);
		else if(sta==1&&flag==1)
			printf("%d x %d + %d x %d\n",c-a*cnt1,d,a*cnt1,d);
		else if(sta==1&&flag==2)
			printf("%d x %d + %d x %d\n",d-b*cnt2,c,b*cnt2,c);
		else if(sta==2&&flag==1)
			printf("-%d x %d - %d x %d\n",c-a*cnt1,d,a*cnt1,d);
		else if(sta==2&&flag==2)
			printf("-%d x %d - %d x %d\n",d-b*cnt2,c,b*cnt2,c);
		else if(sta==3&&flag==1)
			printf("-%d x %d - %d x %d\n",c-a*cnt1,d,a*cnt1,d);
		else if(sta==3&&flag==2)
			printf("-%d x %d - %d x %d\n",d-b*cnt2,c,b*cnt2,c);
		else if(sta==4&&flag==1)
			printf("%d x %d + %d x %d\n",c-a*cnt1,d,a*cnt1,d);
		else if(sta==4&&flag==2)
			printf("%d x %d + %d x %d\n",d-b*cnt2,c,b*cnt2,c);
	}
	return 0;
}
