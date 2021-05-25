import java.awt.Graphics2D;
import java.awt.Graphics;
import java.awt.Color;
import java.awt.geom.GeneralPath;
import javax.swing.*;

public class SinCos extends JFrame{
	public SinCos()
	{
		super("Drawing 2D Shapes");
		setSize(200,200);
		setVisible(true);
	}
	public void paint(Graphics g)
	{
		super.paint(g);
		Graphics2D g2d=(Graphics2D)(g);
		GeneralPath gp1=new GeneralPath();
		GeneralPath gp2=new GeneralPath();
		GeneralPath gp3=new GeneralPath();
		GeneralPath gp4=new GeneralPath();
		double x0=200,y0=200;//设置坐标原点
		gp1.moveTo(x0, y0);//sin曲线
		gp2.moveTo(x0, y0);//cos曲线
		gp3.moveTo(x0, y0);//x轴
		gp4.moveTo(200,100);//y轴
		for(int i=0;i<360;i++)//作图区间为0-360°
		{
			double x=i+200;
			double y1=(float)(-50*Math.sin((x-200)*Math.PI/180))+200;
			double y2=(float)(-50*Math.cos((x-200)*Math.PI/180))+200;
			gp1.lineTo(x, y1);
			gp2.lineTo(x, y2);
		}
		gp3.lineTo(600,200);
		gp4.lineTo(200,300);
		g2d.draw(gp1);
		g2d.draw(gp2);
		g2d.draw(gp3);
		g2d.draw(gp4);
	}
	public static void main(String[] args) {
		SinCos application=new SinCos();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
