import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
//创建主界面类 
public class MainFrame extends JFrame implements ActionListener
	{	// 初始化菜单		
		JMenuBar jMenuBar1 = new JMenuBar();
		JMenu jMenuFile = new JMenu("文件");
		JMenuItem jMenuFileExit = new JMenuItem("退出");
		JMenu jMenu1 = new JMenu("学生管理");
		JMenuItem jMenuItem1 = new JMenuItem("添加学生");
		JMenuItem jMenuItem2 = new JMenuItem("删除学生");
		JMenuItem jMenuItem3	 = new JMenuItem("修改学生信息");
		JMenu jMenu2 = new JMenu("学生查询");
		JMenuItem jMenuItem4 = new JMenuItem("浏览全部学生");
		//JMenuItem jMenuItem5 = new JMenuItem("按学号查询");		
		// 构造方法，界面初始化
		public MainFrame() {
			// 创建内容面板和其布局
			JPanel contentPane = (JPanel) getContentPane();
			contentPane.setLayout( new BorderLayout() );
			// 框架的大小和其标题
			
			setSize(new Dimension(450, 450));
			setTitle("学生信息管理系统");
			// 添加菜单条
			setJMenuBar(jMenuBar1);
			// 添加菜单组件到菜单条
			jMenuBar1.add(jMenuFile);
			jMenuBar1.add(jMenu1);
			jMenuBar1.add(jMenu2);
			
			jMenuBar1.add(jMenuFileExit);
			// 添加菜单项组件到菜单组件
			jMenuFile.add(jMenuFileExit);
			jMenu1.add(jMenuItem1);
			jMenu1.add(jMenuItem2);
			jMenu1.add(jMenuItem3);
			jMenu2.add(jMenuItem4);
			//jMenu2.add(jMenuItem5);
			
			// 给菜单添加事件监听器
			jMenuFileExit.addActionListener(this);
			jMenuItem1.addActionListener(this);
			jMenuItem2.addActionListener(this);
			jMenuItem3.addActionListener(this);
			jMenuItem4.addActionListener(this);
			//jMenuItem5.addActionListener(this);
			
			// 添加标签到内容面板
			 Icon bug = new ImageIcon(getClass().getResource("book.jpg" ));
		     JLabel label = new JLabel( bug, SwingConstants.CENTER );			
			 contentPane.add(label,BorderLayout.CENTER);
			// 关闭框架窗口时的默认事件方法
			setDefaultCloseOperation(EXIT_ON_CLOSE);
		}

		// 菜单事件的处理方法
		public void actionPerformed(ActionEvent actionEvent)
			{
				// 点击“文件”菜单下的“退出”菜单项
				if (actionEvent.getSource() == jMenuFileExit)
					{
						System.exit(0);
					}
				// 点击“学生管理”菜单下的“添加学生”菜单项
				if (actionEvent.getSource() == jMenuItem1)
					{  // 创建添加学生面板对象					    
						AddStudentPanel add = new AddStudentPanel();
						// 移除主界面上原有的内容
						this.remove(this.getContentPane());
						this.setContentPane(add);
						// 令界面可见
						this.setVisible(true);
					}
				// 删除学生
				if (actionEvent.getSource() == jMenuItem2){						
						DeleteStudentPanel delete = new DeleteStudentPanel();						
						this.remove(this.getContentPane());
						this.setContentPane(delete);						
						this.setVisible(true);
				}
				// 修改学生
				if (actionEvent.getSource() == jMenuItem3	)	{ 
					    UpdateStudentPanel mod = new UpdateStudentPanel();						
						this.remove(this.getContentPane());
						this.setContentPane(mod);						
						this.setVisible(true);
				}
				// 浏览
				if (actionEvent.getSource() == jMenuItem4)	{
					    ListStudentsPanel list = new ListStudentsPanel();						
						this.remove(this.getContentPane());
						this.setContentPane(list);						
						this.setVisible(true);
				}
			}
	}