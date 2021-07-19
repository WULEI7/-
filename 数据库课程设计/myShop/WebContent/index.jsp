<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head lang="en">
    <meta charset="utf-8"/>
    <title>小拓商城</title>
    <link rel="stylesheet" type="text/css" href="css/public.css"/>
    <link rel="stylesheet" type="text/css" href="css/index.css"/>
</head>
<body><!------------------------------head------------------------------>

<%@ include file="header.jsp" %>

<!-------------------------banner--------------------------->
<div class="block_home_slider">
    <div id="home_slider" class="flexslider">
        <ul class="slides">
            <li>
                <div class="slide"><img src="img/banner2.jpg"/></div>
            </li>
            <li>
                <div class="slide"><img src="img/banner1.jpg"/></div>
            </li>
        </ul>
    </div>
</div>


<a href="#" class="ad"><img src="img/ib1.jpg"/></a>

<!--返回顶部-->
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
</div><!-------------------login--------------------------><!--footer-->
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
<script src="js/nav.js" type="text/javascript" charset="utf-8"></script>
<script src="js/jquery.flexslider-min.js" type="text/javascript" charset="utf-8"></script>
<script type="text/javascript">$(function () {
    $('#home_slider').flexslider({
        animation: 'slide',
        controlNav: true,
        directionNav: true,
        animationLoop: true,
        slideshow: true,
        slideshowSpeed: 2000,
        useCSS: false
    });
});</script>
</body>
</html>