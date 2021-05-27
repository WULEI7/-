import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ArithmeticOperator extends JFrame
{
	private Container container;
	private FlowLayout layout;
	
	JLabel prompt,equal;//输入提示语、等号
	JTextField input1,input2,input3;//三个输入框
	JTextField output;//计算判断结果显示
	JButton btn1,btn2;//检查、退出按钮
	JComboBox comboBox;//运算符复选框
	private int operator=0;//运算符（0-3分别代表+-*/）
	
	public ArithmeticOperator()
	{
		super("计算测试");
		container=getContentPane();
		layout=new FlowLayout();
		container.setLayout(layout);
		
		String[] operators={"+","-","*","/"};
		comboBox=new JComboBox(operators);
		comboBox.setMaximumRowCount(4);
		comboBox.addItemListener(
			new ItemListener()
			{
				public void itemStateChanged(ItemEvent event)
				{
					if(event.getStateChange()==ItemEvent.SELECTED)
						operator=comboBox.getSelectedIndex();//选中运算符
				}
			}
		);
		
		prompt=new JLabel("请输入两个整数及运算符，并输入运算结果：");
		equal=new JLabel("  =  ");
		input1=new JTextField(5);
		input2=new JTextField(5);
		input3=new JTextField(5);
		btn1=new JButton("检查");
		btn2=new JButton("退出");
		output=new JTextField(20);
		output.setEditable(false);
		
		btn1.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					int a,b,c,d=0;//注意d要初始化值，否则会报错
					a=Integer.parseInt(input1.getText());
					b=Integer.parseInt(input2.getText());
					c=Integer.parseInt(input3.getText());//分别从三个输入框得到数字
					if(operator==0)
						d=a+b;
					else if(operator==1)
						d=a-b;
					else if(operator==2)
						d=a*b;
					else if(operator==3)
						d=a/b;//按照当前选中的运算符，得到实际的计算结果
					String s1="对了！你真棒！";
					String s2="不对呀，你再仔细计算一下";
					if(c==d)
						output.setText(s1);
					else if(c!=d)
						output.setText(s2);//显示计算判断结果
				}
			}
		);//检查按钮
		
		btn2.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					System.exit(0);
				}
			}
		);//退出按钮
		
		container.add(prompt);
		container.add(input1);
		container.add(comboBox);
		container.add(input2);
		container.add(equal);
		container.add(input3);
		container.add(btn1);
		container.add(btn2);
		container.add(output);//添加组件
		
		setSize(320,160);//设置窗口大小
		setVisible(true);
	}
	public static void main(String[] args)
	{
		ArithmeticOperator application=new ArithmeticOperator();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
