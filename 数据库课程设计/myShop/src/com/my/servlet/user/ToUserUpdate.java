package com.my.servlet.user;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.my.entity.my_USER;
import com.my.service.my_USERDBC;

/**
 * Servlet implementation class ToUserUpdate
 */
@WebServlet("/manage/admin_touserupdate")
public class ToUserUpdate extends HttpServlet {
	private static final long serialVersionUID = 1L;

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=utf-8");
		
		String id = request.getParameter("id");
		
		//通过ID到数据里查找
		my_USER user = my_USERDBC.selectByID(id);
		
		request.setAttribute("user", user);
		
		
		request.setAttribute("cpage", request.getParameter("cpage"));
		request.getRequestDispatcher("admin_usermodify.jsp").forward(request, response);
		
	}


}
