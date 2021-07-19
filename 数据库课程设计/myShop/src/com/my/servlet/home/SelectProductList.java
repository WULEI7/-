package com.my.servlet.home;

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
 * Servlet implementation class SelectProductList
 */
@WebServlet("/selectproductlist")
public class SelectProductList extends HttpServlet {
	
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ArrayList<my_CATEGORY> flist =  my_CATEGORYDBC.selectCat("father");
		request.setAttribute("flist", flist);
		
		ArrayList<my_CATEGORY> clist =  my_CATEGORYDBC.selectCat("child");
		request.setAttribute("clist", clist);
		
		String fid = request.getParameter("fid");
		String cid = request.getParameter("cid");
		
		int id=0;
		ArrayList<my_PRODUCT> list = null;
		if(fid!=null) {
			id=Integer.parseInt(fid);
			list = my_PRODUCTDBC.selectAllByFid(id);
		}
		
		if(cid!=null) {
			id=Integer.parseInt(cid);
			list = my_PRODUCTDBC.selectAllByCid(id);
		}
		
		request.setAttribute("title", my_CATEGORYDBC.selectById(id).getCATE_NAME());
		
		request.setAttribute("list", list);
		request.getRequestDispatcher("productlist.jsp").forward(request, response);
	}



}
