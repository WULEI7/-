#include<iostream>  
#include<algorithm>  
#include<cstring>  
#include<cstdio>  
#include<cmath>  
#include<queue>  
using namespace std;  
const int MXN = 1e5 + 5, MXM = 2e5 + 5;  
struct Node{  
    int a, b, t;  
    bool operator< (const Node node)const{  
        return t < node.t;  
    }  
}e[MXM];  
int n, m, par[MXM];  
void init()  
{  
    for(int i = 0; i <= n; i++)  
    {  
        par[i] = i;  
    }  
}  
int fid(int x)  
{  
    return par[x] == x? x : par[x] = fid(par[x]);  
}  
int main()  
{  
    while(scanf("%d%d", &n, &m) != EOF)  
    {  
        for(int i = 0; i < m; i++)  
            scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].t);  
        init();  
        sort(e, e + m);  
        for(int i = 0; i < m; i++)  
        {  
            int x = fid(e[i].a);  
            int y = fid(e[i].b);  
            if(x != y)  
            {  
                par[x] = y;  
            }  
            if(fid(1) == fid(n))  
            {  
                printf("%d\n", e[i].t);  
                break;  
            }  
        }  
    }  
    return 0;  
}  

