#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(){
	int n, i=0, x;
	char str[10000];

	scanf("%d\n", &n);

	while(i < n){
		
		int j=0;
		scanf(" %[^\n]s\n", str);

		x = strlen(str);

		while(j < x){
			int k;
			if(str[j] >= 'a' && str[j] <= 'z'){
				str[j] = str[j] + 3;
			}else if(str[j] >= 'A' && str[j] <= 'Z'){
				str[j] = str[j] + 3;
			}

		j++;

		}

		char c;
		int m;

		for(m=0; m<x/2;m++){
			c = str[m];
			str[m] = str[x-1-m];
			str[x-1-m] = c;
		}
		int a, b;
		
		for (a = x/2; a < x; a++)
		{
			str[a] = str[a] - 1;

		}
		printf("%s\n", str);
		
	i++;
	}


   return 0;
}