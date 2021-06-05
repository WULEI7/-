drop database study;

create database study;

use study;

CREATE TABLE course (
	cno char (2)   ,
	cname char (16) ,
	credit decimal(2, 1)) ;
insert into  course values('c1','数据库',4);
insert into  course values('c2','数学',	2.5);
insert into  course values('c3','信息系统',4);
insert into  course values('c4','英语',	3);
select * from course;

CREATE TABLE student (
	sno char (5)   ,
	sname char (10) ,
	ssex char (2)    ,
	sage  int  ,
	sdept char( 20 ));
insert into student values('20001','张小明','女',23,'信息系');
insert into student values('20002','李强','男',	21,'计算机系');
insert into student values('20003','王方','女',28,'信息系');
insert into student values('20004','刘晨','男',18,'计算机系');
select * from student;

CREATE TABLE SC(
  Sno char(5) ,
  Cno char(2) ,
  Grade decimal(3,0)
   );
insert into SC values('20001','c1',91);
insert into SC values('20001','c2',92);
insert into SC values('20001','c3',93);
insert into SC values('20001','C4',94);
insert into SC values('20002','c2',81);
insert into SC values('20002','c3',80);
insert into SC values('20004','C1',70);
insert into SC values('20004','C2',71);
insert into SC values('20004','C3',72);
select * from sc;






