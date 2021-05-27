import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ShowColors2 extends JFrame
{
	private JButton changeColorButton;
	private Color color=Color.LIGHT_GRAY;
	private Container container;
	public ShowColors2()
	{
		super("使用JColorChooser设置窗口背景色");
		container=getContentPane();
		container.setLayout(new FlowLayout());
		changeColorButton=new JButton("Change COlor",new ImageIcon("bug.gif"));
		changeColorButton.addActionListener(
			new ActionListener()
			{
				public void actionPerformed(ActionEvent event)
				{
					color=JColorChooser.showDialog(ShowColors2.this, "Choose a color", color);
					if(color==null)
						color=Color.LIGHT_GRAY;
					container.setBackground(color);
				}
			}
		);
		container.add(changeColorButton);
		setSize(400,130);
		setVisible(true);
	}
	public static void main(String[] args)
	{
		ShowColors2 application=new ShowColors2();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
