import java.util.Scanner;

public class Test {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		String Num,Clas,Name,Sex,Coursename;
		int Age,Coursenum;
		System.out.print("������ѧ��ѧ�ţ�");
		Num=input.next();
		System.out.print("������ѧ���༶��");
		Clas=input.next();
		System.out.print("������ѧ��������");
		Name=input.next();
		System.out.print("������ѧ���Ա�");
		Sex=input.next();
		System.out.print("������ѧ�����䣺");
		Age=input.nextInt();
		Student stu=new Student(Num,Clas,Name,Sex,Age);
		System.out.print("������ѧ��ѡ�޿γ�������");
		Coursenum=input.nextInt();
		Course[] Select=new Course[Coursenum];
		for(int i=0;i<Coursenum;i++) {
			System.out.printf("������ѧ��ѡ�޵�%d�ſγ����ƣ�",i+1);
			Coursename=input.next();
			Select[i]=new Course();
			Select[i].setName(Coursename);
		}
		stu.setSelect(Select);
		System.out.println("��ӡѧ����Ϣ��");
		stu.printInfo();
	}
}
