import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		final int INF=1999999999;
		int cnt=0,sum=0,zcnt=0,fcnt=0,zmax=1,zmin=INF,fmax=-INF,fmin=-1,temp=1;
		double average,fangcha=0;
		int[] num=new int[1005];
		System.out.print("请输入一行数，以0结束：");
		while(temp!=0) {
			temp=input.nextInt();
			if(temp==0) break;
			num[cnt++]=temp;
			sum+=temp;
			if(temp>0) {
				zcnt++;
				if(temp>zmax) zmax=temp;
				if(temp<zmin) zmin=temp;
			}
			if(temp<0) {
				fcnt++;
				if(temp>fmax) fmax=temp;
				if(temp<fmin) fmin=temp;
			}
		}
		average=sum/cnt;
		for(int i=0;i<cnt;i++)
			fangcha+=(num[i]-average)*(num[i]-average);
		System.out.printf("正整数个数为%d，负整数个数为%d\n",zcnt,fcnt);
		if(zcnt>0)
			System.out.printf("正整数的最大值为%d，最小值为%d\n",zmax,zmin);
		else
			System.out.print("输入的数中不含正整数\n");
		if(fcnt>0)
			System.out.printf("负整数的最大值为%d，最小值为%d\n",fmax,fmin);
		else
			System.out.print("输入的数中不含负整数\n");
		System.out.printf("所有数的平均数为%f，均方差为%f\n", average,fangcha);
	}
}
