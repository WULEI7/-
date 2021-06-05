//AddStudentFrame.java
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.*;
import javax.swing.*;
public class AddStudentPanel extends JPanel {   
	private JButton clearButton, writeButton;   
	private StudentUI userInterface;
	String names1[] = { "学  号","姓  名","性 别","年 龄","所 在 系" };   
   // set up GUI
   public AddStudentPanel(){ 	  
	  setLayout( new BorderLayout() );
      userInterface = new StudentUI( names1 ); 
      this.add( userInterface, BorderLayout.NORTH );
      
      // configure button doTask1 for use in this program
      writeButton =userInterface.getDoTask1Button();
      writeButton.setText( "保存" );

      // register listener to call addRecord when button pressed
      writeButton.addActionListener(
         // anonymous inner class to handle writeButton event
         new ActionListener() {            
            public void actionPerformed( ActionEvent event )
            {   String fieldValues[] = userInterface.getFieldValues();                
                if ( ! fieldValues[ StudentUI.SNO ].equals( "" ) ) {                
                // output values to student
                try {
                   int numberAge = Integer.parseInt(
                   fieldValues[ StudentUI.SAGE ] );
                   //define string for sql insert  statement 
                   String sqlString = "INSERT INTO student " +
       								 "VALUES ('" + 
       								fieldValues[0] + "', '" +
       								fieldValues[1]  +"', '"+
       								fieldValues[2]+ "', "
       								+numberAge+",'"+fieldValues[4] + "')";
                   StudentManager studentmanager=new  StudentManager();            		
                   int result=studentmanager.execUpdate(sqlString);
                   if (result!=0) {
                       userInterface.clearFields();
                      JOptionPane.showMessageDialog( AddStudentPanel.this, 
                       "Inserted sucess!", "Insert Result", 
                        JOptionPane.INFORMATION_MESSAGE ); 
                   }
                        
                } // end try
                // process invalid age number 
                catch ( NumberFormatException formatException ) {
                   JOptionPane.showMessageDialog( AddStudentPanel.this,
                      "Bad age number ", "Invalid Number Format",
                      JOptionPane.ERROR_MESSAGE );
                }
                // process exceptions from file output
                catch (SQLException ee)
       	       { System.out.println(ee);	} 
       	}  //end of if sno field value is not empty
       		
       	else  //if sno field value is  empty
             JOptionPane.showMessageDialog( AddStudentPanel.this,
             "Bad sno number ", "student number is  empty!", JOptionPane.ERROR_MESSAGE );
            }
         }
      ); // end call to addActionListener

      // configure button doTask2 for use in this program
      clearButton = userInterface.getDoTask2Button();
      clearButton.setText( "清除" );      
      // register listener to call userInterface clearFields() when button pressed
      clearButton.addActionListener(
         // anonymous inner class to handle clearButton event
         new ActionListener() {
            // call userInterface clearFields() when button pressed
            public void actionPerformed( ActionEvent event )
            {
            	userInterface.clearFields();
            }
         } 
      ); // end call to addActionListener  
   } 
} 

