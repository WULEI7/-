import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		final int INF=1999999999;
		int cnt=0,sum=0,zcnt=0,fcnt=0,zmax=1,zmin=INF,fmax=-INF,fmin=-1,temp=1;
		double average,fangcha=0;
		int[] num=new int[1005];
		System.out.print("������һ��������0������");
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
		System.out.printf("����������Ϊ%d������������Ϊ%d\n",zcnt,fcnt);
		if(zcnt>0)
			System.out.printf("�����������ֵΪ%d����СֵΪ%d\n",zmax,zmin);
		else
			System.out.print("��������в���������\n");
		if(fcnt>0)
			System.out.printf("�����������ֵΪ%d����СֵΪ%d\n",fmax,fmin);
		else
			System.out.print("��������в���������\n");
		System.out.printf("��������ƽ����Ϊ%f��������Ϊ%f\n", average,fangcha);
	}
}
