import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class MyStringTokenizer {
	String[] words;
	String s;
	int i=0;
	public MyStringTokenizer(String s) {
		this.s=new String(s);
		this.words=s.split("\\n|\\t|\\r| ");
	}
	public int counts() {
		return words.length;
	}
	public boolean hasMoreWords() {
		if(i<words.length)
			return true;
		else
			return false;
	}
	public String nextWord() {
		String cut=words[i];
		i++;
		return cut;
	}
}

public class StringTest extends JFrame {
	private JLabel promptLabel;
	private JTextField inputField;
	private JTextArea outputArea;
	public StringTest() {
		super("²âÊÔMyStringTokenizerÀà");
		Container container=getContentPane();
		container.setLayout(new FlowLayout());
		inputField=new JTextField(20);
		inputField.addActionListener(
			new ActionListener() {
				public void actionPerformed(ActionEvent event) {
					MyStringTokenizer Sentences=new MyStringTokenizer(event.getActionCommand());
					outputArea.setText("Number of words:"+Sentences.counts()+"\nThe Tokenizing words:\n");
					while(Sentences.hasMoreWords())
						outputArea.append(Sentences.nextWord()+"\n");
				}
			}
		);
		container.add(inputField);
		outputArea=new JTextArea(10,20);
		outputArea.setEditable(false);
		container.add(new JScrollPane(outputArea));
		setSize(275,240);
		setVisible(true);
	}
	public static void main(String[] args) {
		StringTest application=new StringTest();
		application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
