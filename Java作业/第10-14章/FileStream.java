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
			if(s.equalsIgnoreCase("exit"))//输入exit结束
				break;
			stdout1.write(s+"\n");
		}//将键盘输入按行写入到文件file1.txt中
		stdin1.close();
		stdout1.close();
		
		InputStream stdin2=new FileInputStream("file1.txt");//从文件file1.txt输入
		Scanner input=new Scanner(stdin2);
		String s;
		int count=0;
		while(input.hasNext())
		{
			s=input.next();
			if(s.equalsIgnoreCase("we"))//统计单词we的个数
				count++;
			System.out.println(s);
		}
		BufferedWriter stdout2=new BufferedWriter(new FileWriter("file2.txt"));
		stdout2.write("单词we的个数为"+count);//将统计结果写入文件file2.txt中
		stdin2.close();
		stdout2.close();
	}
}