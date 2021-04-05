public interface PersonPay{
	public double pay();
}//�ӿ�

abstract class Person implements PersonPay{
	protected String name;
	public Person(String name) {
		this.name=name;
	}
	abstract public String toString();
}

class Teacher extends Person{
	private double price;//�ڿε���
	private double baseWage;//��������
	private int teachingHours;//�ڿ�ʱ��
	public Teacher(String name,double baseWage,double price,int teachingHours) {
		super(name);
		this.baseWage=baseWage;
		this.price=price;
		this.teachingHours=teachingHours;
	}
	public double pay() {
		return baseWage+teachingHours*price;
	}
	public String toString() {
		return "������"+this.name+"\tְ�񣺽�ʦ\t����֧����"+this.pay();
	}
}//��ʦ��

class CollegeStudent extends Person{
	private double scholarship;//��ѧ��
	public CollegeStudent(String name,double scholarship) {
		super(name);
		this.scholarship=scholarship;
	}
	public double pay() {
		return scholarship;
	}
	public String toString() {
		return "������"+this.name+"\tְ�񣺴�ѧ��\t����֧����"+this.pay();
	}
}//��ѧ����

class AdministrativeStaff extends Person{
	private double baseWage;//��������
	private String grade;//���˵ȼ�
	public AdministrativeStaff(String name,double baseWage,String grage) {
		super(name);
		this.baseWage=baseWage;
		this.grade=grage;
	}
	public double pay() {
		if(grade=="����")
			return baseWage+5000;
		else if(grade=="����")
			return baseWage+3000;
		else if(grade=="�ϸ�")
			return baseWage+1000;
		else
			return baseWage;
	}
	public String toString() {
		return "������"+this.name+"\tְ������Ա��\t����֧����"+this.pay();
	}
}//����Ա��

 class Main{
	public static void main(String[] args) {
		PersonPay[] per=new Person[5];
		per[0]=new Teacher("����",10000,10,50);
		per[1]=new CollegeStudent("����",3000);
		per[2]=new AdministrativeStaff("��һ",10000,"����");
		per[3]=new AdministrativeStaff("����",10000,"����");
		per[4]=new AdministrativeStaff("����",10000,"�ϸ�");
		for(int i=0;i<per.length;i++) {
			System.out.println(per[i]);
		}
	}
}
