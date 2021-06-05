// ListStudentsPanel.java
//Displaying the contents of the students table.
import java.awt.*;
import java.sql.*;
import java.util.*;
import javax.swing.*;
import java.util.List;
public class ListStudentsPanel extends JPanel {
   
   public ListStudentsPanel() {
      try { 
    	 String names2[] = { "学  号","姓  名","性 别","年 龄","所 在 系"};
         String sqlString=new String("select sno ,sname ,ssex ,sage ,sdept from student");
         StudentManager studentmanager=new  StudentManager();            		
         List<Student> list=studentmanager.Query(sqlString);
         StringBuffer results=new StringBuffer();
         results.append( "  " );
         for (int i=0;i<names2.length;i++)
            results.append( names2[ i ]+"\t" );
	      results.append( "\n" );
	      
	      for (int i=0;i<list.size();i++){
	    	  results.append( "  " );
	    	  results.append(list.get(i).getSno()+"\t");
	    	  results.append(list.get(i).getSname()+"\t");
	    	  results.append(list.get(i).getSsex()+"\t");
	    	  results.append(String.valueOf(list.get(i).getSage()+"\t") );
	    	  results.append(list.get(i).getSdept()+"\t");
	    	  if (i!=list.size()-1) 
	    		  results.append( "\n" );
          } 	     
         JTextArea textArea = new JTextArea( results.toString() );
         this.add( new JScrollPane( textArea ) );         
         setSize( 300, 100 );  // set window size
        
      }     
      catch ( SQLException sqlException ) {
         JOptionPane.showMessageDialog( null, sqlException.getMessage(), 
            "Database Error", JOptionPane.ERROR_MESSAGE );
      }
   } 
}  


