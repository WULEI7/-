<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
   <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head lang="en">
    <meta charset="utf-8"/>
    <title>小拓商城-购物车</title>
    <link rel="stylesheet" type="text/css" href="css/public.css"/>
    <link rel="stylesheet" type="text/css" href="css/proList.css"/>
    <script src="js/jquery-1.12.4.min.js" type="text/javascript" charset="utf-8"></script>
</head>
<body><!--------------------------------------cart--------------------->
<div class="head ding">
    <div class="wrapper clearfix">
        <div class="clearfix" id="top"><h1 class="fl"><a href="indexselect"><img src="img/logo.png"/></a></h1>
            <div class="fr clearfix" id="top1"><p class="fl"><a href="login.html" id="login">登录</a><a href="reg.html"
                                                                                                      id="reg">注册</a>
            </p>
                <form action="#" method="get" class="fl"><input type="text" placeholder="搜索"/><input type="button"/>
                </form>
                <div class="btn fl clearfix">
                      <c:if test="${isLogin ==1 }">
                      	<a href="myinfo.jsp"><img src="img/grzx.png"/></a>
                      	<a href="showcart"><img src="img/gwc.png"/></a>
                      </c:if> 
                        
                </div>
            </div>
        </div>
        <ul class="clearfix" id="bott">
            <li><a href="indexselect">返回首页</a></li>
            
        </ul>
    </div>
</div>
<div class="cart mt"><!-----------------logo------------------->
    <!--<div class="logo"><h1 class="wrapper clearfix"><a href="indexselect"><img class="fl" src="img/temp/logo.png"></a><img class="top" src="img/temp/cartTop01.png"></h1></div>-->
    <!-----------------site------------------->
    <div class="site"><p class=" wrapper clearfix"><span class="fl">购物车</span><img class="top"
                                                                                   src="img/temp/cartTop01.png"><a
            href="indexselect" class="fr">继续购物&gt;</a></p></div><!-----------------table------------------->
    <div class="table wrapper">
        <div class="tr">
            <div>商品</div>
            <div>单价</div>
            <div>数量</div>
            <div>小计</div>
            <div>操作</div>
        </div>
       
       <c:forEach var="rs" items="${requestScope.shoplist }">
       
        <div class="th">
            <div class="pro clearfix"><label class="fl">
            	<input name="ck" type="checkbox" value="${rs.cart_id }"/>
            	
            	<span></span></label>
            	<a class="fl" href="selectproductview?id=${rs.cart_p_id }">
                <dl class="clearfix">
                    <dt class="fl"><img width="120" height="120" src="images/product/${rs.cart_p_filename }"></dt>
                    <dd class="fl"><p>${rs.cart_p_name }</p>
                        <p>商品分类</p>
                        <p>默认</p></dd>
                </dl>
            </a></div>
            <div class="price">￥${rs.cart_p_price }.00</div>
            <div class="number">
            	<p class="num clearfix">
            	<img class="fl sub" src="img/temp/sub.jpg">
            	<span datasrc="${rs.cart_id }" class="fl">${rs.cart_quantity }</span>
            	<img class="fl add" src="img/temp/add.jpg"></p>
           </div>
            <div class="price sAll">￥${rs.cart_p_price * rs.cart_quantity }.00</div>
            <div class="price"><a class="del" datasrc="${rs.cart_id }" href="#2">删除</a></div>
        </div>
       
       </c:forEach>
       
        
        <div class="goOn">空空如也~<a href="indexselect">去逛逛</a></div>
        <div class="tr clearfix"><label class="fl"><input class="checkAll" type="checkbox"/><span></span></label>
            <p class="fl"><a href="#">全选</a><a href="#" class="del">删除</a></p>
            <p class="fr"><span>共<small id="sl">0</small>件商品</span><span>合计:&nbsp;<small id="all">￥0.00</small></span><a
                    href="javascript:toorder()" class="count">结算</a></p></div>
    </div>
</div>

<script>
	function toorder() {
			var str = "";
			
			$("input[name='ck']:checked").each(function(index, item){
				if($("input[name='ck']:checked").length-1 == index){
					str+= $(this).val();
				}else{
					str+= $(this).val()+",";
				}
				
			});
			
			location.href="orderselect?eids="+str;
		
	}
</script>
<div class="mask"></div>
<div class="tipDel"><p>确定要删除该商品吗？</p>
    <p class="clearfix"><a class="fl cer" href="#">确定</a><a class="fr cancel" href="#">取消</a></p></div><!--返回顶部-->
<div class="gotop">
<c:if test="${isLogin ==1 }">
	<a href="showcart">
	    <dl>
	        <dt><img src="img/gt1.png"/></dt>
	        <dd>去购<br/>物车</dd>
	    </dl>
	</a>
	<a href="myinfo.jsp">
	    <dl>
	        <dt><img src="img/gt3.png"/></dt>
	        <dd>个人<br/>中心</dd>
	    </dl>
	</a>
</c:if>
<a href="#" class="toptop" style="display: none;">
    <dl>
        <dt><img src="img/gt4.png"/></dt>
        <dd>返回<br/>顶部</dd>
    </dl>
</a>
</div>
<!--footer-->
<div class="footer">
    <div class="top">
        <div class="wrapper">
            <div class="clearfix"><a href="#2" class="fl"><img src="img/foot1.png"/></a><span class="fl">7天无理由退货</span>
            </div>
            <div class="clearfix"><a href="#2" class="fl"><img src="img/foot2.png"/></a><span class="fl">15天免费换货</span>
            </div>
            <div class="clearfix"><a href="#2" class="fl"><img src="img/foot3.png"/></a><span class="fl">满99元包邮</span>
            </div>
            <div class="clearfix"><a href="#2" class="fl"><img src="img/foot4.png"/></a><span class="fl">服务让您满意</span>
            </div>
        </div>
    </div>
    <p class="dibu">小拓商城&copy;2021版权所有<br/>
        江南大学人工智能与计算机学院</p></div><!----------------mask------------------->
<div class="mask"></div><!-------------------mask内容------------------->
<div class="proDets"><img class="off" src="img/temp/off.jpg"/>
    <div class="proCon clearfix">
        
        <div class="fl">
            <div class="proIntro change"><p>颜色分类</p>
                <div class="smallImg clearfix"><p class="fl on"><img src="img/temp/prosmall01.jpg" alt="默认"
                                                                     data-src="img/temp/proBig01.jpg"></p>
                    
                </div>
            </div>
            <div class="changeBtn clearfix"><a href="#2" class="fl"><p class="buy">确认</p></a><a href="#2" class="fr"><p
                    class="cart">取消</p></a></div>
        </div>
    </div>
</div>
<div class="pleaseC"><p>请选择宝贝</p><img class="off" src="img/temp/off.jpg"/></div>

<script src="js/public.js" type="text/javascript" charset="utf-8"></script>
<script src="js/pro.js" type="text/javascript" charset="utf-8"></script>
<script src="js/cart.js" type="text/javascript" charset="utf-8"></script>
</body>
</html>