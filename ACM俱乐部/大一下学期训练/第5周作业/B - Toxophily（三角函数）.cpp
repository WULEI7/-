#include <cstdio>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	double x,y,v;
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>v;
		/*
			����ٶȷ�����x�᷽��н�Ϊ ��
			x = vtcos��
			y =vtsin��-(1/2)gt2 
			���ù�ʽ 1/cos2�� =1+tan2�� 
			���� t �� (gx2/2v2)tan2��- xtan��+ gx2/2v2 + y = 0
		*/
		double a=(9.8*x*x)/(2*v*v),b=-x,c=(9.8*x*x)/(2*v*v)+y;
		double delta=b*b-4*a*c;
		if(delta<0)
		{
			cout<<"-1"<<endl;
			continue;
		}
		else
		{
			double ans1=atan((-b-sqrt(delta))/(2*a)),ans2=atan((-b+sqrt(delta))/(2*a));
			int flag1=0,flag2=0;
			if(ans1>0&&ans1<asin(1)) flag1=1;
			if(ans2>0&&ans2<asin(1)) flag2=1;
			if(flag1&&!flag2) cout<<fixed<<setprecision(6)<<ans1<<endl;
			else if(!flag1&&flag2) cout<<fixed<<setprecision(6)<<ans2<<endl;
			else if(flag1&&flag2)
			{
				if(ans1<ans2) cout<<fixed<<setprecision(6)<<ans1<<endl;
				else cout<<fixed<<setprecision(6)<<ans2<<endl;
			}
		}
	}
	return 0;
}
