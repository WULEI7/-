<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta charset="UTF-8"/>
    <title>小拓商城-后台管理系统</title>
	<link rel="stylesheet" type="text/css" href="css/adminlogin.css"/>
</head>
<body>
<div class="admin_login_wrap">
    <h1>后台管理账户登录</h1>
    <div class="adming_login_border">
        <div class="admin_input">
            <form action="/myShop/manage/adminlogin" method="post">
                <ul class="admin_items">
                    <li>
                        <label for="user">用户名：</label>
                        <input type="text" name="userName" value="" id="user" size="40" class="admin_input_style" />
                    </li>
                    <li>
                        <label for="pwd">密码：</label>
                        <input type="password" name="passWord" value="" id="pwd" size="40" class="admin_input_style" />
                    </li>
                    <li>
                        <input type="submit" tabindex="3" value="提交" class="btn btn-primary" />
                    </li>
                </ul>
            </form>
        </div>
    <a href="..\indexselect" id="login1">进入前台</a>
    </div>
    
    <p> &copy; 2021 Powered by 小拓商城</p>
</div>
</body>
</html>