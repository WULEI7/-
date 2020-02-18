#include <stdio.h>
void main(void)
{ FILE *fp; char ch='0';
  fp = fopen("DUMMY.FIL", "w");  // 打开一个只写文件
  ch = fgetc(fp);  // 对一个只写文件去强制读操作（肯定要出错的）
  printf("%c\n",ch);
  if (ferror(fp))
  { printf("Error reading from DUMMY.FIL,error code:%d\n",ferror(fp));//显示错误信息
    clearerr(fp); // 错误或EOF指示复位，这样可以根据错误状态进行后续操作
    printf("After clear error, error code: %d\n",ferror(fp)); //error code is 0
  } 
  fputc('A',fp);   //清除错误后输出一个字符
  fclose(fp);
}
