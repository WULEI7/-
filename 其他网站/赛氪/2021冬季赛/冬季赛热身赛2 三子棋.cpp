#include <iostream>
#include <cstdio>
using namespace std;
char mp[31][31];
int s, t;
int main()
{
    scanf("%d%d",&s,&t);
    for(int i=1;i<=s;i++)
        scanf("%s",mp[i]+1);
    for(int i=1;i<=s;i++)
    {
        for(int j=1;j<=t;j++)
        {
            //�жϵ�ǰ����Ϊ���ĵĺ������������Ƿ񹹳�������
            if(mp[i][j-1]==mp[i][j]&&mp[i][j]==mp[i][j+1]&&mp[i][j]!='.')
            {
                printf("%c\n", mp[i][j]);
                return 0;
            }
            //�жϵ�ǰ����Ϊ���ĵ��������������Ƿ񹹳�������
            if(mp[i-1][j]==mp[i][j]&&mp[i][j]==mp[i+1][j]&&mp[i][j]!='.')
            {
                printf("%c\n", mp[i][j]);
                return 0;
            }
            //�жϵ�ǰ����Ϊ���ĵ�б�ţ����ϵ����£����������Ƿ񹹳�������
            if(mp[i-1][j-1]==mp[i][j]&&mp[i][j]==mp[i+1][j+1]&&mp[i][j]!='.')
            {
                printf("%c\n", mp[i][j]);
                return 0;
            }
            //�жϵ�ǰ����Ϊ���ĵ�б�ţ����ϵ����£����������Ƿ񹹳�������
            if(mp[i-1][j+1]==mp[i][j]&&mp[i][j]==mp[i+1][j-1]&&mp[i][j]!='.')
            {
                printf("%c\n",mp[i][j]);
                return 0;
            }
        }
    }
    printf("ADPC!\n");
    return 0;
}
