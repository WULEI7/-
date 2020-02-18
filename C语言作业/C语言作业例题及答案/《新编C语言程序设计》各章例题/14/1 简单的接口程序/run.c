#include "dos.h"   /*程序运行环境TC2.0、Win-TC，程序名run.c */
#include "stdlib.h"
#include "stdio.h"
#define PORT 0                      /*com1串口*/
void SendFile(char *fname);           /*发送文件*/
void Send(int s);                     /*发送一个字节*/
void SendFileName(char *fname);      /*发送文件名*/
void ReceiveFile();                   /*接收文件*/
void GetFileName(char *f);            /*接收文件名*/
void InitPort(int port,unsigned char para); /*初始化端口*/
void SendPort(int port,char c);         /*端口发送*/
int ReadPort(int port);                /*读端口字节*/
int CheckState(int port);              /*检查端口状态*/
int Receive(int port,int *G);           /*接收一个字节*/
main(int argc,char *argv[])  /*主函数*/
{
if(argc<2){
printf("Please input R(receive) or S(sent) parametre:");
exit(1);
}
InitPort(PORT,231);
if(*argv[1]=='S') /*根据参数选择执行*/
SendFile(argv[2]);
else if(*argv[1]=='R')
ReceiveFile();
else{
printf("Error parametre.Please input again.");
exit(1);
}
}
void SendFile(char *fname)  /*发送文件*/
{
FILE *fp;
int ch,s;
if((fp=fopen(fname,"rb"))==NULL)
{
printf("Can't open the file.\n");
exit(1);
}
SendFileName(fname); /*发送文件名*/
do{                 /*循环发送文件内容 */
ch=(int)getc(fp);
if(ferror(fp)){
printf("Error reading file.\n"); break;
}
s=ch%16; /*取文件中一个字节的低4位*/
Send(s);
s=ch/16; /*取文件中一个字节的高4位*/
Send(s);
}while(!feof(fp));
s=48; /*发送文件结束信息*/
Send(s);
Send(s);
fclose(fp);
}
void Send(int s)  /*发送一个字节 */
{
int G;
SendPort(PORT,s);
G=ReadPort(PORT); /*等待握手信号*/
if(s!=G) s=s+16;
do{
SendPort(PORT,s);
G=ReadPort(PORT); /*等待握手信号*/
}while(s!=G);
}
void SendFileName(fname)  /*发送文件名*/
char *fname;
{
int s,ch;
printf("Now transmit the file.Please wait...");
while(*fname){
ch=(int)fname++;
s=ch%16;  /*取文件名中一个字节的低4位*/
Send(s);
s=ch/16;
Send(s);   /*取文件名中一个字节的高4位*/
}
s=32; /*发送文件名结束标志*/
Send(s);
Send(s);
}
void ReceiveFile()  /*接收文件*/
{   FILE *fp; char ch;
int G1,G2,G3;
char fname[15];
GetFileName(fname);
printf("Receiving file %s.\n",fname);
remove(fname);
if((fp=fopen(fname,"wb"))==NULL)
{
printf("Can't open output file.\n");
exit(1);
}
/*循环为检测每次接受的数据是否为新数据，如果不是，*/
/*则用此次接收的数据覆盖上次接收的数据*/
G1=ReadPort(PORT);
G2=Receive(PORT,&G1);
do{  /*循环直到发送文件内容结束*/
G3=Receive(PORT,&G2);
ch=(char)(G1%16+G2*16);/*恢复分开的数据，组合高4位和低4位*/
putc(ch,fp);
if(ferror(fp)){
printf("\nError writing file.");
exit(1);
}
G2=Receive(PORT,&G3);
G1=G3;
}while(G1/16!=48);
printf("\nTransmit finished.");
fclose(fp);
}
int Receive(int port,int *G)  /*接收一个字节*/
{
int GM;
SendPort(port,*G);
GM=ReadPort(port);
if(GM/16==0) return GM;
else if(GM/16==1){
do{
*G=GM;
SendPort(port,GM);
GM=ReadPort(port);
}while(GM/16==1); /*循环直到发送的是新数据*/
}
return GM;
}
void GetFileName(char *f)  /*接收文件名*/
{
int G1,G2,G3;
char ch;
G1=ReadPort(PORT);
G2=ReadPort(PORT);
do{
G3=Receive(PORT,&G2);
ch=(char)(G1%16+G2/16);
*f=ch;
*f++;
G2=Receive(PORT,&G3);
G1=G3;
}while(G1/16!=32);
printf("File name transmit finished.\n");
}
void InitPort(int port,unsigned char para)  /*初始化端口*/
{
union REGS reg;
reg.x.dx=port;
reg.h.ah=0;
reg.h.al=para;
int86(0x14, &reg, &reg);
}
void SendPort(int port,char c)  /*端口发送*/
{   union REGS reg;
reg.x.dx=port;
reg.h.al=c;
reg.h.ah=1;
int86(0x14,&reg, &reg);
if(reg.h.ah&128){
printf("\nSend mistakes!");
exit(1);
}
}
int ReadPort(int port)  /*读端口字节*/
{   union REGS reg;
while(!(CheckState(port)&256)){
if(kbhit()){/*如端口长期无数据可人为终止等待*/
printf("Press any key to exit.");
getch();
exit(1);
}
}
reg.x.dx=port;
reg.h.ah=2;
int86(0x14, &reg, &reg);
if(reg.h.ah&128){
printf("\nRead mistake!");
exit(1);
}
return reg.h.al;
}
int CheckState(int port)  /*检查端口状态*/
{
union REGS reg;
reg.x.dx=port;
reg.h.ah=3;
int86(0x14, &reg, &reg);
return reg.x.ax;
} 
