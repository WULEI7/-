<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
     <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>   
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head lang="en">
    <meta charset="utf-8"/>
    <title>小拓商城-个人信息</title>
    <link rel="stylesheet" type="text/css" href="css/public.css"/>
    <link rel="stylesheet" type="text/css" href="css/myinfo.css"/>
</head>
<body><!------------------------------head------------------------------>
<div class="head ding">
    <div class="wrapper clearfix">
        <div class="clearfix" id="top"><h1 class="fl"><a href="indexselect"><img src="img/logo.png"/></a></h1>
            <div class="fr clearfix" id="top1"><p class="fl"><a href="#" id="login">登录</a><a href="#" id="reg">注册</a>
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
</div><!------------------------------idea------------------------------>
<div class="address mt" id="add">
    <div class="wrapper clearfix"><a href="indexselect" class="fl">首页</a><span>/</span><a href="myinfo.jsp" class="on">个人中心</a>
    </div>
</div><!------------------------------Bott------------------------------>
<div class="Bott">
    <div class="wrapper clearfix">
        <div class="zuo fl">
            <h3><a href="#"><img src="img/tx.png"/></a>
                <p class="clearfix"><span class="fl">${name.USER_NAME }</span>
                <c:if test="${isLogin ==1 }">
                	<span>[<a href="logout">退出登录</a>]</span>
                </c:if>
                </p></h3>
            <div><h4>我的交易</h4>
                <ul>
                    <li><a href="showcart">我的购物车</a></li>
                    <li><a href="myorderq.html">我的订单</a></li>
                    <li><a href="myprod.html">评价晒单</a></li>
                </ul>
                <h4>个人中心</h4>
                <ul>
                    <li class="on"><a href="myinfo.jsp">我的中心</a></li>
                    <li><a href="address.html">地址管理</a></li>
                </ul>
                <h4>账户管理</h4>
                <ul>
                    <li><a href="mygrxx.jsp">个人信息</a></li>
                    <li><a href="remima.html">修改密码</a></li>
                </ul>
            </div>
        </div>
        <div class="you fl">
            <div class="tx clearfix">
                <div class="fl clearfix"><a href="#" class="fl"><img src="img/tx.png"/></a>
                    <p class="fl"><span>${name.USER_NAME }</span><a href="mygrxx.jsp">修改个人信息></a></p></div>
                <div class="fr">绑定邮箱：${name.USER_EMAIL }</div>
            </div>
            <div class="bott">
                <div class="clearfix"><a href="#" class="fl"><img src="img/gxin1.jpg"/></a>
                    <p class="fl"><span>待支付的订单：<strong>0</strong></span><a href="myorderq.html">查看待支付订单></a></p></div>
                <div class="clearfix"><a href="#" class="fl"><img src="img/gxin2.jpg"/></a>
                    <p class="fl"><span>待收货的订单：<strong>0</strong></span><a href="myorderq.html">查看待收货订单></a></p></div>
                <div class="clearfix"><a href="#" class="fl"><img src="img/gxin3.jpg"/></a>
                    <p class="fl"><span>待评价的订单：<strong>0</strong></span><a href="myprod.html">查看待评价订单></a></p></div>
                <div class="clearfix"><a href="#" class="fl"><img src="img/gxin4.jpg"/></a>
                    <p class="fl"><span>喜欢的商品：<strong>0</strong></span><a href="#">查看喜欢的商品></a></p></div>
            </div>
        </div>
    </div>
</div><!--返回顶部-->
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
<script src="js/jquery-1.12.4.min.js" type="text/javascript" charset="utf-8"></script>
<script src="js/public.js" type="text/javascript" charset="utf-8"></script>
<script src="js/user.js" type="text/javascript" charset="utf-8"></script>
</body>
</html>