package com.my.servlet.cate;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.my.entity.my_CATEGORY;
import com.my.service.my_CATEGORYDBC;

/**
 * Servlet implementation class DoUserCate
 */
@WebServlet("/manage/admin_docateadd")
public class DoUserCate extends HttpServlet {
	


	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//设置字符集
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=utf-8");
		
		
		int fid = Integer.parseInt(request.getParameter("parentId"));
		String name = request.getParameter("className");
		
		my_CATEGORY cate= new my_CATEGORY(0, name, fid);
		my_CATEGORYDBC.insert(cate);
		
		response.sendRedirect("admin_cateselect");
		
	}

}
