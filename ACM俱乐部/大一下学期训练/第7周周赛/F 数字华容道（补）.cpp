#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,x[17];
	cin>>t;
	while(t--)
	{
		int wz;
		for(int i=1;i<=16;i++)
		{
			cin>>x[i];
			if(x[i]==0) wz=i;
		}//��wz��¼�ո��λ�� 
		while(wz<=12)
		{
			int temp=x[wz];
			x[wz]=x[wz+4];
			x[wz+4]=temp;
			wz+=4;
		}//�ѿո񻻵����һ�� 
		int tot=0;
		for(int i=1;i<16;i++)
			for(int j=i+1;j<=16;j++)
			{
				if(x[j]!=0&&x[j]<x[i])
				tot++;
			}//��tot��¼���������� 
		if(tot%2==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
