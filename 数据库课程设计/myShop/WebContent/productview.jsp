<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
  <%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>   
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta charset="UTF-8">
    <title>小拓商城-详情页</title>
    <link rel="stylesheet" type="text/css" href="css/public.css"/>
    <link rel="stylesheet" type="text/css" href="css/proList.css"/>
</head>
<body><!------------------------------head------------------------------>

<%@ include file="header.jsp" %>

<!-----------------address------------------------------->
<div class="address">
    <div class="wrapper clearfix">
    		<a href="indexselect">首页</a><span>/</span>
    		<a href="selectproductlist?cid=${cate.CATE_ID }">${cate.CATE_NAME }</a><span>/</span>
    		<a href="#" class="on">${p.PRODUCT_NAME }</a>
    </div>
</div><!-----------------------Detail------------------------------>
<div class="detCon">
    <div class="proDet wrapper">
        <div class="proCon clearfix">
            <div class="proImg fl">
            <img class="det" src="images/product/${p.PRODUCT_FILENAME }"/>
                <div class="smallImg clearfix"><img src="images/product/${p.PRODUCT_FILENAME }"
                                                    data-src="images/product/${p.PRODUCT_FILENAME }"></div>
            </div>
            <div class="fr intro">
                <div class="title"><h4>【小拓商城】${p.PRODUCT_NAME }</h4>
                    <p>【${p.PRODUCT_DESCRIPTION }】</p><span>￥${p.PRODUCT_PRICE }.00</span></div>
                <div class="proIntro"><p>颜色分类</p>
                    <div class="smallImg clearfix categ"><p class="fl"><img src="images/product/${p.PRODUCT_FILENAME }"
                                                                            alt="默认"
                                                                            data-src="images/product/${p.PRODUCT_FILENAME }"></p>
                    </div>
                    <p>数量&nbsp;&nbsp;库存<span>${p.PRODUCT_STOCK }</span>件</p>
                    <div class="num clearfix">
                    		<img class="fl sub" src="img/temp/sub.jpg">
                    		<span id="count" class="fl" contentEditable="true">1</span><img
                            class="fl add" src="img/temp/add.jpg">
                        <p class="please fl">请选择商品属性!</p></div>
                </div>
                <div class="btns clearfix">
                	<a href="javascript:shopAdd(${p.PRODUCT_ID },'z')"><p class="buy fl">立即购买</p></a>
                	<a href="javascript:shopAdd(${p.PRODUCT_ID },'s')""><p class="cart fr"> 加入购物车</p></a></div>
            </div>
        </div>
    </div>
</div>

<script>
	function shopAdd(id, url) {
		var count = document.getElementById("count").innerHTML;
		
		location.href='cartadd?id='+id+'&count='+count+'&url='+url;
		
	}

</script>

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
</div>
<div class="msk"></div><!--footer-->
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
<script src="js/jquery.SuperSlide.2.1.1.js" type="text/javascript" charset="utf-8"></script>
<script src="js/public.js" type="text/javascript" charset="utf-8"></script>
<script src="js/nav.js" type="text/javascript" charset="utf-8"></script>
<script src="js/pro.js" type="text/javascript" charset="utf-8"></script>
<script src="js/cart.js" type="text/javascript" charset="utf-8"></script>
<script type="text/javascript">jQuery(".bottom").slide({
    titCell: ".hd ul",
    mainCell: ".bd .likeList",
    autoPage: true,
    autoPlay: false,
    effect: "leftLoop",
    autoPlay: true,
    vis: 1
});</script>
</body>
</html>
