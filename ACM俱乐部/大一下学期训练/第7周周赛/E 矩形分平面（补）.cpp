#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,x1,x2,x3,x4,y1,y2,y3,y4;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		
		if(x1==x3&&y1==y3&&x2==x4&&y2==y4) cout<<"2"<<endl;//��ȫ�غ� 
		
		else if(x1<x3&&y1>y3&&x2>x4&&y2<y4) cout<<"6"<<endl;
		else if(x1>x3&&y1<y3&&x2<x4&&y2>y4) cout<<"6"<<endl;//ʮ���� 
		
		else if(x2<=x3||x1>=x4||y2<=y3||y1>=y4) cout<<"3"<<endl;//���� 
		
		else if(x1<x3&&x2>x4&&y1==y3&&y2==y4) cout<<"4"<<endl;
		else if(x1>x3&&x2<x4&&y1==y3&&y2==y4) cout<<"4"<<endl;
		else if(y1<y3&&y2>y4&&x1==x3&&x2==x4) cout<<"4"<<endl;
		else if(y1>y3&&y2<y4&&x1==x3&&x2==x4) cout<<"4"<<endl;//�ں����Ա��غϣ� 
		
		else if(x1<=x3&&y1<=y3&&x2>=x4&&y2>=y4) cout<<"3"<<endl;
		else if(x1>=x3&&y1>=y3&&x2<=x4&&y2<=y4) cout<<"3"<<endl;//�ں���ȥ���Ա��غϵ������ 
		
		else if(x1<x3&&y1>y3&&x2==x4&&y2<y4) cout<<"5"<<endl;
		else if(x1>x3&&y1<y3&&x2==x4&&y2>y4) cout<<"5"<<endl;
		else if(x1==x3&&y1>y3&&x2>x4&&y2<y4) cout<<"5"<<endl;
		else if(x1==x3&&y1<y3&&x2<x4&&y2>y4) cout<<"5"<<endl;
		else if(x1<x3&&y1>y3&&x2>x4&&y2==y4) cout<<"5"<<endl;
		else if(x1>x3&&y1<y3&&x2<x4&&y2==y4) cout<<"5"<<endl;
		else if(x1<x3&&y1==y3&&x2>x4&&y2<y4) cout<<"5"<<endl;
		else if(x1>x3&&y1==y3&&x2<x4&&y2>y4) cout<<"5"<<endl;//������ 
		
		else cout<<"4"<<endl;//���� 
	}
	return 0;
}
