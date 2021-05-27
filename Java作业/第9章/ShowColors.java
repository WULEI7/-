import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ShowColors extends JFrame
{
	private JButton changeCOlorButton;
	private Color color[]= {Color.red,Color.yellow,Color.blue,Color.cyan};
	private Color selectedColor=Color.red;
	private String colorStrings[]= {"Red","Yellow","Blue","Cyan"};
	JCheckBox checkbox1,checkbox2;
	JComboBox comboBox;
	JButton okButton,exitButton;
	private Container container;
	public ShowColors()
	{
		super("Color—°‘Ò");
		container=getContentPane();
		container.setLayout(new GridLayout(3,1,5,5));
		JPanel jpanel1,jpanel2,jpanel3;
		jpanel1=new JPanel();
		jpanel2=new JPanel();
		comboBox=new JComboBox(colorStrings);
		comboBox.setMaximumRowCount(3);
		comboBox.addItemListener(
			new ItemListener()
			{
				public void itemStateChanged(ItemEvent event)
				{
					if(event.getStateChange()==ItemEvent.SELECTED)
						selectedColor=color[comboBox.getSelectedIndex()];
				}
			}
		);
		container.add(comboBox);
		checkbox1=new JCheckBox("background");
		jpanel1.add(checkbox1);
		checkbox2=new JCheckBox("foreground");
		jpanel1.add(checkbox2);
		container.add(jpanel1);
		okButton=new JButton("OK");
		okButton.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					if(checkbox1.isSelected())
						comboBox.setBackground(selectedColor);
					if(checkbox2.isSelected())
						comboBox.setForeground(selectedColor);
				}
			}
		);
		exitButton=new JButton("Exit");
		exitButton.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					System.exit(0);
				}
			}
		);
		jpanel2.add(okButton);
		jpanel2.add(exitButton);
		container.add(jpanel2);
		setSize(400,150);
		setVisible(true);
	}
	public static void main(String[] args)
	{
		ShowColors application=new ShowColors();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
