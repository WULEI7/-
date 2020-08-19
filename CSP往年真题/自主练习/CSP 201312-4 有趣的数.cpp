#include <cstdio>
using namespace std;
const long long mod=1e9+7;
long long f[1005][7]={0};
int main()
{
	int n;
	scanf("%d",&n);
    f[1][1]=1;//一位数 
    for(int i=2;i<=n;i++)
    {
        f[i][1]=1;//只包含2 
        f[i][2]=(f[i-1][2]*2+f[i-1][1])%mod;//包含0和2 
        f[i][3]=(f[i-1][3]+f[i-1][1])%mod;//包含2和3 
        f[i][4]=(f[i-1][4]*2+f[i-1][2])%mod;//包含2、0、1，满足0在1前 
        f[i][5]=(f[i-1][5]*2+f[i-1][2]+f[i-1][3])%mod;//包含2、0、3，满足2在3前 
        f[i][6]=(f[i-1][6]*2+f[i-1][4]+f[i-1][5])%mod;//包含2、0、1、3，满足0在1前、2在3前 
    }
    printf("%d\n",f[n][6]);
    return 0;
}
