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
		return "ѧ�ţ�"+num+"\t��ţ�"+clas+"\t������"+name+"\t�Ա�"+sex+"\t���䣺"+age;
	}
}

public class Main{
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);
		List<Student> studentlist=new ArrayList<Student>();
		System.out.println("����3��ѧ���������������ѧ������Ϣ��");
		for(int i=1;i<=3;i++)
		{
			System.out.printf("�������%dλѧ����ѧ�ţ�",i);
			String a=input.next();
			System.out.printf("�������%dλѧ���İ�ţ�",i);
			String b=input.next();
			System.out.printf("�������%dλѧ����������",i);
			String c=input.next();
			System.out.printf("�������%dλѧ�����Ա�",i);
			String d=input.next();
			System.out.printf("�������%dλѧ�������䣺",i);
			int e=input.nextInt();
			studentlist.add(new Student(a,b,c,d,e));
		}
		System.out.println();
		
		System.out.println("��ӡ����ѧ������Ϣ��");
		System.out.println("����ѧ��������"+studentlist.size());
		for(Student s:studentlist)
			System.out.println("ѧ�ţ�"+s.getNum()+"\t��ţ�"+s.getClas()+"\t������"+s.getName()+"\t�Ա�"+s.getSex()+"\t���䣺"+s.getAge());
		System.out.println();
		
		System.out.println("�޸ĵ�2λѧ��������Ϊ21");
		Student t=studentlist.get(1);
		studentlist.set(1,new Student(t.getNum(),t.getClas(),t.getName(),t.getSex(),21));
		System.out.println("��ӡ����ѧ������Ϣ��");
		System.out.println("����ѧ��������"+studentlist.size());
		for(Student s:studentlist)
			System.out.println("ѧ�ţ�"+s.getNum()+"\t��ţ�"+s.getClas()+"\t������"+s.getName()+"\t�Ա�"+s.getSex()+"\t���䣺"+s.getAge());
		System.out.println();
		
		System.out.println("ɾ����1λѧ������Ϣ");
		studentlist.remove(0);
		System.out.println("��ӡ����ѧ������Ϣ��");
		System.out.println("����ѧ��������"+studentlist.size());
		for(Student s:studentlist)
			System.out.println("ѧ�ţ�"+s.getNum()+"\t��ţ�"+s.getClas()+"\t������"+s.getName()+"\t�Ա�"+s.getSex()+"\t���䣺"+s.getAge());
		System.out.println();
	}
}
