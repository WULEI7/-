import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int n;
		double x,s=0,fm,fz,p,t;
		System.out.print("������������n��ʵ��x��");
		n=input.nextInt();
		x=input.nextDouble();
		p=1;
		for(int i=1;i<=n;i++) {
			if(i%2==1)
				t=1;
			else
				t=-1;
			p*=x;
			fm=p/x/x-t*(i+1);
			fz=p+i;
			s+=t*(fz/fm);
		}
		System.out.printf("S��ֵΪ��%f\n",s);
	}
}
