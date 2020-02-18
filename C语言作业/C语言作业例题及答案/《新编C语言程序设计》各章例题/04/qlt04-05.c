main(){
int i=123;char c='A'; float f=3.1415;double d=1234.567890;
long l=1234567890;
printf("%d,%ld,%lo,%lx,%lu\n",l,l,l,l,l);   /*以下多种类型多格式输出*/
printf("%-d %-f %-e %-f %-e\n",i,f,f,d,d);
printf("%+d %+f %+e %+f %+e\n",i,f,f,d,d);
printf("% d % f % e % f % e\n",-i,-f,f,d,d);
printf("%#o %#x %#e %#f %#g\n",i,i,f,f,f);
printf("%#e %#f %#g\n",d,d,d);
printf("\n%5d,%10f,%15e\n",i,f,f);
printf("%-5d,%-10f,%-15e\n",i,f,f);
printf("%.3f,%.4e,%.5g\n",f,d,d);
printf("%10.3f,%15.4e,%20.5g\n",f,f,d);
printf("%hd,%ho,%hx,%hu,%hi,%ld,%lo,%lx,%lu,%li\n",i,i,i,i,i,i,l,l,l,l);
printf("%lf,%le,%lg\n",f,f,f);
printf("%-10.3lf,%-20.5lg,%+15.4le\n",f,d,d);
printf("%-10.3lf,%-20.5lg,%+15.4le\n",f*d,f*d,f*d);
printf("%5.2s,%-7.3s,%s,%3s\n","China","China","China","China");
}
