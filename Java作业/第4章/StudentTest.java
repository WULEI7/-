import student.Student;

public class StudentTest {
	public static void main(String[] args) {
		Student s1=new Student("0101","1901","Tom","男",21);
		System.out.println("构造s1后，班级人数为："+Student.getCount());
		Student s2=new Student("0102","1901","Jerry","女",20);
		System.out.println("构造s2后，班级人数为："+Student.getCount());
		s1.setName("WuLei");
		s1.setAge(22);
		System.out.println(s1.toString());
		System.out.println(s2.toString());
		if(s1.getAge()>s2.getAge())
			System.out.println("年龄较大的学生为："+s1.getName());
		else
			System.out.println("年龄较大的学生为："+s2.getName());
	}
}