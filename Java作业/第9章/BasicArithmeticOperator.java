import javax.swing.*;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.*;

public class ArithmeticOperator extends JApplet implements ActionListener
{
	JLabel prompt;
	JTextField input1,input2;
	JTextArea output;
	JButton btn;
	public void init()
	{
		Container container=getContentPane();
		container.setLayout(new FlowLayout());
		prompt=new JLabel("请输入两个整型数据：");
		input1=new JTextField(5);
		input2=new JTextField(5);
		btn=new JButton("计算");
		output=new JTextArea(5,20);
		output.setEditable(false);
		container.add(prompt);
		container.add(input1);
		container.add(input2);
		container.add(btn);
		container.add(output);
		btn.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e)
	{
		int a,b;
		a=Integer.parseInt(input1.getText());
		b=Integer.parseInt(input2.getText());
		String s1=a+"+"+b+"="+(a+b)+"\n";
		s1+=a+"-"+b+"="+(a-b)+"\n";
		s1+=a+"*"+b+"="+(a*b)+"\n";
		s1+=a+"/"+b+"="+(a/b)+"\n";
		s1+=a+"%"+b+"="+(a%b)+"\n";
		output.setText(s1);
	}
}
