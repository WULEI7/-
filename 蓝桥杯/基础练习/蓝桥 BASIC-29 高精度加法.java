import java.util.Scanner;
import java.math.BigInteger;

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		BigInteger a,b,c;
		a=input.nextBigInteger();
		b=input.nextBigInteger();
		c=a.add(b);
		System.out.println(c);
	}
}
