package com.my.servlet.home;

import java.io.IOException;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.my.entity.my_CATEGORY;
import com.my.entity.my_PRODUCT;
import com.my.service.my_CATEGORYDBC;
import com.my.service.my_PRODUCTDBC;

/**
 * Servlet implementation class SelectProductView
 */
@WebServlet("/selectproductview")
public class SelectProductView extends HttpServlet {
	
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		ArrayList<my_CATEGORY> flist =  my_CATEGORYDBC.selectCat("father");
		request.setAttribute("flist", flist);
		
		ArrayList<my_CATEGORY> clist =  my_CATEGORYDBC.selectCat("child");
		request.setAttribute("clist", clist);
		
		String id = request.getParameter("id");
	
		//获取最近访问
		
		HttpSession session = request.getSession();
		
		//从SSESSIOn获取一下 ids
		
		ArrayList<Integer> ids = (ArrayList<Integer>)session.getAttribute("ids");
		
		if(ids == null){
			ids = new ArrayList<Integer>();
		}
			
		//最多放5， 如果多出5个将第一个删除
		if(ids.size() >= 5) {
			ids.remove(0);
		}
		
		// 添加列表里， 但只要一份
		if(id!=null && (!ids.contains(Integer.parseInt(id)))) {
			ids.add(Integer.parseInt(id));
		
		}
		
		session.setAttribute("ids", ids);
		
		ids= (ArrayList<Integer>)session.getAttribute("ids");
		
		if(ids!=null) {
				
			ArrayList<my_PRODUCT> lastlylist = my_PRODUCTDBC.selectAllById(ids);
			request.setAttribute("lastlylist", lastlylist);
		}
		
		
		my_PRODUCT p = null;
		
		if(id !=null) {
			p = my_PRODUCTDBC.selectById(Integer.parseInt(id));
			request.setAttribute("p", p);
		}
		
		
		if(p!=null) {
			int cid = p.getPRODUCT_CID();
			ArrayList<my_PRODUCT> classlist = my_PRODUCTDBC.selectAllByCid(cid);
			request.setAttribute("classlist", classlist);
			
			my_CATEGORY cate = my_CATEGORYDBC.selectById(cid);
			
			request.setAttribute("cate", cate);
		}
		
		
		request.getRequestDispatcher("productview.jsp").forward(request, response);
	}

	
}
