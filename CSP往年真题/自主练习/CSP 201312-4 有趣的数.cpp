#include <cstdio>
using namespace std;
const long long mod=1e9+7;
long long f[1005][7]={0};
int main()
{
	int n;
	scanf("%d",&n);
    f[1][1]=1;//һλ�� 
    for(int i=2;i<=n;i++)
    {
        f[i][1]=1;//ֻ����2 
        f[i][2]=(f[i-1][2]*2+f[i-1][1])%mod;//����0��2 
        f[i][3]=(f[i-1][3]+f[i-1][1])%mod;//����2��3 
        f[i][4]=(f[i-1][4]*2+f[i-1][2])%mod;//����2��0��1������0��1ǰ 
        f[i][5]=(f[i-1][5]*2+f[i-1][2]+f[i-1][3])%mod;//����2��0��3������2��3ǰ 
        f[i][6]=(f[i-1][6]*2+f[i-1][4]+f[i-1][5])%mod;//����2��0��1��3������0��1ǰ��2��3ǰ 
    }
    printf("%d\n",f[n][6]);
    return 0;
}
