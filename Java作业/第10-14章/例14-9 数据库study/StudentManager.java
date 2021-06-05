//Studentmanager.java
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
public class StudentManager extends DBConnection {
	private  Connection conn=null; 
	//���췽������ɴ����ݿ�����
	public StudentManager() {        
       conn=getConnection();  //���ø��෽�����������ݿ⣬����Connection����
    }  
    //��studeng����в�ѯ��������ѯ�������List�ṹ���أ�����ʱ�ر����ݿ�����
	public List<Student> Query(String sqlString) throws SQLException
	 {  List<Student> list = new ArrayList<Student>(); 	
	    Statement statement=null; 
	    ResultSet rs=null;
		 try {	
			 statement = conn.createStatement();  
		      rs= statement.executeQuery(sqlString);
		     while(rs.next()) {		    	
			    	Student m=new Student();
			    	m.setSno(rs.getString("sno"));
					m.setSname(rs.getString("sname"));
					m.setSsex(rs.getString("ssex"));
					m.setSage(rs.getInt("sage"));
					m.setSdept(rs.getString("Sdept"));
					list.add(m);
		     }
		 }
		 catch (SQLException e)
		  { System.out.println(e); } 
	      finally {
			if (statement !=null)
				statement .close();
			if (rs!=null)
				rs.close();
			closeConnection();
		}
	   return list;	          
	}
   //����һ����в��롢�޸ġ�ɾ������	
	public int execUpdate(String sql)throws SQLException {
		int result=0; 
		Statement statement=null; 
		try {	            
	            statement = conn.createStatement();  
	            result = statement.executeUpdate(sql);		           
	                 
	    } 
        catch (SQLException e)
	    { System.out.println(e); } 
        finally {
		if (statement!=null)
			statement.close();			
		closeConnection();
	  }
      return result;	   
    }
}
	

