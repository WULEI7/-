import student.Student;

public class StudentTest {
	public static void main(String[] args) {
		Student s1=new Student("0101","1901","Tom","��",21);
		System.out.println("����s1�󣬰༶����Ϊ��"+Student.getCount());
		Student s2=new Student("0102","1901","Jerry","Ů",20);
		System.out.println("����s2�󣬰༶����Ϊ��"+Student.getCount());
		s1.setName("WuLei");
		s1.setAge(22);
		System.out.println(s1.toString());
		System.out.println(s2.toString());
		if(s1.getAge()>s2.getAge())
			System.out.println("����ϴ��ѧ��Ϊ��"+s1.getName());
		else
			System.out.println("����ϴ��ѧ��Ϊ��"+s2.getName());
	}
}