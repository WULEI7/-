import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class BasicGUI extends JFrame{
	private JLabel aLabel,bLabel;
	private JTextField aField,bField,displayField;
	private JButton computeButton,exitButton;
	private class ActionEventHandler implements ActionListener{
		public void actionPerformed(ActionEvent event)
		{
			if(event.getSource()==exitButton)
				System.exit(0);
			else if(event.getSource()==computeButton)
			{
				//String a=aField.getText();
				int ai=Integer.parseInt(aField.getText());
				int bi=Integer.parseInt(bField.getText());
				String result=String.valueOf(ai+bi);
				displayField.setText("a+b="+result);
			}
		}
	}
	public BasicGUI()
	{
		Container container=getContentPane();
		container.setLayout(new FlowLayout());
		aLabel=new JLabel("A:");
		aField=new JTextField(10);
		container.add(aLabel);
		container.add(aField);
		bLabel=new JLabel("B:");
		bField=new JTextField(10);
		container.add(bLabel);
		container.add(bField);
		displayField=new JTextField(30);
		displayField.setEditable(false);
		container.add(displayField);
		computeButton=new JButton("¼ÆËãºÍ");
		container.add(computeButton);
		exitButton=new JButton("ÍË³ö");
		container.add(exitButton);
		ActionEventHandler handler=new ActionEventHandler();
		computeButton.addActionListener(handler);
		exitButton.addActionListener(handler);
		setSize(400,140);
		setVisible(true);
	}
	public static void main(String[] args)
	{
		BasicGUI window=new BasicGUI();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
