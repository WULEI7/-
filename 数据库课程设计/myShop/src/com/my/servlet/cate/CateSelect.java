package com.my.servlet.cate;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.my.entity.my_CATEGORY;
import com.my.service.my_CATEGORYDBC;

/**
 * Servlet implementation class CateSelect
 */
@WebServlet("/manage/admin_cateselect")
public class CateSelect extends HttpServlet {
	
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ArrayList<my_CATEGORY> catelist = my_CATEGORYDBC.selectAll();
		
		request.setAttribute("catelist", catelist);
		
		request.getRequestDispatcher("admin_cate.jsp").forward(request, response);
	}


}
