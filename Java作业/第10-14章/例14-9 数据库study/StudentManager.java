//Studentmanager.java
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
public class StudentManager extends DBConnection {
	private  Connection conn=null; 
	//构造方法中完成打开数据库链接
	public StudentManager() {        
       conn=getConnection();  //调用父类方法，链接数据库，返回Connection对象
    }  
    //对studeng表进行查询，并将查询结果集以List结构返回，并及时关闭数据库连接
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
   //对任一表进行插入、修改、删除操作	
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
	

