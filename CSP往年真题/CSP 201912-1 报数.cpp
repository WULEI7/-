#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,a=0,b=0,c=0,d=0,i=1,j=1;
	cin>>n;
	while(j<=n)
	{
		int x=i,flag=0;
		if(x%7)
			while(x)
			{
				if(x%10==7)
				{
					flag=1;
					break;
				}
				x/=10;
			}
		else
			flag=1;
		if(flag==1)
		{
			if(i%4==1)
				a++;
			else if(i%4==2)
				b++;
			else if(i%4==3)
				c++;
			else if(i%4==0)
				d++;
		}//a��b��c��d�ֱ��¼���˸������������ָ��� 
		i++;//i�ǵ�ǰ������ 
		if(flag==0)
			j++;//j�ǵ�ǰ�Ѿ��������ֵ��ܸ��� 
	}
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	return 0;
}
