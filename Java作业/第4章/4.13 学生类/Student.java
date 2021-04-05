package student;

public class Student {
	private String num;
	private String clas;
	private String name;
	private String sex;
	private int age;
	private static int count=0;
	
	public Student(String Num,String Clas,String Name,String Sex,int Age)
	{
		num=Num;
		clas=Clas;
		name=Name;
		sex=Sex;
		age=Age;
		count++;
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
	public static int getCount() {
		return count;
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