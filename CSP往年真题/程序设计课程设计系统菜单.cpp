#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
void f1();//��������
void f2();
void f3();
int main(){
    int t;
    char ch;
    for(;;){
        cout<<endl<<endl;
        cout<<"==========0--�˳�============"<<endl;
        cout<<"==========1--����============"<<endl;
        cout<<"==========2--����վѡַ======"<<endl;
        cout<<"==========3--��ѧ����ʽ======"<<endl;
        cout<<"===������ϣ�����еĲ������:==="<<endl;
        cin>>t;
        if(t==1)
            f1();
        else if(t==2)
            f2();
        else if(t==3)
            f3();
        else if(t==0)
            exit(0);
        ch=getch();//ʹ��Ļ��ͣ�����������
        system("cls");//����
    }
    return 0;
}
void f1(){
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
	return;
}
void f2(){
	int n,cnt[5]={0};
	vector<pair<int,int> > pos;//������������������� 
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		pos.push_back({x,y});
	}
	for(int i=0;i<n;i++)
	{
		int x=pos[i].first,y=pos[i].second,flag=0;
		for(int j=0;j<n;j++)
		{
			if(pos[j].first==x-1&&pos[j].second==y)
				flag++;
			if(pos[j].first==x+1&&pos[j].second==y)
				flag++;
			if(pos[j].first==x&&pos[j].second==y-1)
				flag++;
			if(pos[j].first==x&&pos[j].second==y+1)
				flag++;
		}//�ж��Ƿ�������������Ĵ��������� 
		if(flag==4)
		{
			int temp=0;
			for(int j=0;j<n;j++)
			{
				if(pos[j].first==x-1&&pos[j].second==y-1)
					temp++;
				if(pos[j].first==x-1&&pos[j].second==y+1)
					temp++;
				if(pos[j].first==x+1&&pos[j].second==y-1)
					temp++;
				if(pos[j].first==x+1&&pos[j].second==y+1)
					temp++;
			}
			cnt[temp]++;
		}//�ж��ĸ��Խ�λ���м���������������cnt����Բ�ͬ�÷ֵĻ���վѡַ���� 
	}
	for(int i=0;i<5;i++)
		cout<<cnt[i]<<endl;
	return;
}
map<string,int> leftcnt,rightcnt;//���Ⱥ�������������ԭ�Ӹ����ֱ����map�н��м��� 
void deal(int lr,int xishu,string fenzi)//�Է���ʽ��ȥ��ǰ���ϵ�������� 
{
	map<string,int> tempcnt;
	for(int i=0;i<fenzi.length();i++)
	{
		if(isupper(fenzi[i]))
		{
			string t;
			t+=fenzi[i];
			if(i+1<fenzi.length())
				if(islower(fenzi[i+1]))
					t+=fenzi[i+1];
			tempcnt[t]=1;
		}//������ԭ�Ӵ���tempcnt�� 
	}
	map<string,int>::iterator it;
	for(it=tempcnt.begin();it!=tempcnt.end();it++)
	{
		string yuanzi=it->first;
		int pos=0,sum=0,wz=0;
		while(pos<fenzi.length()&&wz!=-1)
		{
			int geshu=1;
			wz=fenzi.find(yuanzi,pos);
			if(wz!=-1)
				if(yuanzi.length()==2||(yuanzi.length()==1&&!islower(fenzi[wz+1])))//�ų�����Ҫ���ҵ�ԭ����N��������ʽ����Na����� 
				{
					for(int i=fenzi.length()-1;i>=wz+yuanzi.length();i--)
					{
						if(fenzi[i]==')')
						{
							int flag=1,kuohao=1;
							for(int j=i-1;j>=0;j--)
							{
								if(fenzi[j]=='(')
									kuohao--;
								else if(fenzi[j]==')')
									kuohao++;
								if(kuohao==0)
								{
									if(j>wz)
										flag=0;
									break;
								}
							}//�жϵ�ǰ���ҵ���ԭ���Ƿ������������ 
							if(flag==1)
							{
								int houzhui=0;
								string hz;
								if(i<fenzi.length()-1)//����������Na(Au(CN)2)������ź���û�к�׺�ķ���ʽ 
								{
									for(int k=i+1;k<fenzi.length();k++)
									{
										if(fenzi[k]>='0'&&fenzi[k]<='9')
											hz+=fenzi[k];
										else break;
									}
									for(int k=0;k<hz.length();k++)
									{
										houzhui*=10;
										houzhui+=(hz[k]-'0');
									}//��ȡ�����ź�ĺ�׺����houzhui��¼ 
								}
								if(houzhui==0)
									houzhui=1;//�������ź�û�к�׺�����׺Ϊ1 
								geshu*=houzhui;//ԭ�Ӹ������Ժ�׺ 
							}
						}//�ӷ���ʽ�Ҷ�������ҡ����� 
					}
					int hou=0;
					string h;
					if(wz+yuanzi.length()<fenzi.length())
					{
						for(int k=wz+yuanzi.length();k<fenzi.length();k++)
						{
							if(fenzi[k]>='0'&&fenzi[k]<='9')
								h+=fenzi[k];
							else break;
						}
						for(int k=0;k<h.length();k++)
						{
							hou*=10;
							hou+=(h[k]-'0');
						}//��ȡԭ�Ӻ�ĺ�׺����hou��¼ 
					}
					if(hou==0)
						hou=1;//��ԭ�Ӻ�û�к�׺�����׺Ϊ1 
					geshu*=hou;//ԭ�Ӹ������Ժ�׺ 
					sum+=geshu;
				}
			pos=wz+1;
		}//ԭ�ӿ����ڷ���ʽ�ж�γ��֣�����Ҫ�������� 
		sum*=xishu;
		if(lr==1)
			leftcnt[yuanzi]+=sum;
		else if(lr==2)
			rightcnt[yuanzi]+=sum;
	}//��tempcnt��ÿ��ԭ����ԭ����ʽ�н��в��Һʹ��� 
	return;
}
void f3()
{
	int n;
	cin>>n;
	while(n--)
	{
		leftcnt.clear(),rightcnt.clear();//���map 
		string fangcheng,left,right;
		cin>>fangcheng;//���뻯ѧ����ʽ 
		int equal;
		for(int i=0;i<fangcheng.length();i++)
			if(fangcheng[i]=='=')
			{
				equal=i;
				break;
			}//�ҵ��Ⱥŵ�λ�ã���equal��¼ 
		for(int i=0;i<equal;i++)
			left+=fangcheng[i];
		for(int i=equal+1;i<fangcheng.length();i++)
			right+=fangcheng[i];//������ʽ��Ϊ���������֣��ֱ���left��right���� 
		left.insert(0,"+");//ʹÿ������ʽ����ϵ����ǰ���ǡ�+�������ڴ��� 
		for(int i=0;i<left.length();i++)
		{
			if(left[i]=='+')
			{
				int xishu=0,p;
				string xs;
				for(int j=i+1;j<left.length();j++)
				{
					if(left[j]>='0'&&left[j]<='9')
						xs+=left[j];
					else
					{
						p=j;
						break;
					}
				}
				for(int j=0;j<xs.length();j++)
				{
					xishu*=10;
					xishu+=(xs[j]-'0');
				}//��ȡÿ������ʽǰ��ϵ������xishu��¼ 
				if(xishu==0)
					xishu=1;//������ʽǰ����ϵ������ϵ��Ϊ1 
				string fenzishi;
				for(int j=p;j<left.length()&&left[j]!='+';j++)
					fenzishi+=left[j];//��ȡ����ϵ���ķ���ʽ 
				deal(1,xishu,fenzishi);
			}//��ÿ������ʽ���д��� 
		}//����Ⱥ����� 
		right.insert(0,"+");//ʹÿ������ʽ����ϵ����ǰ���ǡ�+�������ڴ��� 
		for(int i=0;i<right.length();i++)
		{
			if(right[i]=='+')
			{
				int xishu=0,p;
				string xs;
				for(int j=i+1;j<right.length();j++)
				{
					if(right[j]>='0'&&right[j]<='9')
						xs+=right[j];
					else
					{
						p=j;
						break;
					}
				}
				for(int j=0;j<xs.length();j++)
				{
					xishu*=10;
					xishu+=(xs[j]-'0');
				}//��ȡÿ������ʽǰ��ϵ������xishu��¼ 
				if(xishu==0)
					xishu=1;//������ʽǰ����ϵ������ϵ��Ϊ1 
				string fenzishi;
				for(int j=p;j<right.length()&&right[j]!='+';j++)
					fenzishi+=right[j];//��ȡ����ϵ���ķ���ʽ 
				deal(2,xishu,fenzishi);
			}//��ÿ������ʽ���д��� 
		}//����Ⱥ��Ұ�� 
		bool flag=1;
		if(leftcnt.size()!=rightcnt.size())
			flag=0;
		else
		{
			map<string,int>::iterator it;
		    for(it=leftcnt.begin();it!=leftcnt.end();it++)
			{
				map<string,int>::iterator itt;
				itt=rightcnt.find(it->first);
				if(itt==rightcnt.end())
					flag=0;//û�ҵ���Ӧ��ԭ�� 
				if(itt->second!=it->second)
					flag=0;//��Ӧ��ԭ�Ӹ�����ͬ 
			}
		}//����ж�leftcnt��rightcnt�Ƿ���ȫ��ȣ����Ƿ���ƽ 
		if(flag)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return;
}
