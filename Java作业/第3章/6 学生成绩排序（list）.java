import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class Student{
	int num;
	String name;
	int totscore,score1,score2,score3;
	Student(int Num,String Name,int Totscore,int Score1,int Score2,int Score3)
	{
		num=Num;
		name=Name;
		totscore=Totscore;
		score1=Score1;
		score2=Score2;
		score3=Score3;
	}
}

public class Main{
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		List<Student> list=new ArrayList<>();
		System.out.print("请依次输入5个同学的姓名和3门课的成绩!\n");
		for(int i=1;i<=5;i++) {
			int no=i,tot,a,b,c;
			String s;
			System.out.printf("请依次输入第%d个同学的姓名!",i);
			s=input.next();
			System.out.printf("请依次输入第%d个同学的第1门课的成绩!",i);
			a=input.nextInt();
			System.out.printf("请依次输入第%d个同学的第2门课的成绩!",i);
			b=input.nextInt();
			System.out.printf("请依次输入第%d个同学的第3门课的成绩!",i);
			c=input.nextInt();
			tot=a+b+c;
			Student student=new Student(no,s,tot,a,b,c);
			list.add(student);
		}
		list.sort((o1,o2)->o2.totscore-o1.totscore);
		System.out.print("  序号 总分  姓名  1门  2门  3门\n");
		for(Student t:list)
			System.out.printf("    %d  %d   %s   %d   %d   %d\n",t.num,t.totscore,t.name,t.score1,t.score2,t.score3);
	}
}
