#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int w[1000005],k,cnt=0;
bool check(int x)
{
	int line=1,temp=0;
	for(int i=0;i<cnt;i++)
	{
		temp+=w[i];
		if(i==cnt-1&&line<=k&&temp<=x)
			return true;
		if(line>k)
			return false;
		if(temp==x)
		{
			line++;
			temp=0;
		}
		if(temp>x)
		{
			line++;
			i--;
			temp=0;
		}
	}
}//��鵱ǰ����ܷ�д���������� 
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>k;
	cin.ignore();//ע����cin��ʹ��getline��ǰ����ϴ˾� 
	getline(cin,s);
	int len=s.length(),pos=-1;
	for(int i=0;i<len;i++)
	{
		if(s[i]==' '||s[i]=='-'||i==len-1)
		{
			w[cnt++]=i-pos;
			pos=i;
		}
	}//��w�����ȡ���зִʳ��� 
	for(int i=1;;i++)
	{
		if(check(i))
		{
			cout<<i<<endl;
			break;
		}
	}//�ӿ��1��ʼ���μ���Ƿ���� 
	return 0;
}
