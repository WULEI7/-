import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ArithmeticOperator extends JFrame
{
	private Container container;
	private FlowLayout layout;
	
	JLabel prompt,equal;//������ʾ��Ⱥ�
	JTextField input1,input2,input3;//���������
	JTextField output;//�����жϽ����ʾ
	JButton btn1,btn2;//��顢�˳���ť
	JComboBox comboBox;//�������ѡ��
	private int operator=0;//�������0-3�ֱ����+-*/��
	
	public ArithmeticOperator()
	{
		super("�������");
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
						operator=comboBox.getSelectedIndex();//ѡ�������
				}
			}
		);
		
		prompt=new JLabel("�������������������������������������");
		equal=new JLabel("  =  ");
		input1=new JTextField(5);
		input2=new JTextField(5);
		input3=new JTextField(5);
		btn1=new JButton("���");
		btn2=new JButton("�˳�");
		output=new JTextField(20);
		output.setEditable(false);
		
		btn1.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					int a,b,c,d=0;//ע��dҪ��ʼ��ֵ������ᱨ��
					a=Integer.parseInt(input1.getText());
					b=Integer.parseInt(input2.getText());
					c=Integer.parseInt(input3.getText());//�ֱ�����������õ�����
					if(operator==0)
						d=a+b;
					else if(operator==1)
						d=a-b;
					else if(operator==2)
						d=a*b;
					else if(operator==3)
						d=a/b;//���յ�ǰѡ�е���������õ�ʵ�ʵļ�����
					String s1="���ˣ��������";
					String s2="����ѽ��������ϸ����һ��";
					if(c==d)
						output.setText(s1);
					else if(c!=d)
						output.setText(s2);//��ʾ�����жϽ��
				}
			}
		);//��鰴ť
		
		btn2.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					System.exit(0);
				}
			}
		);//�˳���ť
		
		container.add(prompt);
		container.add(input1);
		container.add(comboBox);
		container.add(input2);
		container.add(equal);
		container.add(input3);
		container.add(btn1);
		container.add(btn2);
		container.add(output);//������
		
		setSize(320,160);//���ô��ڴ�С
		setVisible(true);
	}
	public static void main(String[] args)
	{
		ArithmeticOperator application=new ArithmeticOperator();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
