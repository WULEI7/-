#include "dos.h"   /*�������л���TC2.0��Win-TC��������run.c */
#include "stdlib.h"
#include "stdio.h"
#define PORT 0                      /*com1����*/
void SendFile(char *fname);           /*�����ļ�*/
void Send(int s);                     /*����һ���ֽ�*/
void SendFileName(char *fname);      /*�����ļ���*/
void ReceiveFile();                   /*�����ļ�*/
void GetFileName(char *f);            /*�����ļ���*/
void InitPort(int port,unsigned char para); /*��ʼ���˿�*/
void SendPort(int port,char c);         /*�˿ڷ���*/
int ReadPort(int port);                /*���˿��ֽ�*/
int CheckState(int port);              /*���˿�״̬*/
int Receive(int port,int *G);           /*����һ���ֽ�*/
main(int argc,char *argv[])  /*������*/
{
if(argc<2){
printf("Please input R(receive) or S(sent) parametre:");
exit(1);
}
InitPort(PORT,231);
if(*argv[1]=='S') /*���ݲ���ѡ��ִ��*/
SendFile(argv[2]);
else if(*argv[1]=='R')
ReceiveFile();
else{
printf("Error parametre.Please input again.");
exit(1);
}
}
void SendFile(char *fname)  /*�����ļ�*/
{
FILE *fp;
int ch,s;
if((fp=fopen(fname,"rb"))==NULL)
{
printf("Can't open the file.\n");
exit(1);
}
SendFileName(fname); /*�����ļ���*/
do{                 /*ѭ�������ļ����� */
ch=(int)getc(fp);
if(ferror(fp)){
printf("Error reading file.\n"); break;
}
s=ch%16; /*ȡ�ļ���һ���ֽڵĵ�4λ*/
Send(s);
s=ch/16; /*ȡ�ļ���һ���ֽڵĸ�4λ*/
Send(s);
}while(!feof(fp));
s=48; /*�����ļ�������Ϣ*/
Send(s);
Send(s);
fclose(fp);
}
void Send(int s)  /*����һ���ֽ� */
{
int G;
SendPort(PORT,s);
G=ReadPort(PORT); /*�ȴ������ź�*/
if(s!=G) s=s+16;
do{
SendPort(PORT,s);
G=ReadPort(PORT); /*�ȴ������ź�*/
}while(s!=G);
}
void SendFileName(fname)  /*�����ļ���*/
char *fname;
{
int s,ch;
printf("Now transmit the file.Please wait...");
while(*fname){
ch=(int)fname++;
s=ch%16;  /*ȡ�ļ�����һ���ֽڵĵ�4λ*/
Send(s);
s=ch/16;
Send(s);   /*ȡ�ļ�����һ���ֽڵĸ�4λ*/
}
s=32; /*�����ļ���������־*/
Send(s);
Send(s);
}
void ReceiveFile()  /*�����ļ�*/
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
/*ѭ��Ϊ���ÿ�ν��ܵ������Ƿ�Ϊ�����ݣ�������ǣ�*/
/*���ô˴ν��յ����ݸ����ϴν��յ�����*/
G1=ReadPort(PORT);
G2=Receive(PORT,&G1);
do{  /*ѭ��ֱ�������ļ����ݽ���*/
G3=Receive(PORT,&G2);
ch=(char)(G1%16+G2*16);/*�ָ��ֿ������ݣ���ϸ�4λ�͵�4λ*/
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
int Receive(int port,int *G)  /*����һ���ֽ�*/
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
}while(GM/16==1); /*ѭ��ֱ�����͵���������*/
}
return GM;
}
void GetFileName(char *f)  /*�����ļ���*/
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
void InitPort(int port,unsigned char para)  /*��ʼ���˿�*/
{
union REGS reg;
reg.x.dx=port;
reg.h.ah=0;
reg.h.al=para;
int86(0x14, &reg, &reg);
}
void SendPort(int port,char c)  /*�˿ڷ���*/
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
int ReadPort(int port)  /*���˿��ֽ�*/
{   union REGS reg;
while(!(CheckState(port)&256)){
if(kbhit()){/*��˿ڳ��������ݿ���Ϊ��ֹ�ȴ�*/
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
int CheckState(int port)  /*���˿�״̬*/
{
union REGS reg;
reg.x.dx=port;
reg.h.ah=3;
int86(0x14, &reg, &reg);
return reg.x.ax;
} 
