package com.my.servlet.cart;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.my.service.my_CARTDBC;

/**
 * Servlet implementation class CartShopDel
 */
@WebServlet("/cartshopdel")
public class CartShopDel extends HttpServlet {
	
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String esid = request.getParameter("esid");
		
		my_CARTDBC.getDeleteDD(Integer.parseInt(esid));
	}
	

}
