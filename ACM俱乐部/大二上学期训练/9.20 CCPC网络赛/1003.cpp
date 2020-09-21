#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(long long int a,long long int b)
{
    return a < b;
}

int main()
{
    int t;
    
    scanf("%d",&t);
    
    while(t--)
    {
        int n, m, k;
        
        scanf("%d %d %d",&n,&m,&k);
        
        vector<long long int> cab;
        
        for(int i=0;i<m;++i)
        {
            long long int num;
            
            scanf("%lld",&num);
            
            cab.push_back(num);
        }
        
        sort(cab.begin(),cab.end(),cmp);
        
        long long int ans = 0;
        
        if(cab[0]<k)
        {            
            for(int i=1;i<cab.size();++i)
            {
                ans += 2*abs(cab[i]-k);
            }
            
            ans += 2*(k-1);
        }
        else
        {
            for(int i=0;i<cab.size();++i)
            {
                ans += 2*(cab[i]-k);
            }
            
            ans += 2*(k-1);
        }
        
        printf("%lld\n",ans);
    }
    
    return 0;
}
