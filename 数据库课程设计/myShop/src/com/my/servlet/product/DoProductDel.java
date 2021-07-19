package com.my.servlet.product;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.my.service.my_CATEGORYDBC;
import com.my.service.my_PRODUCTDBC;
import com.my.service.my_USERDBC;

/**
 * Servlet implementation class DoProductDel
 */
@WebServlet("/manage/admin_doprodel")
public class DoProductDel extends HttpServlet {
	

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String id = request.getParameter("id");
		my_PRODUCTDBC.del(Integer.parseInt(id));
		response.sendRedirect("admin_productselect");
	}

		
	}

	

