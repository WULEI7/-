/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 80023
Source Host           : localhost:3306
Source Database       : myshop

Target Server Type    : MYSQL
Target Server Version : 80023
File Encoding         : 65001

Date: 2021-07-12 10:55:24
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `my_cart`
-- ----------------------------
DROP TABLE IF EXISTS `my_cart`;
CREATE TABLE `my_cart` (
  `cart_id` int NOT NULL AUTO_INCREMENT,
  `cart_p_filename` varchar(128) DEFAULT NULL,
  `cart_p_name` varchar(64) DEFAULT NULL,
  `cart_p_price` decimal(10,2) DEFAULT NULL,
  `cart_quantity` int DEFAULT NULL,
  `cart_p_stock` int DEFAULT NULL,
  `cart_p_id` int DEFAULT NULL,
  `cart_u_id` varchar(64) DEFAULT NULL,
  `cart_valid` int DEFAULT NULL,
  PRIMARY KEY (`cart_id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of my_cart
-- ----------------------------

-- ----------------------------
-- Table structure for `my_category`
-- ----------------------------
DROP TABLE IF EXISTS `my_category`;
CREATE TABLE `my_category` (
  `CATE_ID` int NOT NULL AUTO_INCREMENT,
  `CATE_NAME` varchar(20) NOT NULL,
  `CATE_PARENT_ID` decimal(10,0) NOT NULL,
  PRIMARY KEY (`CATE_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=27 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of my_category
-- ----------------------------
INSERT INTO `my_category` VALUES ('12', 'Java图书', '0');
INSERT INTO `my_category` VALUES ('13', 'Python图书', '0');
INSERT INTO `my_category` VALUES ('14', 'PHP图书', '0');
INSERT INTO `my_category` VALUES ('21', '人工智能', '13');

-- ----------------------------
-- Table structure for `my_product`
-- ----------------------------
DROP TABLE IF EXISTS `my_product`;
CREATE TABLE `my_product` (
  `PRODUCT_ID` int NOT NULL AUTO_INCREMENT,
  `PRODUCT_NAME` varchar(128) NOT NULL,
  `PRODUCT_DESCRIPTION` varchar(512) DEFAULT NULL,
  `PRODUCT_PRICE` decimal(10,2) NOT NULL,
  `PRODUCT_STOCK` decimal(10,0) DEFAULT NULL,
  `PRODUCT_FID` decimal(10,0) DEFAULT NULL,
  `PRODUCT_CID` decimal(10,0) DEFAULT NULL,
  `PRODUCT_FILENAME` varchar(200) DEFAULT NULL,
  PRIMARY KEY (`PRODUCT_ID`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of my_product
-- ----------------------------
INSERT INTO `my_product` VALUES ('1', '细说PHP 第四版', '一本详细介绍PHP的书', '158.00', '3000', '14', '23', '0bf587e1b7d5de74.jpg');
INSERT INTO `my_product` VALUES ('2', 'PHP学习手册', '自学PHP的手册，全面实用', '51.00', '21', '14', '22', '592fb45cNac23b876.jpg');
INSERT INTO `my_product` VALUES ('3', 'PHP项目案例', '通过这本书，可以完成PHP的项目案例', '104.00', '55', '14', '23', '56f63c22Nbb294bc0.jpg');
INSERT INTO `my_product` VALUES ('4', 'Java编程思想', '这是一本学习Java好书', '109.00', '3223', '12', '17', '5624b582Nbc01af5b.jpg');
INSERT INTO `my_product` VALUES ('5', 'Java从入门到精通', '学习Java，对新手友好', '68.00', '99', '12', '17', '99742c91174d3d7a.jpg');
INSERT INTO `my_product` VALUES ('6', 'Java经典案例', 'Java程序案例，经典实用', '88.00', '55', '12', '17', '74a5a5dcd83ecc09.jpg');
INSERT INTO `my_product` VALUES ('7', 'Java核心技术', '全面介绍Java的核心技术', '128.00', '120', '12', '17', '57e09a03Nc57334e1.jpg');
INSERT INTO `my_product` VALUES ('8', '深入理解Java虚拟机', '了解Java虚拟机，就选这一本', '89.00', '55', '12', '17', '592bf167Naf49f7f6.jpg');
INSERT INTO `my_product` VALUES ('9', 'Java精彩编程', '编程案例多，内容精彩丰富', '106.00', '555', '12', '17', 'ccc877ab66ae0b5e.jpg');
INSERT INTO `my_product` VALUES ('10', 'Python编程技术', '是一本学习Ptyhon的实用好书', '120.00', '77', '13', '20', '5acb3627N8191c867.jpg');

-- ----------------------------
-- Table structure for `my_user`
-- ----------------------------
DROP TABLE IF EXISTS `my_user`;
CREATE TABLE `my_user` (
  `USER_ID` varchar(32) NOT NULL,
  `USER_NAME` varchar(20) NOT NULL,
  `USER_PASSWORD` varchar(20) NOT NULL,
  `USER_SEX` varchar(1) NOT NULL,
  `USER_BIRTHDAY` datetime DEFAULT NULL,
  `USER_IDENITY_CODE` varchar(60) DEFAULT NULL,
  `USER_EMAIL` varchar(60) DEFAULT NULL,
  `USER_MOBILE` varchar(11) DEFAULT NULL,
  `USER_ADDRESS` varchar(200) NOT NULL,
  `USER_STATUS` decimal(6,0) NOT NULL,
  PRIMARY KEY (`USER_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of my_user
-- ----------------------------
INSERT INTO `my_user` VALUES ('admin1', 'admin', '123456', 'F', '2021-07-06 00:00:00', '10000', 'admin@qq.com', '12312300001', '后台管理中心', '2');
INSERT INTO `my_user` VALUES ('admin2', 'admin', '123456', 'T', '2021-07-06 00:00:00', '10000', 'admin@qq.com', '12312300002', '后台管理中心', '2');
INSERT INTO `my_user` VALUES ('admin3', 'admin', '123456', 'T', '2021-07-06 00:00:00', '10000', 'admin@qq.com', '12312300003', '后台管理中心', '2');
INSERT INTO `my_user` VALUES ('LiSi', '李四', '123456', 'F', '2002-02-02 00:00:00', '10002', 'LiSi@qq.com', '18918900002', '江南大学人工智能与计算机学院102', '1');
INSERT INTO `my_user` VALUES ('WangWu', '王五', '123456', 'T', '2003-03-03 00:00:00', '10003', 'WangWu@qq.com', '18918900003', '江南大学人工智能与计算机学院103', '1');
INSERT INTO `my_user` VALUES ('ZhangSan1', '张三', '123456', 'T', '2001-01-01 00:00:00', '10001', 'ZhangSan@qq.com', '18918900001', '江南大学人工智能与计算机学院101', '1');
INSERT INTO `my_user` VALUES ('ZhangSan2', '张三', '123456', 'T', '2001-01-01 00:00:00', '10001', 'ZhangSan@qq.com', '18918900001', '江南大学人工智能与计算机学院101', '1');
INSERT INTO `my_user` VALUES ('ZhangSan3', '张三', '123456', 'T', '2001-01-01 00:00:00', '10001', 'ZhangSan@qq.com', '18918900001', '江南大学人工智能与计算机学院101', '1');
INSERT INTO `my_user` VALUES ('ZhangSan4', '张三', '123456', 'T', '2001-01-01 00:00:00', '10001', 'ZhangSan@qq.com', '18918900001', '江南大学人工智能与计算机学院101', '1');
INSERT INTO `my_user` VALUES ('ZhangSan5', '张三', '123456', 'T', '2001-01-01 00:00:00', '10001', 'ZhangSan@qq.com', '18918900001', '江南大学人工智能与计算机学院101', '1');
INSERT INTO `my_user` VALUES ('ZhaoLiu', '赵六', '123456', 'F', '2004-04-04 00:00:00', '10004', 'ZhaoLiu@qq.com', '18918900004', '江南大学人工智能与计算机学院104', '1');
