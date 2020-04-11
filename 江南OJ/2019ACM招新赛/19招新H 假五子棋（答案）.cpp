#include "cstdio"
int n, m, p; 
int a[105][105]={}; 
int flag = 0; 
int main() 
{ 
	int x, y; 
	int i, j, k; 
	scanf("%d%d%d", &n, &m, &p); 
	for (i = 1; i <= p; ++i) 
	{ 
 		scanf("%d%d", &x, &y); 
 		if (i % 2 == 1) 
  			a[x][y] = 1; 
 		else 
  			a[x][y] = 2; 
	} 
	if (m - 4 >= 1) 
 		for (i = 1; i <= n; ++i) 
  			for (j = 1; j <= m - 4; ++j) 
  			{ 
   				for (k = j + 1; k <= j + 4; ++k) 
    					if (a[i][k] != a[i][j]) 
     						break; 
   				if (k == j + 5 && a[i][j] == 1) 
    					flag = 1; 
   				if (k == j + 5 && a[i][j] == 2) 
    					flag = 2; 
  			} 
	if (n - 4 >= 1) 
 		for (i = 1; i <= n - 4; ++i) 
  			for (j = 1; j <= m; ++j) 
  			{ 
   				for (k = i + 1; k <= i + 4; ++k) 
    					if (a[k][j] != a[i][j]) 
     						break; 
   				if (k == i + 5 && a[i][j] == 1) 
    					flag = 1; 
   				if (k == i + 5 && a[i][j] == 2) 
    					flag = 2; 
  			} 
	if(flag == 0) 
 		printf("no winner"); 
	if(flag == 1) 
 		printf("black"); 
	if(flag == 2) 
 		printf("white"); 
	return 0; 
}
