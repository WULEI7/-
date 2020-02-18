#include <stdio.h>
#define PI 3.14159
int main()
{  float h,r,ly,sy,sq,vq,vz;
   printf("请输入圆半径r，圆柱高h：\n");
   scanf("%f%f",&r,&h);
   ly=2*PI*r; 
   sy=PI*r*r; 
   sq=4*PI*r*r;
   vq=4.0/3*PI*r*r*r;  
   vz=PI*h*r*r;
   printf("圆周长为：%.2f\n",ly); 
   printf("圆面积为：%.2f\n",sy);
   printf("圆球表面积为：%.2f\n",sq); 
   printf("圆球体积为：%.2f\n",vq);
   printf("圆柱体积为：%.2f\n",vz);
   return 0;
}
