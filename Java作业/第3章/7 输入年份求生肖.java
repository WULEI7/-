import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int year,k;
		String sx="";
		System.out.print("��������ݣ�1-9999����");
		year=input.nextInt();
		while(year<=0||year>=10000)
		{
			System.out.print("�����������������������룺");
			year=input.nextInt();
		}
		//2020��������
		//ʮ����Ф����ţ������������Ｆ����
		k=(year+2400-2020)%12;
		switch(k) {
			case 0:sx="��";break;
			case 1:sx="ţ";break;
			case 2:sx="��";break;
			case 3:sx="��";break;
			case 4:sx="��";break;
			case 5:sx="��";break;
			case 6:sx="��";break;
			case 7:sx="��";break;
			case 8:sx="��";break;
			case 9:sx="��";break;
			case 10:sx="��";break;
			case 11:sx="��";break;
		}
		System.out.printf("%d����%s��",year,sx);
	}
}
