import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

class Student
{
	private String num;
	private String clas;
	private String name;
	private String sex;
	private int age;
	
	public Student(String Num,String Clas,String Name,String Sex,int Age)
	{
		num=Num;
		clas=Clas;
		name=Name;
		sex=Sex;
		age=Age;
	}
	public String getNum() {
		return num;
	}
	public String getClas() {
		return clas;
	}
	public String getName() {
		return name;
	}
	public String getSex() {
		return sex;
	}
	public int getAge() {
		return age;
	}
	public void setNum(String Num) {
		num=Num;
	}
	public void setClas(String Clas) {
		clas=Clas;
	}
	public void setName(String Name) {
		name=Name;
	}
	public void setSex(String Sex) {
		sex=Sex;
	}
	public void setAge(int Age) {
		age=Age;
	}
	public String toString() {
		return "学号："+num+"\t班号："+clas+"\t姓名："+name+"\t性别："+sex+"\t年龄："+age;
	}
}

public class Main{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		List<Student> studentlist=new ArrayList<Student>();
		System.out.println("插入3名学生，请依次输入各学生的信息：");
		for(int i=1;i<=3;i++)
		{
			System.out.printf("请输入第%d位学生的学号：",i);
			String a=input.next();
			System.out.printf("请输入第%d位学生的班号：",i);
			String b=input.next();
			System.out.printf("请输入第%d位学生的姓名：",i);
			String c=input.next();
			System.out.printf("请输入第%d位学生的性别：",i);
			String d=input.next();
			System.out.printf("请输入第%d位学生的年龄：",i);
			int e=input.nextInt();
			studentlist.add(new Student(a,b,c,d,e));
		}
		System.out.println();
		
		System.out.println("打印所有学生的信息：");
		System.out.println("现有学生人数："+studentlist.size());
		for(Student s:studentlist)
			System.out.println("学号："+s.getNum()+"\t班号："+s.getClas()+"\t姓名："+s.getName()+"\t性别："+s.getSex()+"\t年龄："+s.getAge());
		System.out.println();
		
		System.out.println("修改第2位学生的年龄为21");
		Student t=studentlist.get(1);
		studentlist.set(1,new Student(t.getNum(),t.getClas(),t.getName(),t.getSex(),21));
		System.out.println("打印所有学生的信息：");
		System.out.println("现有学生人数："+studentlist.size());
		for(Student s:studentlist)
			System.out.println("学号："+s.getNum()+"\t班号："+s.getClas()+"\t姓名："+s.getName()+"\t性别："+s.getSex()+"\t年龄："+s.getAge());
		System.out.println();
		
		System.out.println("删除第1位学生的信息");
		studentlist.remove(0);
		System.out.println("打印所有学生的信息：");
		System.out.println("现有学生人数："+studentlist.size());
		for(Student s:studentlist)
			System.out.println("学号："+s.getNum()+"\t班号："+s.getClas()+"\t姓名："+s.getName()+"\t性别："+s.getSex()+"\t年龄："+s.getAge());
		System.out.println();
	}
}
