package com.my.servlet.cart;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.my.entity.my_CART;
import com.my.entity.my_USER;
import com.my.service.my_CARTDBC;

/**
 * Servlet implementation class ShowCart
 */
@WebServlet("/showcart")
public class ShowCart extends HttpServlet {
	
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");
		response.setContentType("text/html;charset=utf-8");
		
		HttpSession session =  request.getSession();
		
		String isLogin = (String)session.getAttribute("isLogin");
		
		my_USER user=(my_USER)session.getAttribute("name");
		
		if(user!=null && isLogin.equals("1")) {
			String uid = (String)user.getUSER_ID();
			
			ArrayList<my_CART> list= my_CARTDBC.getCart(uid);
			
			request.setAttribute("shoplist", list);
			
			request.getRequestDispatcher("cart.jsp").forward(request, response);
			
		}else{
			PrintWriter out = response.getWriter();
			
			out.write("<script>");
			out.write("alert('登录后，再购买')");
			out.write("location.href='login.jsp'");
			out.write("</script>");
			out.close();
			
			
		}
	}


}
