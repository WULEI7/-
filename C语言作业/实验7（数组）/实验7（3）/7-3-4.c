#include <stdio.h> 
#define N 10
int main()
{  	int a[]={0,1,2,3,4,5,6,7,8,9},k;
   	int low=0,high=9,mid,find=0;
   	printf("请输入欲查找的值：\n");
   	scanf("%d",&k);
   	while(low<=high)
   	{
    	mid=(low+high)/2;
    	if(a[mid]==k)
    	{
      		printf("找到位置为：%d\n",mid+1);find=1;break;
    	}
    	if(a[mid]>k)
    	high--;
    	else
    	low++;
		}
	if (!find) printf("%d未找到\n",k);
	return 0;
}
