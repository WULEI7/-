#include <stdio.h>
void main(void)
{ FILE *fp; char ch='0';
  fp = fopen("DUMMY.FIL", "w");  // ��һ��ֻд�ļ�
  ch = fgetc(fp);  // ��һ��ֻд�ļ�ȥǿ�ƶ��������϶�Ҫ����ģ�
  printf("%c\n",ch);
  if (ferror(fp))
  { printf("Error reading from DUMMY.FIL,error code:%d\n",ferror(fp));//��ʾ������Ϣ
    clearerr(fp); // �����EOFָʾ��λ���������Ը��ݴ���״̬���к�������
    printf("After clear error, error code: %d\n",ferror(fp)); //error code is 0
  } 
  fputc('A',fp);   //�����������һ���ַ�
  fclose(fp);
}
