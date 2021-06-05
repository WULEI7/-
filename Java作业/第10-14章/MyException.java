import java.util.Scanner;
 
public class MyException
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		boolean continueInput=true;
		int num1=0,num2=0;
		System.out.println("请输入两个三位数：");
		do
		{
			try
			{
				num1=input.nextInt();
				num2=input.nextInt();
				if(num1<100||num1>999||num2<100||num2>999)
				{
					Exception e=new Exception();
					throw e;
				}
				continueInput=false;
			}
			catch(Exception e)
			{
				System.out.println("您的输入有误哟，请重新输入两个三位数：");
				input.nextLine();
			}
		}while(continueInput);
		System.out.println("两个数的和为"+(num1+num2));
	}
}