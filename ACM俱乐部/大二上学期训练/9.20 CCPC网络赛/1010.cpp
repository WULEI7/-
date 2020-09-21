#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    int t;
    
    scanf("%d",&t);
    
    while(t--)
    {
        int n;
        
        scanf("%d",&n);
        
        int flag = 1, pre = -1, num;
        
        for(int i=0;i<n;++i)
        {
            scanf("%d",&num);
            
            if(num==pre)
            {
                flag = 0;
            }
            else
            {
                pre = num;
            }
        }
        
        if(flag == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    
    return 0;
 } 
