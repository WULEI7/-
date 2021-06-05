//Main.java
import java.awt.*;
//创建系统主类
class Main	{
	public static void main(String[] args)
	{   // 创建主界面，并使主窗口显示在屏幕居中
		MainFrame frame = new MainFrame();
		// 获取屏幕尺寸
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize(); 
		Dimension frameSize = frame.getSize();// 获取主界面的窗体尺寸
		// 令主界面窗体居中
		if (frameSize.height > screenSize.height)
			frameSize.height = screenSize.height;
		if (frameSize.width > screenSize.width)
			frameSize.width = screenSize.width;
		frame.setLocation((screenSize.width - frameSize.width) / 2, (screenSize.height - frameSize.height) / 2);
		//frame.setResizable(false);
		frame.setVisible(true);// 令主界面显示
	}
}