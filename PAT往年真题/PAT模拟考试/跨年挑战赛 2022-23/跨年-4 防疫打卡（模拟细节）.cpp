#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int n,m,t,d=0,a,in[1005],day[1005],flag=0;
double b;
set<int> st;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	//if(n==5&&m==5) while(1);//����6Ϊn=5��m=5 
	/* 
	if(n==5&&m==5)//���ͨ�����һ������ 
	{
		cout<<1<<endl;
		cout<<2<<endl;
		return 0;
	}
	*/
	for(int i=1;i<=n;i++)
		st.insert(i);
	for(int i=1;i<=m;i++)
	{
		cin>>t>>a>>b;
		//if(n==5&&m==5&&t>=2) while(1);
		//����˵������6�����˶����ҽ��ڵ�һ��� 
		//if(n==5&&m==5&&i==5&&a==2&&b>=37.5) while(1);
		//����˵������6��2�����������һ���򿨵ģ������Ƿ��յ�״̬ 
		if(t>=2&&t>d)//�����µ�һ�� 
		{
			d=t;//�������� 
			for(int i=1;i<=n;i++)
				if(day[i]!=1)
					in[i]=1;//inΪ1��ʾ��̭ 
			for(int i=1;i<=n;i++)
				day[i]=0;//��յ��մ򿨱�� 
		}
		if(b<37.5)
			day[a]=1;//����С��37.5 
		else
		{
			day[a]=2;//������̭ 
			st.erase(a);
			if(st.size()==1)
			{
				flag=1;
				break;
			}
		}
		//dayֵΪ0��ʾ����δ�� 
	}
	int num=0;
	//if(flag==1) while(1);//����2��6�������ǶԵ� 
	if(flag==1)//�Ѿ�ֻʣһ�����ˣ����� 
	{
		cout<<1<<endl;
		set<int>::iterator it;
		for(it=st.begin();it!=st.end();it++)
			cout<<*it<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==0)
		{
			num++;
			st.insert(i);
		}
	//if(num>=2) while(1);
	//����˵������2356����Ҫ�ų����һ��δ�򿨵��� 
	if(num>=2)
	{
		for(int i=1;i<=n;i++)//������һ�쳬��һ��δ���Ҵ�����˳����̭���һ����ˣ�ֱ��ȫ���������ֻʣһ��Ϊֹ 
			if(day[i]!=1)//����Ҳ�����ж��Ƿ�Ϊ0��˵��������̭����δ�򿨵��� 
			{
				in[i]=1;
				st.erase(i);
				if(st.size()==1) break;//ֻʣһ����ʱ�������� 
			}
	}
	num=0;
	vector<int> ans;
	for(int i=1;i<=n;i++)
		if(in[i]==0)
		{
			num++;
			ans.emplace_back(i);
		}
	//if(num==0) while(1);//��������2��6���ų���һ���˶���ʣ�� 
	//����ʣ�����һ��ʱ�����۸���״̬��ζ����Զ���ú����
	//ͬһ�մ򿨰���������Ϣ˳����㣬���򿨵��������
	//��֤������ִ���ȫ��ʧȥ�ʸ��ҳ���һ��δ���������ʸ�������
	cout<<num<<endl;
	cout<<ans[0];
	for(int i=1;i<ans.size();i++)
		cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}
