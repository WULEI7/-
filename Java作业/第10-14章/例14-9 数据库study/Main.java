//Main.java
import java.awt.*;
//����ϵͳ����
class Main	{
	public static void main(String[] args)
	{   // ���������棬��ʹ��������ʾ����Ļ����
		MainFrame frame = new MainFrame();
		// ��ȡ��Ļ�ߴ�
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize(); 
		Dimension frameSize = frame.getSize();// ��ȡ������Ĵ���ߴ�
		// �������洰�����
		if (frameSize.height > screenSize.height)
			frameSize.height = screenSize.height;
		if (frameSize.width > screenSize.width)
			frameSize.width = screenSize.width;
		frame.setLocation((screenSize.width - frameSize.width) / 2, (screenSize.height - frameSize.height) / 2);
		//frame.setResizable(false);
		frame.setVisible(true);// ����������ʾ
	}
}