#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int t;
    char s[20];
    scanf("%d",&t);
    while(t--)
    {
        int ans=0;
        char c[4];
        int num[4];
        int ni=0,ci=0;
        int temp;
        scanf("%s",s);
        int i;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]>='1' && s[i]<='9')
            {
                num[ni++]=s[i]-48;
            }
            if(s[i]=='+' || s[i]=='-')
            {
                c[ci++]=s[i];
            }
            if(s[i]=='x')
            {
                num[ni]=s[i+1]-48;
                i++;
                temp=num[ni-1]*num[ni];
                num[ni-1]=temp;
            }
            if(s[i]=='/')
            {
                num[ni]=s[i+1]-48;
                i++;
                temp=num[ni-1]/num[ni];
                num[ni-1]=temp;
            }
        }
        ans+=num[0];
        for(i=1;i<ni;i++)
        {
            if(c[i-1]=='+') ans+=num[i];
            else ans-=num[i];
        }
        if(ans==24) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
