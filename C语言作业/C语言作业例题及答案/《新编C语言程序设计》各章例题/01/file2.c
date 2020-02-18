static int max(int a,int b)   /*定义max函数*/
{
   if(a>b) return a;   /*把结果按条件返回主调函数*/
   else return b;
}


/* file2.c——C源程序文件2，含min()函数 */
 int min(int a,int b)  /*定义min函数*/
{
   int result;
   result= a<b?a:b;   /*使用?:条件运算符得到最小数*/
   return result;     /*返回最小值*/
}
