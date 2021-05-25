import java.awt.*;
import javax.swing.*;

public class Rectangle extends JFrame{
	public Rectangle()
	{
		super("Drawing 2D Shapes");
		setSize(200,200);
		setVisible(true);
	}
	public void paint(Graphics g)
	{
		super.paint(g);
		Graphics2D g2d=(Graphics2D)g;
		g2d.setPaint(new GradientPaint(5,40,Color.RED,15,50,Color.YELLOW,true));
		g2d.fillRect(20, 40, 90, 55);
		
	}
	public static void main(String[] args) {
		Rectangle application=new Rectangle();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
