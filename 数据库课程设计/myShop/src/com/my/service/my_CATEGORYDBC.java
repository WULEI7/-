package com.my.service;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

import com.my.DBC.DBConnector;
import com.my.entity.my_CATEGORY;
import com.my.entity.my_USER;

/**
 * 获取所有分类
 * @author Administrator
 *
 */
public class my_CATEGORYDBC {
	public static ArrayList<my_CATEGORY> selectAll() {
		ArrayList<my_CATEGORY> list = new ArrayList<my_CATEGORY>();
		//声明结果集
		ResultSet rs = null;
		//获取连接对象
		Connection conn = DBConnector.getconn();
		
		PreparedStatement ps = null;
		
		
		
		try {
			String sql = "select * from my_CATEGORY";
			ps = conn.prepareStatement(sql);
			rs = ps.executeQuery();
			 
			 while(rs.next()) {
				 my_CATEGORY cate = new my_CATEGORY(
						 	rs.getInt("CATE_ID"),
						 	rs.getString("CATE_NAME"),
						 	rs.getInt("CATE_PARENT_ID")
						 
						 );
				 
				 
				 list.add(cate);
				 
			 }
			 
			 
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			DBConnector.closeall(rs, ps, conn);
		}
		
		
		
		return list;
	}
	/**
	 * 查询分类，子分类和父级分类
	 * @param flag  flag="father" flag="child"
	 * @return
	 */
	
	public static ArrayList<my_CATEGORY> selectCat(String flag) {
		ArrayList<my_CATEGORY> list = new ArrayList<my_CATEGORY>();
		//声明结果集
		ResultSet rs = null;
		//获取连接对象
		Connection conn = DBConnector.getconn();
		
		PreparedStatement ps = null;
		
		
		
		try {
			
			String sql = null;
			
			if(flag!=null && flag.equals("father")){
			
				sql = "select * from my_CATEGORY where CATE_PARENT_ID=0";
			}else{
				sql = "select * from my_CATEGORY where CATE_PARENT_ID!=0";
			}
			ps = conn.prepareStatement(sql);
			rs = ps.executeQuery();
			 
			 while(rs.next()) {
				 my_CATEGORY cate = new my_CATEGORY(
						 	rs.getInt("CATE_ID"),
						 	rs.getString("CATE_NAME"),
						 	rs.getInt("CATE_PARENT_ID")
						 
						 );
				 
				 
				 list.add(cate);
				 
			 }
			 
			 
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			DBConnector.closeall(rs, ps, conn);
		}
		
		
		
		return list;
	}
	
	
	
	public static my_CATEGORY selectById(int id) {

		my_CATEGORY cate = null;
		
		//声明结果集
		ResultSet rs = null;
		//获取连接对象
		Connection conn = DBConnector.getconn();
		
		PreparedStatement ps = null;
		
		
		
		try {
			String sql = "select *  from my_CATEGORY  where CATE_ID=?";
			
			 ps = conn.prepareStatement(sql);
			 ps.setInt(1, id);
			
			 
			 rs = ps.executeQuery();
			 
			 while(rs.next()) {
				 cate = new my_CATEGORY(
						 	rs.getInt("CATE_ID"),
						 	rs.getString("CATE_NAME"),
						 	rs.getInt("CATE_PARENT_ID")
			
						 );
				 
				 
				
				 
			 }
			 
			 
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			DBConnector.closeall(rs, ps, conn);
		}
		
		
		
		return cate;
	}
	
	
	
	/**
	 * 添加分类
	 * @param cate
	 * @return
	 */
	
	public static int insert(my_CATEGORY cate) {
		String sql = "insert into my_category values(null, ?, ?)";
		
		Object[] params = {
					cate.getCATE_NAME(), 
					cate.getCATE_PARENT_ID()
					};
		
		return DBConnector.exectuIUD(sql, params);
	}
	
	

	public static int update(my_CATEGORY cate) {
		String sql = "update my_CATEGORY set CATE_NAME=?, CATE_PARENT_ID=?  where CATE_ID = ?";
		
		Object[] params = {
					cate.getCATE_NAME(),
					cate.getCATE_PARENT_ID(),
					cate.getCATE_ID()
					};
		
		return DBConnector.exectuIUD(sql, params);
}

	
	public static int del(int id) {
		String sql = "delete from my_CATEGORY where CATE_ID=?";
		
		Object[] params = {id};
		
		return DBConnector.exectuIUD(sql, params);
		
	}
	
	
	

}
