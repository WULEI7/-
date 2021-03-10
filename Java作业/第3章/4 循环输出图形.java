import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		for(int i=0;i<=3;i++) {
			for(int j=0;j<3-i;j++)
				System.out.print(" ");
			for(int j=0;j<2*(i+1);j++)
				System.out.printf("%c",'A'+j);
			System.out.print("\n");
		}
		for(int i=1;i<=3;i++) {
			for(int j=0;j<i;j++)
				System.out.print(" ");
			for(int j=2*(4-i);j>=1;j--)
				System.out.printf("%d",j);
			System.out.print("\n");
		}
	}
}
