import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
//������������ 
public class MainFrame extends JFrame implements ActionListener
	{	// ��ʼ���˵�		
		JMenuBar jMenuBar1 = new JMenuBar();
		JMenu jMenuFile = new JMenu("�ļ�");
		JMenuItem jMenuFileExit = new JMenuItem("�˳�");
		JMenu jMenu1 = new JMenu("ѧ������");
		JMenuItem jMenuItem1 = new JMenuItem("���ѧ��");
		JMenuItem jMenuItem2 = new JMenuItem("ɾ��ѧ��");
		JMenuItem jMenuItem3	 = new JMenuItem("�޸�ѧ����Ϣ");
		JMenu jMenu2 = new JMenu("ѧ����ѯ");
		JMenuItem jMenuItem4 = new JMenuItem("���ȫ��ѧ��");
		//JMenuItem jMenuItem5 = new JMenuItem("��ѧ�Ų�ѯ");		
		// ���췽���������ʼ��
		public MainFrame() {
			// �������������䲼��
			JPanel contentPane = (JPanel) getContentPane();
			contentPane.setLayout( new BorderLayout() );
			// ��ܵĴ�С�������
			
			setSize(new Dimension(450, 450));
			setTitle("ѧ����Ϣ����ϵͳ");
			// ��Ӳ˵���
			setJMenuBar(jMenuBar1);
			// ��Ӳ˵�������˵���
			jMenuBar1.add(jMenuFile);
			jMenuBar1.add(jMenu1);
			jMenuBar1.add(jMenu2);
			
			jMenuBar1.add(jMenuFileExit);
			// ��Ӳ˵���������˵����
			jMenuFile.add(jMenuFileExit);
			jMenu1.add(jMenuItem1);
			jMenu1.add(jMenuItem2);
			jMenu1.add(jMenuItem3);
			jMenu2.add(jMenuItem4);
			//jMenu2.add(jMenuItem5);
			
			// ���˵�����¼�������
			jMenuFileExit.addActionListener(this);
			jMenuItem1.addActionListener(this);
			jMenuItem2.addActionListener(this);
			jMenuItem3.addActionListener(this);
			jMenuItem4.addActionListener(this);
			//jMenuItem5.addActionListener(this);
			
			// ��ӱ�ǩ���������
			 Icon bug = new ImageIcon(getClass().getResource("book.jpg" ));
		     JLabel label = new JLabel( bug, SwingConstants.CENTER );			
			 contentPane.add(label,BorderLayout.CENTER);
			// �رտ�ܴ���ʱ��Ĭ���¼�����
			setDefaultCloseOperation(EXIT_ON_CLOSE);
		}

		// �˵��¼��Ĵ�����
		public void actionPerformed(ActionEvent actionEvent)
			{
				// ������ļ����˵��µġ��˳����˵���
				if (actionEvent.getSource() == jMenuFileExit)
					{
						System.exit(0);
					}
				// �����ѧ�������˵��µġ����ѧ�����˵���
				if (actionEvent.getSource() == jMenuItem1)
					{  // �������ѧ��������					    
						AddStudentPanel add = new AddStudentPanel();
						// �Ƴ���������ԭ�е�����
						this.remove(this.getContentPane());
						this.setContentPane(add);
						// �����ɼ�
						this.setVisible(true);
					}
				// ɾ��ѧ��
				if (actionEvent.getSource() == jMenuItem2){						
						DeleteStudentPanel delete = new DeleteStudentPanel();						
						this.remove(this.getContentPane());
						this.setContentPane(delete);						
						this.setVisible(true);
				}
				// �޸�ѧ��
				if (actionEvent.getSource() == jMenuItem3	)	{ 
					    UpdateStudentPanel mod = new UpdateStudentPanel();						
						this.remove(this.getContentPane());
						this.setContentPane(mod);						
						this.setVisible(true);
				}
				// ���
				if (actionEvent.getSource() == jMenuItem4)	{
					    ListStudentsPanel list = new ListStudentsPanel();						
						this.remove(this.getContentPane());
						this.setContentPane(list);						
						this.setVisible(true);
				}
			}
	}