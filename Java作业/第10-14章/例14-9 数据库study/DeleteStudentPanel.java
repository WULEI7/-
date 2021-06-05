//DeleteStudentPanel.java
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.*;
import java.util.List;

import javax.swing.*;
import javax.swing.border.*;

class DeleteStudentPanel extends JPanel {
   private StudentUI userInterface1,userInterface2;
   private JButton  firstButton1,secondButton1, firstButton2,secondButton2;
   String snoUpdate;
   // JDBC driver and database URL  
   String sqlString ;
      // set up GUI
   public DeleteStudentPanel()
   {
      
      
      // create instance of reusable user interface
      //set up column names
      String names1[] = { "请输入要删除的学生的学号:"};
            
      userInterface1= new StudentUI( names1 );  // four textfields
      
      //set up column names
      String names2[] = { "学  号","姓  名","性 别","年 龄","所 在 系"};
      userInterface2 = new StudentUI(names2 );
      this.setLayout(new FlowLayout());
      Box box = Box.createVerticalBox();
      box.add(userInterface1  );
      box.add(userInterface2 );      
      this.add(box);
      
      firstButton1 = userInterface1.getDoTask1Button();
      firstButton1.setText( "确认" );

      // register listener to call openFile when firstButton1 pressed
      firstButton1.addActionListener(

         // anonymous inner class to handle firstButton2 event
         new ActionListener() {

            // call DisplayRecord() when button pressed
            public void actionPerformed( ActionEvent event )
            {
               //initialize();
               DisplayRecord();
            }

         } // end anonymous inner class

      ); // end call to addActionListener

      // configure button doTask2 for userInterface1 in this program
      secondButton1 = userInterface1.getDoTask2Button();
      secondButton1.setText( "清除" );
      
      // register listener to call clearFields when button pressed
      secondButton1.addActionListener(

         // anonymous inner class to handle secondButton1 event
         new ActionListener() {

            // call clearFields when button pressed
            public void actionPerformed( ActionEvent event )
            {
               userInterface1.clearFields();
            }

         } // end anonymous inner class

      ); 
      
      
      // configure button doTask1 for userInterface2 in this program
      firstButton2 = userInterface2.getDoTask1Button();
      firstButton2.setText( "确认删除" );

      // register listener to call firstButton2 when button pressed
      firstButton2.addActionListener(

         // anonymous inner class to handle firstButton2 event
         new ActionListener() {

            // call UpdateRecord when button pressed
            public void actionPerformed( ActionEvent event )
            {
              deleteRecord();
            }

         } // end anonymous inner class

      ); // end call to addActionListener

      // configure button doTask2 for serInterface2 in this program
      secondButton2 = userInterface2.getDoTask2Button();
      secondButton2.setText( "放弃" );
      
      // register listener to call clearFields when button pressed
      secondButton2.addActionListener(

         // anonymous inner class to handle secondButton2 event
         new ActionListener() {

            // call addRecord when button pressed
            public void actionPerformed( ActionEvent event )
            {
               userInterface2.clearFields();
            }

         } // end anonymous inner class

      ); // end call to addActionListener

     
      setSize( 400, 260 );
      setVisible( true );

   } // end  constructor

  
   public void DisplayRecord()
   {
   	
   	String fieldValues1[] = userInterface1.getFieldValues();
   	
   	String fieldValues2 []=new String[5] ;
   	if ( ! fieldValues1[ StudentUI.SNO ].equals( "" ) ) {         
         snoUpdate=fieldValues1[0];       
         try {        
            String sqlString = "select * from student "+
                             " where sno='"+fieldValues1[0] + "'";
            StudentManager studentmanager=new  StudentManager();            		
            List<Student> list=studentmanager.Query(sqlString);
            if ( list.size()!=0 ) {
            	fieldValues2[0]=list.get(0).getSno();
                fieldValues2[1]=list.get(0).getSname();
                fieldValues2[2]=list.get(0).getSsex();
                fieldValues2[3]=String.valueOf(list.get(0).getSage()) ;
                fieldValues2[4]=list.get(0).getSdept();
                userInterface2.setFieldValues(fieldValues2);
            }    
            else
            {
                userInterface2.clearFields();
                JOptionPane.showMessageDialog( DeleteStudentPanel.this, 
                  "Not fund this record!", "Find Result", 
                    JOptionPane.INFORMATION_MESSAGE ); 
            }              
          }        
         // process exceptions from sql
         catch (Exception ee)
		{   System.out.println(ee);	} 
	  }  //end of if sno field value is not empty		
	  else //if sno field value is  empty
            JOptionPane.showMessageDialog( DeleteStudentPanel.this,
               "Bad sno number ", "Invalid Number Format",
               JOptionPane.ERROR_MESSAGE );
     	
   }
   // Delete record of student
   public void deleteRecord()
   {
      
      String fieldValues[] = userInterface2.getFieldValues();
      
     
      // if sno field value is not empty
      if ( ! fieldValues[ StudentUI.SNO ].equals( "" ) ) {

      
         // delete record from student
         try {
            
            String sqlString = "delete from student  "+
                               "where sno='"+snoUpdate + "'";
								
            StudentManager studentmanager=new  StudentManager();            		
            int result=studentmanager.execUpdate(sqlString);
            if (result!=0) {
                JOptionPane.showMessageDialog( this, 
                "Deleted sucess!", "Delete Result", 
                 JOptionPane.INFORMATION_MESSAGE ); 
            }
                 
         } // end try
         // process exceptions for sql
         catch (SQLException ee)
				{ System.out.println(ee);	} 
		}  //end of if sno field value is not empty
		
		else 
            JOptionPane.showMessageDialog( this,
               "Bad sno number ", "Invalid Number Format",
               JOptionPane.ERROR_MESSAGE );
        

   
   } // end method updateRecord
} // end class 

