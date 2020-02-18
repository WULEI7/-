///////////////////////////////////////////////////////
//���뻷����Visual C++ 6.0��Easyx��	        //
///////////////////////////////////////////////////////
#include <graphics.h>   // ���� EasyX ͼ�ο⣬������.cppΪ��չ��
#include <windows.h>
#include <conio.h>
#include <math.h>
#define PI 3.1415926
int main(void)
{	/*����ԭ������*/
	void DralDial();                            /*������*/
	void DrawDecoration();                     // ��װ��
	void DrawHand(int hour, int minute, int second); //��ָ��
	initgraph(600, 600);           //��ʼ��600��600�Ļ�ͼ����
	setbkcolor(RGB(245, 247, 222));  //���ñ���ɫ
	cleardevice();                //�����Ļ
	DrawDecoration();            //��װ��
	DralDial();                   //������
	//������
	setcolor(RED);
	setfont(32, 0, "������κ");
	outtextxy(260, 130, "Clock");
	setwritemode(R2_XORPEN);   //��������ͼ��ʽ
	SYSTEMTIME t;             //������������浱ǰʱ��
	while(!kbhit()){
		GetLocalTime(&t);      //��ȡ��ǰʱ��
		DrawHand(t.wHour, t.wMinute, t.wSecond); //������
		Sleep(1000);
		DrawHand(t.wHour, t.wMinute, t.wSecond); //������
	}
	closegraph();  //�رջ�ͼ����
	return 0;
}
void DralDial()  /*������*/
{	int i,x1, y1, x2, y2, x3, y3, x4, y4, x5, y5; //��������ϵ����
	char rome[][3]= {"12","1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11" } ; //��������
	//���ĸ�Բ
	setcolor(LIGHTGRAY);
	circle(300, 300, 250);circle(300, 300, 30);
	circle(300, 300, 260);circle(300, 300, 270);
	for(i = 0; i < 59; i++){
		// ��60������
		setcolor(LIGHTGRAY);
		x1 = (int)(300 + (sin(i * PI / 30) * 250)); y1 = (int)(300 - (cos(i * PI / 30) * 250));
		x2 = (int)(300 + (sin(i * PI / 30) * 260)); y2 = (int)(300 - (cos(i * PI / 30) * 260));
		line(x1, y1, x2, y2);
		//��12��������
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
			//д��������
			setcolor(RED);
			setfont(24, 0, "����");
			outtextxy(x5 , y5, rome[i / 5]);
		}
	}
}
void DrawDecoration()  // ��װ��
{	double i; int x1, y1, x2, y2; //��������ϵ����
	//������ϵ��������ͼ��
	setcolor(RGB(250, 225, 222));
	for(i = 0; i < 10 * PI ; i += 0.4){
		x1 = (int)(300 + (250 * sin(2.4 * i)));
		y1 = (int)(300 - (250 * cos(2.4 * i)));
		x2 = (int)(300 + (250 * sin(2.4 * (i + 1))));
		y2 = (int)(300 - (250 * cos(2.4 * (i + 1))));
		line(x1, y1, x2, y2);
	}
}
void DrawHand(int hour, int minute, int second) //��ָ��
{	int xhour, yhour, xminute, yminute, xsecond, ysecond;	//��������ϵָ������
	xhour = (int)(130 * sin( hour * PI / 6 + minute * PI / 360 + second * PI / 1800));
	yhour = (int)(130 * cos( hour * PI / 6 + minute * PI / 360 + second * PI / 1800));
	xminute = (int)(145 * sin( minute  * PI / 30 + second * PI / 1800));
	yminute = (int)(145 * cos( minute  * PI / 30 + second * PI / 1800));
	xsecond = (int)(200 * sin( second * PI / 30));
	ysecond = (int)(200 * cos( second * PI / 30));
	//��ʱ��
	setlinestyle(PS_SOLID, NULL, 10);
	setcolor(LIGHTGRAY);
	line(300 + xhour, 300 - yhour, 300 -xhour / 6, 300 + yhour / 6);
	//������
	setlinestyle(PS_SOLID, NULL, 7);
	setcolor(RGB(222, 158, 107));
	line(300 + xminute, 300 - yminute, 300 -xminute / 4, 300 + yminute / 4);
	//������
	setlinestyle(PS_SOLID, NULL, 3);
	setcolor(RED);
	line(300 + xsecond, 300 - ysecond, 300 -xsecond / 3, 300 + ysecond / 3);
}
