package com.my.service;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import com.my.DBC.DBConnector;
import com.my.entity.my_CATEGORY;
import com.my.entity.my_PRODUCT;
import com.my.entity.my_USER;

public class my_PRODUCTDBC {
	 public static int insert(my_PRODUCT p) {
		  
   	  String sql = "insert into my_Product values(null, ?, ?, ?, ?, ?, ?, ?)"; 
   	  Object[] params= {
   			  p.getPRODUCT_NAME(),
   			  p.getPRODUCT_DESCRIPTION(),
   			  p.getPRODUCT_PRICE(),
   			  p.getPRODUCT_STOCK(),
   			  p.getPRODUCT_FID(),
   			  p.getPRODUCT_CID(),
   			  p.getPRODUCT_FILENAME()
  	  
   	  };
		return DBConnector.exectuIUD(sql, params);
     }
	
	 public static int update(my_PRODUCT product ) {
			String sql = "update my_PRODUCT set PRODUCT_NAME=?, PRODUCT_DESCRIPTION=?,PRODUCT_PRICE=?,PRODUCT_STOCK=?  where PRODUCT_ID = ?";
			
			Object[] params = {
						product.getPRODUCT_NAME(),
						product.getPRODUCT_DESCRIPTION(),
						product.getPRODUCT_PRICE(),
						product.getPRODUCT_STOCK()
						};
			
			return DBConnector.exectuIUD(sql, params);
	}
	
