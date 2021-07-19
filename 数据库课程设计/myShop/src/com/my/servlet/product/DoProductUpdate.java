package com.my.servlet.product;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.my.entity.my_CATEGORY;
import com.my.entity.my_PRODUCT;
import com.my.entity.my_USER;
import com.my.service.my_CATEGORYDBC;
import com.my.service.my_PRODUCTDBC;
import com.my.service.my_USERDBC;

/**
 * Servlet implementation class DoProductUpdate
 */
@WebServlet("/manage/admin_doproductupdate")
public class DoProductUpdate extends HttpServlet {
	

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	/*protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		request.setCharacterEncoding("utf-8");
		response.setContentType("text/html charset=utf-8");
		
		int id=Integer.parseInt(request.getParameter("id"));
		String name=request.getParameter("productName");
		int price=Integer.parseInt(request.getParameter("productPrice"));
		String desc=request.getParameter("productDesc");
		int stock=Integer.parseInt(request.getParameter("productStock"));
	
		
	  PrintWriter pw=response.getWriter(); 			//连接数据库 			
		//创建用户实体
		my_PRODUCT product=new my_PRODUCT(id,name,desc,price,stock,null,null,null);


		int count = my_PRODUCTDBC.update(product);
		//System.out.print(u);
		//成功或失败的去向
		if(count > 0) {
			response.sendRedirect("/shop/manage/admin_douserselect?cp="+request.getParameter("cpage"));
			
		}else {
			PrintWriter out = response.getWriter();
			out.write("<script>");
			out.write("alter('用户登录失败')");
			out.write("location.href='manage/admin_touserupdate");
			out.write("</script>");
		  
	}
		protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			//设置字符集
			request.setCharacterEncoding("UTF-8");
			response.setContentType("text/html;charset=utf-8");
			
			int id = Integer.parseInt(request.getParameter("id"));
			int fid = Integer.parseInt(request.getParameter("parentId"));
			String name = request.getParameter("className");
			
			my_CATEGORY cate= new my_CATEGORY(id, name, fid);
			my_CATEGORYDBC.update(cate);
			
			response.sendRedirect("admin_cateselect");
		}
		
	}

	}
	*/
}
