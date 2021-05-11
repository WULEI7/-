import java.awt.Graphics2D;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.geom.GeneralPath;
import javax.swing.*;

public class Star extends JFrame{
	public Star()
	{
		super("Drawing 2D Shapes");
		getContentPane().setBackground(Color.white);
		setSize(200,200);
		setVisible(true);
	}
	public void paint(Graphics g)
	{
		super.paint(g);
		int xPoints[]= {55,67,109,73,83,55,27,37,1,43};
		int yPoints[]= {60,96,96,114,156,122,156,114,96,96};
		Graphics2D g2d=(Graphics2D)g;
		GeneralPath star=new GeneralPath();
		star.moveTo(xPoints[0], yPoints[0]);
		for(int i=1;i<xPoints.length;i++)
			star.lineTo(xPoints[i], yPoints[i]);
		star.closePath();
		g2d.setColor(Color.red);
		g2d.fill(star);
	}
	public static void main(String[] args) {
		Star application=new Star();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
