#include <bits/stdc++.h>
using namespace std;
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

int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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
	return 0;
}
