//DBConnection.java
import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import javax.swing.JOptionPane;
public class DBConnection{
	static  Connection conn = null;	 
	private static String username ="WULEI7";
	private static String password="sjjsswweiyvfei7" ;
	private static String driverClassName="com.mysql.jdbc.Driver";  	
	private static String url="jdbc:mysql://localhost:3306/study";
	public  Connection getConnection()  {
  	try {  
  			
			Class.forName(driverClassName); //ªÚ’ﬂClass.forName(driverClassName)...newInstance();
			conn = DriverManager.getConnection(url,username,password);			
	   }
      catch(Exception e){			
		e.printStackTrace();
	  } 
      return conn;
	}
	public void closeConnection() throws SQLException {
		if (conn!= null) {
			try {
				conn.close();
			} catch (SQLException e) {
				e.printStackTrace();				
			}
		}
	}
}
	

