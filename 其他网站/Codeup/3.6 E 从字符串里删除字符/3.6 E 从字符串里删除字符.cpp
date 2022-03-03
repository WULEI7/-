#include<stdio.h>
#include<string.h>
int main(){
	//freopen("test0.in","r",stdin);
    char str[10005];//题目没说字符串长度，开100太小比较危险 
    //如果用string则不用考虑长度问题 
    char c;
    //while(scanf("%s\n%c",str,&c)!=EOF){
    //因为字符串里面可能有空格（题目没说不含空格），不能用scanf输入字符串 
    while(fgets(str,10005,stdin))
    {
    	scanf("%c",&c);//scanf里面最好不要放\n,容易出错 
    	getchar();//接收回车 
        int len=strlen(str);
        int n=0;
        //char str1[10005];
        //int x[10000];//记录字符所在位置 
        //既然想到记录字符所在位置了，大可以直接这样写 
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
        //这里面应该还是逻辑有些问题
		//比如输入是gooooood和o的时候，输出就不对 
        //printf("%s\n",str1);
        for(int i=0;i<strlen(str);i++)
        {
        	if(x[i]==0)//没有标记过的 
        		printf("%c",str[i]);
		}
		//printf("\n");
		//fgets自动换行了，所以这里不用输出换行，否则会格式错误 
		//如果用C++ string会方便得多，参考另外两道题 
    }
    return 0;
}