	 public static ArrayList<my_PRODUCT> selectAll() {
	   	  ArrayList<my_PRODUCT> list=new ArrayList<my_PRODUCT>();
	   	  ResultSet rs = null;//声明结果集
	   	  //获取连接对象
	   	  Connection conn = DBConnector.getconn();
	   	   PreparedStatement ps = null;
	   	   
	   	   try { 
	   	String sql = "select * from my_PRODUCT ";
	   	ps = conn.prepareStatement(sql);
		
		rs=ps.executeQuery();
	  
				while(rs.next()) {
					my_PRODUCT p = new my_PRODUCT(
							rs.getInt("PRODUCT_ID"),
							rs.getString("PRODUCT_NAME"),
							rs.getString("PRODUCT_DESCRIPTION"),
							rs.getInt("PRODUCT_PRICE"),
							rs.getInt("PRODUCT_STOCK"),
							rs.getInt("PRODUCT_FID"),
							rs.getInt("PRODUCT_CID"),
							rs.getString("PRODUCT_FILENAME")
							
							
							
							);
					list.add(p);
					}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally {
				DBConnector.closeall(rs, ps, conn);
			}
	   	  return list;
	     }
	 
	 public static ArrayList<my_PRODUCT> selectAllByFid(int fid) {
	   	  ArrayList<my_PRODUCT> list=new ArrayList<my_PRODUCT>();
	   	  ResultSet rs = null;//声明结果集
	   	  //获取连接对象
	   	  Connection conn = DBConnector.getconn();
	   	   PreparedStatement ps = null;
	   	   
	   	   try { 
	   	String sql = "select * from my_PRODUCT where PRODUCT_FID=?";
	   	ps = conn.prepareStatement(sql);
		
	   	ps.setInt(1, fid);
	   	
	   	
		rs=ps.executeQuery();
	  
				while(rs.next()) {
					my_PRODUCT p = new my_PRODUCT(
							rs.getInt("PRODUCT_ID"),
							rs.getString("PRODUCT_NAME"),
							rs.getString("PRODUCT_DESCRIPTION"),
							rs.getInt("PRODUCT_PRICE"),
							rs.getInt("PRODUCT_STOCK"),
							rs.getInt("PRODUCT_FID"),
							rs.getInt("PRODUCT_CID"),
							rs.getString("PRODUCT_FILENAME")
							
							
							
							);
					list.add(p);
					}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally {
				DBConnector.closeall(rs, ps, conn);
			}
	   	  return list;
	 }
	 
	 public static ArrayList<my_PRODUCT> selectAllByCid(int cid) {
	   	  ArrayList<my_PRODUCT> list=new ArrayList<my_PRODUCT>();
	   	  ResultSet rs = null;//声明结果集
	   	  //获取连接对象
	   	  Connection conn = DBConnector.getconn();
	   	   PreparedStatement ps = null;
	   	   
	   	   try { 
	   	String sql = "select * from my_PRODUCT where PRODUCT_CID=?";
	   	ps = conn.prepareStatement(sql);
		
	   	ps.setInt(1, cid);
	   	
	   	
		rs=ps.executeQuery();
	  
				while(rs.next()) {
					my_PRODUCT p = new my_PRODUCT(
							rs.getInt("PRODUCT_ID"),
							rs.getString("PRODUCT_NAME"),
							rs.getString("PRODUCT_DESCRIPTION"),
							rs.getInt("PRODUCT_PRICE"),
							rs.getInt("PRODUCT_STOCK"),
							rs.getInt("PRODUCT_FID"),
							rs.getInt("PRODUCT_CID"),
							rs.getString("PRODUCT_FILENAME")
							
							
							
							);
					list.add(p);
					}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally {
				DBConnector.closeall(rs, ps, conn);
			}
	   	  return list;
	     }
	 
	 public static my_PRODUCT selectById(int id) {
	   	 my_PRODUCT p = null;
	   	  ResultSet rs = null;//声明结果集
	   	  //获取连接对象
	   	  Connection conn = DBConnector.getconn();
	   	   PreparedStatement ps = null;
	   	   
	   	   try { 
	   	String sql = "select * from my_PRODUCT where PRODUCT_ID=?";
	   	ps = conn.prepareStatement(sql);
		ps.setInt(1, id);
		rs=ps.executeQuery();
	  
				while(rs.next()) {
					 p = new my_PRODUCT(
							rs.getInt("PRODUCT_ID"),
							rs.getString("PRODUCT_NAME"),
							rs.getString("PRODUCT_DESCRIPTION"),
							rs.getInt("PRODUCT_PRICE"),
							rs.getInt("PRODUCT_STOCK"),
							rs.getInt("PRODUCT_FID"),
							rs.getInt("PRODUCT_CID"),
							rs.getString("PRODUCT_FILENAME")
							
							
							
							);
					
					}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally {
				DBConnector.closeall(rs, ps, conn);
			}
	   	  return p;
	     }

	 
	 public static ArrayList<my_PRODUCT> selectAllById(ArrayList<Integer> ids) {
	   	  ArrayList<my_PRODUCT> lastlylist=new ArrayList<my_PRODUCT>();
	   	 
	   	my_PRODUCT p = null;
	   	  
	   	  ResultSet rs = null;//声明结果集
	   	  //获取连接对象
	   	  Connection conn = DBConnector.getconn();
	   	   PreparedStatement ps = null;
	   	   
	   	   try { 
	   		   for(int i=0; i<ids.size(); i++) {
	   			String sql = "select * from my_PRODUCT where PRODUCT_ID=?";
	   		   	ps = conn.prepareStatement(sql);
	   			
	   		   	ps.setInt(1, ids.get(i));
	   		   	
	   		   	
	   			rs=ps.executeQuery();
	   		  
	   					while(rs.next()) {
	   					 p = new my_PRODUCT(
	   								rs.getInt("PRODUCT_ID"),
	   								rs.getString("PRODUCT_NAME"),
	   								rs.getString("PRODUCT_DESCRIPTION"),
	   								rs.getInt("PRODUCT_PRICE"),
	   								rs.getInt("PRODUCT_STOCK"),
	   								rs.getInt("PRODUCT_FID"),
	   								rs.getInt("PRODUCT_CID"),
	   								rs.getString("PRODUCT_FILENAME")
	   								
	   								
	   								
	   								);
	   						lastlylist.add(p);
	   						}
	   		   }
	   
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}finally {
				DBConnector.closeall(rs, ps, conn);
			}
	   	  return lastlylist;
	     }
	 
	 
	 
	 /**
	  * 删除商品
	  * @param id
	  * @return
	  */
	 public static int del(int id) {
   	  String sql = "delete from my_PRODUCT where PRODUCT_ID=?";
   	 Object[] params = {id};
   	  return DBConnector.exectuIUD(sql, params);
     } 
	  
	 
	 
	 /**
	  * 
	  * @param id
	  * @return
	  */
	 public static my_PRODUCT selectByID(int id) {
    	 my_PRODUCT p = null;
    	 
    	  ResultSet rs = null;//声明结果集
    	  //获取连接对象
    	  Connection conn = DBConnector.getconn();
    	  
    	   PreparedStatement ps = null;
 
    	   try {
        String sql = "select * from my_PRODUCT where PRODUCT_ID=?";
        ps = conn.prepareStatement(sql);
        ps.setInt(1, id);
     	rs=ps.executeQuery();
			
			
			while(rs.next()) {
				 p = new my_PRODUCT(
						rs.getInt("PRODUCT_ID"),
						rs.getString("PRODUCT_NAME"),
						rs.getString("PRODUCT_DESCRIPTION"),
						rs.getInt("PRODUCT_PRICE"),
						rs.getInt("PRODUCT_STOCK"),
						rs.getInt("PRODUCT_FID"),
						rs.getInt("PRODUCT_CID"),
						rs.getString("PRODUCT_FILENAME")
						);
				 
				}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			DBConnector.closeall(rs, ps, conn);
		}
    	  return p;
      }
	 
}
