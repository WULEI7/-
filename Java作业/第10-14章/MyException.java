import java.util.Scanner;
 
public class MyException
{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		boolean continueInput=true;
		int num1=0,num2=0;
		System.out.println("������������λ����");
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
				System.out.println("������������Ӵ������������������λ����");
				input.nextLine();
			}
		}while(continueInput);
		System.out.println("�������ĺ�Ϊ"+(num1+num2));
	}
}