#include<stdio.h>
#include<string.h>
int main(){
	//freopen("test0.in","r",stdin);
    char str[10005];//��Ŀû˵�ַ������ȣ���100̫С�Ƚ�Σ�� 
    //�����string���ÿ��ǳ������� 
    char c;
    //while(scanf("%s\n%c",str,&c)!=EOF){
    //��Ϊ�ַ�����������пո���Ŀû˵�����ո񣩣�������scanf�����ַ��� 
    while(fgets(str,10005,stdin))
    {
    	scanf("%c",&c);//scanf������ò�Ҫ��\n,���׳��� 
    	getchar();//���ջس� 
        int len=strlen(str);
        int n=0;
        //char str1[10005];
        //int x[10000];//��¼�ַ�����λ�� 
        //��Ȼ�뵽��¼�ַ�����λ���ˣ������ֱ������д 
        int x[10005]={0}; 
        for(int i=0;i<len;i++){
            if(str[i]==c){
                //x[n++]=i;
                x[i]=1;
                //printf("%d\n",i);
            }
        }
        /*
        int t=0;
        for(int i=0;i<len;i++){
	        int k=0;
            for(int j=0;j<n;j++){
                if(i==x[j]){
                    i++;
                    k=1;
                    t+=k;
                    break;
                }
            }
            str1[i-t]=str[i];
        }
        */
        //������Ӧ�û����߼���Щ����
		//����������gooooood��o��ʱ������Ͳ��� 
        //printf("%s\n",str1);
        for(int i=0;i<strlen(str);i++)
        {
        	if(x[i]==0)//û�б�ǹ��� 
        		printf("%c",str[i]);
		}
		//printf("\n");
		//fgets�Զ������ˣ��������ﲻ��������У�������ʽ���� 
		//�����C++ string�᷽��ö࣬�ο����������� 
    }
    return 0;
}
