import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int year,k;
		String sx="";
		System.out.print("请输入年份（1-9999）：");
		year=input.nextInt();
		while(year<=0||year>=10000)
		{
			System.out.print("您输入的年份有误，请重新输入：");
			year=input.nextInt();
		}
		//2020年是鼠年
		//十二生肖：鼠牛虎兔龙蛇马羊猴鸡狗猪
		k=(year+2400-2020)%12;
		switch(k) {
			case 0:sx="鼠";break;
			case 1:sx="牛";break;
			case 2:sx="虎";break;
			case 3:sx="兔";break;
			case 4:sx="龙";break;
			case 5:sx="蛇";break;
			case 6:sx="马";break;
			case 7:sx="羊";break;
			case 8:sx="猴";break;
			case 9:sx="鸡";break;
			case 10:sx="狗";break;
			case 11:sx="猪";break;
		}
		System.out.printf("%d年是%s年",year,sx);
	}
}
