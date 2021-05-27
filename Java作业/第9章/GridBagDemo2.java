import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GridBagDemo2 extends JFrame
{
	private GridBagLayout layout;
	private GridBagConstraints constraints;
	private Container container;
	public GridBagDemo2()
	{
		super("GridBagLayout��Ӧ��");
		container=getContentPane();
		layout=new GridBagLayout();
		container.setLayout(layout);
		constraints=new GridBagConstraints();
		String students[]= {"��ѧ��","��ѧ��","Сѧ��"};
		JComboBox comboBox=new JComboBox(students);
		JTextField textField=new JTextField("�ı���");
		String fonts[]= {"����","����"};
		JList list=new JList(fonts);
		String names[]= {"��ť0","��ť1","��ť2","��ť3","��ť4"};
		JButton buttons[]=new JButton[names.length];
		for(int count=0;count<buttons.length;count++)
			buttons[count]=new JButton(names[count]);
		constraints.weightx=1;
		constraints.weighty=1;
		constraints.fill=GridBagConstraints.BOTH;
		constraints.gridwidth=GridBagConstraints.REMAINDER;
		addComponent(textField);
		constraints.gridwidth=1;
		addComponent(buttons[0]);
		constraints.gridwidth=GridBagConstraints.RELATIVE;
		addComponent(buttons[1]);
		constraints.gridwidth=GridBagConstraints.REMAINDER;
		addComponent(buttons[2]);
		constraints.weighty=0;
		constraints.gridwidth=GridBagConstraints.REMAINDER;
		addComponent(comboBox);
		constraints.weighty=1;
		constraints.gridwidth=GridBagConstraints.REMAINDER;
		addComponent(buttons[3]);
		constraints.gridwidth=GridBagConstraints.RELATIVE;
		addComponent(buttons[4]);
		constraints.gridwidth=GridBagConstraints.REMAINDER;
		addComponent(list);
		setSize(300,200);
		setVisible(true);
	}
	private void addComponent(Component component)
	{
		layout.setConstraints(component, constraints);
		container.add(component);
	}
	public static void main(String[] args)
	{
		GridBagDemo2 application=new GridBagDemo2();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
