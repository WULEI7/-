#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
void f1();//函数声明
void f2();
void f3();
int main(){
    int t;
    char ch;
    for(;;){
        cout<<endl<<endl;
        cout<<"==========0--退出============"<<endl;
        cout<<"==========1--报数============"<<endl;
        cout<<"==========2--回收站选址======"<<endl;
        cout<<"==========3--化学方程式======"<<endl;
        cout<<"===请输入希望进行的操作序号:==="<<endl;
        cin>>t;
        if(t==1)
            f1();
        else if(t==2)
            f2();
        else if(t==3)
            f3();
        else if(t==0)
            exit(0);
        ch=getch();//使屏幕暂停，任意键继续
        system("cls");//清屏
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
		}//a、b、c、d分别记录四人各自跳过的数字个数 
		i++;//i是当前的数字 
		if(flag==0)
			j++;//j是当前已经报出数字的总个数 
	}
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<c<<endl;
	cout<<d<<endl;
	return;
}
void f2(){
	int n,cnt[5]={0};
	vector<pair<int,int> > pos;//保存所有垃圾点的坐标 
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
		}//判断是否符合上下左右四处都有垃圾 
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
		}//判断四个对角位置有几处有垃圾，并用cnt数组对不同得分的回收站选址计数 
	}
	for(int i=0;i<5;i++)
		cout<<cnt[i]<<endl;
	return;
}
map<string,int> leftcnt,rightcnt;//将等号左右两边所有原子个数分别存入map中进行计数 
void deal(int lr,int xishu,string fenzi)//对分子式（去掉前面的系数）处理 
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
		}//将所有原子存入tempcnt中 
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
				if(yuanzi.length()==2||(yuanzi.length()==1&&!islower(fenzi[wz+1])))//排除比如要查找的原子是N，而分子式中是Na的情况 
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
							}//判断当前查找到的原子是否在这对括号内 
							if(flag==1)
							{
								int houzhui=0;
								string hz;
								if(i<fenzi.length()-1)//样例中有如Na(Au(CN)2)最后括号后面没有后缀的分子式 
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
									}//提取右括号后的后缀，用houzhui记录 
								}
								if(houzhui==0)
									houzhui=1;//若右括号后没有后缀，则后缀为1 
								geshu*=houzhui;//原子个数乘以后缀 
							}
						}//从分子式右端往左查找“）” 
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
						}//提取原子后的后缀，用hou记录 
					}
					if(hou==0)
						hou=1;//若原子后没有后缀，则后缀为1 
					geshu*=hou;//原子个数乘以后缀 
					sum+=geshu;
				}
			pos=wz+1;
		}//原子可能在分子式中多次出现，所以要挨个查找 
		sum*=xishu;
		if(lr==1)
			leftcnt[yuanzi]+=sum;
		else if(lr==2)
			rightcnt[yuanzi]+=sum;
	}//对tempcnt中每个原子在原分子式中进行查找和处理 
	return;
}
void f3()
{
	int n;
	cin>>n;
	while(n--)
	{
		leftcnt.clear(),rightcnt.clear();//清空map 
		string fangcheng,left,right;
		cin>>fangcheng;//输入化学方程式 
		int equal;
		for(int i=0;i<fangcheng.length();i++)
			if(fangcheng[i]=='=')
			{
				equal=i;
				break;
			}//找到等号的位置，用equal记录 
		for(int i=0;i<equal;i++)
			left+=fangcheng[i];
		for(int i=equal+1;i<fangcheng.length();i++)
			right+=fangcheng[i];//将方程式分为左右两部分，分别用left、right保存 
		left.insert(0,"+");//使每个分子式（含系数）前都是“+”，便于处理 
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
				}//提取每个分子式前的系数，用xishu记录 
				if(xishu==0)
					xishu=1;//若分子式前不含系数，则系数为1 
				string fenzishi;
				for(int j=p;j<left.length()&&left[j]!='+';j++)
					fenzishi+=left[j];//提取不含系数的分子式 
				deal(1,xishu,fenzishi);
			}//对每个分子式进行处理 
		}//处理等号左半边 
		right.insert(0,"+");//使每个分子式（含系数）前都是“+”，便于处理 
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
				}//提取每个分子式前的系数，用xishu记录 
				if(xishu==0)
					xishu=1;//若分子式前不含系数，则系数为1 
				string fenzishi;
				for(int j=p;j<right.length()&&right[j]!='+';j++)
					fenzishi+=right[j];//提取不含系数的分子式 
				deal(2,xishu,fenzishi);
			}//对每个分子式进行处理 
		}//处理等号右半边 
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
					flag=0;//没找到相应的原子 
				if(itt->second!=it->second)
					flag=0;//相应的原子个数不同 
			}
		}//最后判断leftcnt和rightcnt是否完全相等，即是否配平 
		if(flag)
			cout<<"Y"<<endl;
		else
			cout<<"N"<<endl;
	}
	return;
}
