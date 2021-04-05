public interface PersonPay{
	public double pay();
}//接口

abstract class Person implements PersonPay{
	protected String name;
	public Person(String name) {
		this.name=name;
	}
	abstract public String toString();
}

class Teacher extends Person{
	private double price;//授课单价
	private double baseWage;//基本工资
	private int teachingHours;//授课时数
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
		return "姓名："+this.name+"\t职务：教师\t工资支出："+this.pay();
	}
}//教师类

class CollegeStudent extends Person{
	private double scholarship;//奖学金
	public CollegeStudent(String name,double scholarship) {
		super(name);
		this.scholarship=scholarship;
	}
	public double pay() {
		return scholarship;
	}
	public String toString() {
		return "姓名："+this.name+"\t职务：大学生\t工资支出："+this.pay();
	}
}//大学生类

class AdministrativeStaff extends Person{
	private double baseWage;//基础工资
	private String grade;//考核等级
	public AdministrativeStaff(String name,double baseWage,String grage) {
		super(name);
		this.baseWage=baseWage;
		this.grade=grage;
	}
	public double pay() {
		if(grade=="优秀")
			return baseWage+5000;
		else if(grade=="良好")
			return baseWage+3000;
		else if(grade=="合格")
			return baseWage+1000;
		else
			return baseWage;
	}
	public String toString() {
		return "姓名："+this.name+"\t职务：行政员工\t工资支出："+this.pay();
	}
}//行政员工

 class Main{
	public static void main(String[] args) {
		PersonPay[] per=new Person[5];
		per[0]=new Teacher("张三",10000,10,50);
		per[1]=new CollegeStudent("李四",3000);
		per[2]=new AdministrativeStaff("王一",10000,"优秀");
		per[3]=new AdministrativeStaff("王二",10000,"良好");
		per[4]=new AdministrativeStaff("王三",10000,"合格");
		for(int i=0;i<per.length;i++) {
			System.out.println(per[i]);
		}
	}
}
