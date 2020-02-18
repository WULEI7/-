#include <stdio.h>

int main()
{
	int bar[26]={0},i,j,temp,max;
	char ch;

	while( (ch=getchar())!=EOF )
	{
		if(ch>='a'&&ch<='z')
			bar[ch-'a']++;
	}

	for(i=0;i<26;i++)
	{
		max=i;
		for(j=i+1;j<26;j++)
			if(bar[max]<bar[j])
				max=j;
		if(max!=i)
		{
			temp=bar[max];
			bar[max]=bar[i];
			bar[i]=temp;
		}
	}

	max=bar[0];
	while(max>0)
	{
		for(i=0;i<26;i++)
			if(bar[i]>0)
			{
				if(bar[i]>=max)
					printf("#");
				else
					printf(" ");
			}
		printf("\n");
		max--;
	}

	return 0;

}
