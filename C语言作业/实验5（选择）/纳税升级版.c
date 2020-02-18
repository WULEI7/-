#include<stdio.h>
int main()
{   float income,n,tax;
    printf("请输入您的收入和是否离退休人员（1表示是，0表示否）：");
    scanf("%f,%f",&income,&n);
    if (income<=3500||n==1)
    {printf("免纳税！");
	}
	else if (income>3500 && income<=5000)
    {   tax=(income-3500)*0.03;
    printf("纳税金额为%.2f",tax);
    }
    else if (income>5000 && income<=8000)
    {   tax=1500*0.03+(income-5000)*0.10;
    printf("纳税金额为%.2f",tax);
    }
    else if (income>8000)
    {   tax=1500*0.03+3000*0.10+(income-8000)*0.2;
    printf("纳税金额为%.2f",tax);
    }
    return 0;
}
