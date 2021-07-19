package com.my.servlet.product;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.my.entity.my_CATEGORY;
import com.my.entity.my_PRODUCT;
import com.my.service.my_CATEGORYDBC;
import com.my.service.my_PRODUCTDBC;

/**
 * Servlet implementation class ProductSelect
 */
@WebServlet("/manage/admin_productselect")
public class ProductSelect extends HttpServlet {
	private static final long serialVersionUID = 1L;
  
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		ArrayList<my_PRODUCT>  plist = my_PRODUCTDBC.selectAll();
		
		request.setAttribute("plist", plist);
		
		
		request.getRequestDispatcher("admin_product.jsp").forward(request, response);
	}



}
