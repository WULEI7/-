
public class Student {
	private String num;
	private String clas;
	private String name;
	private String sex;
	private int age;
	private Course[] select;
	
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
	public Course[] getSelect() {
		return select;
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
	public void setSelect(Course[] Select) {
		select=Select;
	}
	public void printInfo() {
		System.out.println("ѧ�ţ�"+num+"\t��ţ�"+clas+"\t������"+name+"\t�Ա�"+sex+"\t���䣺"+age);
		Course[] sel=getSelect();
		System.out.printf("��ѧ��ѡ����%d�ſγ�\n",sel.length);
		for(int i=0;i<sel.length;i++) {
			System.out.printf("��%d�ſγ�Ϊ��%s\n",i+1,sel[i].getName());
		}
	}
}