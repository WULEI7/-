package com.my.servlet.product;

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
 * Servlet implementation class ToProductAdd
 */
@WebServlet("/manage/admin_toproductadd")
public class ToProductAdd extends HttpServlet {

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		ArrayList<my_CATEGORY> flist = my_CATEGORYDBC.selectCat("father");
		request.setAttribute("flist", flist);
		
		ArrayList<my_CATEGORY> clist = my_CATEGORYDBC.selectCat("child");
		request.setAttribute("clist", clist);
		
		request.getRequestDispatcher("/manage/admin_productadd.jsp").forward(request, response);;
		
		
		
		
	}

}
