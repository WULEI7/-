#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t;
    
    scanf("%d",&t);
    
    for(int c=1;c<=t;++c)
    {
        string s;
        
        cin >> s;
        
        int alp[30]={0}, maxx=0;
        
        for(int i=0;i<s.size();++i)
        {
            alp[s[i]-96]++;
            
            if(alp[s[i]-96]>maxx)
            {
                maxx = alp[s[i]-96];
            }
        }
        
        printf("Case #%d: %d\n",c,maxx);
    }
    
    return 0;
 } 
