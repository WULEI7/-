import java.io.*;
import java.util.Scanner;

class FileStream
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader stdin1=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter stdout1=new BufferedWriter(new FileWriter("file1.txt"));
		while(true)
		{
			System.out.print("INPUT>");
			String s=stdin1.readLine();
			if(s.equalsIgnoreCase("exit"))//����exit����
				break;
			stdout1.write(s+"\n");
		}//���������밴��д�뵽�ļ�file1.txt��
		stdin1.close();
		stdout1.close();
		
		InputStream stdin2=new FileInputStream("file1.txt");//���ļ�file1.txt����
		Scanner input=new Scanner(stdin2);
		String s;
		int count=0;
		while(input.hasNext())
		{
			s=input.next();
			if(s.equalsIgnoreCase("we"))//ͳ�Ƶ���we�ĸ���
				count++;
			System.out.println(s);
		}
		BufferedWriter stdout2=new BufferedWriter(new FileWriter("file2.txt"));
		stdout2.write("����we�ĸ���Ϊ"+count);//��ͳ�ƽ��д���ļ�file2.txt��
		stdin2.close();
		stdout2.close();
	}
}