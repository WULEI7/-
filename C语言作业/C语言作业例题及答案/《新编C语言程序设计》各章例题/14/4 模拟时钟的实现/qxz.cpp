///////////////////////////////////////////////////////
//编译环境：Visual C++ 6.0，Easyx库	        //
///////////////////////////////////////////////////////
#include <graphics.h>   // 引用 EasyX 图形库，程序以.cpp为扩展名
#include <windows.h>
#include <conio.h>
#include <math.h>
#define PI 3.1415926
int main(void)
{	/*函数原型声明*/
	void DralDial();                            /*画表盘*/
	void DrawDecoration();                     // 画装饰
	void DrawHand(int hour, int minute, int second); //画指针
	initgraph(600, 600);           //初始化600×600的绘图窗口
	setbkcolor(RGB(245, 247, 222));  //设置背景色
	cleardevice();                //清空屏幕
	DrawDecoration();            //画装饰
	DralDial();                   //画表盘
	//刻名字
	setcolor(RED);
	setfont(32, 0, "华文新魏");
	outtextxy(260, 130, "Clock");
	setwritemode(R2_XORPEN);   //设置异或绘图方式
	SYSTEMTIME t;             //定义变量，保存当前时间
	while(!kbhit()){
		GetLocalTime(&t);      //获取当前时间
		DrawHand(t.wHour, t.wMinute, t.wSecond); //画表针
		Sleep(1000);
		DrawHand(t.wHour, t.wMinute, t.wSecond); //擦表针
	}
	closegraph();  //关闭绘图窗口
	return 0;
}
void DralDial()  /*画表盘*/
{	int i,x1, y1, x2, y2, x3, y3, x4, y4, x5, y5; //表心坐标系坐标
	char rome[][3]= {"12","1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11" } ; //表盘数字
	//画四个圆
	setcolor(LIGHTGRAY);
	circle(300, 300, 250);circle(300, 300, 30);
	circle(300, 300, 260);circle(300, 300, 270);
	for(i = 0; i < 59; i++){
		// 画60条短线
		setcolor(LIGHTGRAY);
		x1 = (int)(300 + (sin(i * PI / 30) * 250)); y1 = (int)(300 - (cos(i * PI / 30) * 250));
		x2 = (int)(300 + (sin(i * PI / 30) * 260)); y2 = (int)(300 - (cos(i * PI / 30) * 260));
		line(x1, y1, x2, y2);
		//画12个三角形
		setfillstyle(BLACK);
		if(i % 5 == 0){
			x3 = (int)(x1 + sin((i + 5) * PI / 30) * 12 );
			y3 = (int)(y1 - cos((i + 5) * PI / 30) * 12 );
			x4 = (int)(x1 + sin((i - 5) * PI / 30) * 12 );
			y4 = (int)(y1 - cos((i - 5) * PI / 30) * 12 );
			x5 = (int)(290 + (sin((i - 0.2) * PI / 30) * 220));
			y5 = (int)(290 - (cos((i - 0.2) * PI / 30) * 220));
			int triangle[6] = {x1, y1, x3, y3, x4, y4};
			setcolor(BLACK);
			fillpolygon(3, triangle);
			//写表盘数字
			setcolor(RED);
			setfont(24, 0, "黑体");
			outtextxy(x5 , y5, rome[i / 5]);
		}
	}
}
void DrawDecoration()  // 画装饰
{	double i; int x1, y1, x2, y2; //表心坐标系坐标
	//极坐标系，画函数图像
	setcolor(RGB(250, 225, 222));
	for(i = 0; i < 10 * PI ; i += 0.4){
		x1 = (int)(300 + (250 * sin(2.4 * i)));
		y1 = (int)(300 - (250 * cos(2.4 * i)));
		x2 = (int)(300 + (250 * sin(2.4 * (i + 1))));
		y2 = (int)(300 - (250 * cos(2.4 * (i + 1))));
		line(x1, y1, x2, y2);
	}
}
void DrawHand(int hour, int minute, int second) //画指针
{	int xhour, yhour, xminute, yminute, xsecond, ysecond;	//表心坐标系指针坐标
	xhour = (int)(130 * sin( hour * PI / 6 + minute * PI / 360 + second * PI / 1800));
	yhour = (int)(130 * cos( hour * PI / 6 + minute * PI / 360 + second * PI / 1800));
	xminute = (int)(145 * sin( minute  * PI / 30 + second * PI / 1800));
	yminute = (int)(145 * cos( minute  * PI / 30 + second * PI / 1800));
	xsecond = (int)(200 * sin( second * PI / 30));
	ysecond = (int)(200 * cos( second * PI / 30));
	//画时针
	setlinestyle(PS_SOLID, NULL, 10);
	setcolor(LIGHTGRAY);
	line(300 + xhour, 300 - yhour, 300 -xhour / 6, 300 + yhour / 6);
	//画分针
	setlinestyle(PS_SOLID, NULL, 7);
	setcolor(RGB(222, 158, 107));
	line(300 + xminute, 300 - yminute, 300 -xminute / 4, 300 + yminute / 4);
	//画秒针
	setlinestyle(PS_SOLID, NULL, 3);
	setcolor(RED);
	line(300 + xsecond, 300 - ysecond, 300 -xsecond / 3, 300 + ysecond / 3);
}
