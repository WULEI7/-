import java.util.Scanner;

public class Test {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		String Num,Clas,Name,Sex,Coursename;
		int Age,Coursenum;
		System.out.print("请输入学生学号：");
		Num=input.next();
		System.out.print("请输入学生班级：");
		Clas=input.next();
		System.out.print("请输入学生姓名：");
		Name=input.next();
		System.out.print("请输入学生性别：");
		Sex=input.next();
		System.out.print("请输入学生年龄：");
		Age=input.nextInt();
		Student stu=new Student(Num,Clas,Name,Sex,Age);
		System.out.print("请输入学生选修课程门数：");
		Coursenum=input.nextInt();
		Course[] Select=new Course[Coursenum];
		for(int i=0;i<Coursenum;i++) {
			System.out.printf("请输入学生选修第%d门课程名称：",i+1);
			Coursename=input.next();
			Select[i]=new Course();
			Select[i].setName(Coursename);
		}
		stu.setSelect(Select);
		System.out.println("打印学生信息：");
		stu.printInfo();
	}
}
