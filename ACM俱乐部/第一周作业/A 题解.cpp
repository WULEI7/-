#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int t[10100];
char a[10100],b[10100];
int main()
{
    int n,stl1,stl2,k,i;
    while(cin>>n>>a>>b)
    {
        stack<char>train;
        stl1=stl2=k=0;
        while(stl2<n)
        {
            if(train.empty()||train.top()!=b[stl2])
            {
                train.push(a[stl1++]);
                t[k++]=1;
            }
            else if(train.top()==b[stl2])
            {
                train.pop();
                t[k++]=0;
                stl2++;
            }
        }
        if(train.empty())
        {
            cout<<"Yes."<<endl;
            for(i=0;i<k;i++)
                if(t[i])
                    cout<<"in"<<endl;
                else
                    cout<<"out"<<endl;
        }
        else
            cout<<"No."<<endl;
        cout<<"FINISH"<<endl;
    }
}
