import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int n;
		int[][] a=new int[25][25];
		System.out.print("«Î ‰»În£∫");
		n=input.nextInt();
		a[1][1]=1;
		for(int i=2;i<=n;i++)
		{
			a[i][1]=a[i][i]=1;
			for(int j=2;j<i;j++)
				a[i][j]=a[i-1][j-1]+a[i-1][j];
		}
		for(int i=1;i<=n;i++)
		{
			System.out.print("1    ");
			for(int j=2;j<=i;j++)
				System.out.printf("%-5d",a[i][j]);
			System.out.print("\n");
		}
	}
}
