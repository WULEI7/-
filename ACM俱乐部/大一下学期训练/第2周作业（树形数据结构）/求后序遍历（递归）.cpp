#include<iostream>
#include<string.h>
using namespace std;
int q[10000],w[10000];
int e;
//已知先序 中序 求后序 
void dg(int r1,int l1,int r2,int l2)
{int i;if(r1>l1) return;
for(i=r2;w[i]!=q[r1];i++);
dg(r1+1,l1-l2+i,r2,i-1);
dg(l1-l2+i+1,l1,i+1,l2);
if(e==1){cout<<q[r1];e=0;}
else cout<<" "<<q[r1];
}
int main()
{int n;
while(cin>>n)
{
e=1;
for(int i=0;i<n;i++)
cin>>q[i];
for(int i=0;i<n;i++)
cin>>w[i];
dg(0,n-1,0,n-1);
cout<<endl;
}
return 0;
}
