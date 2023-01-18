#include <stdio.h>
#include <string.h>

int main()
	{
	char cadena[2048];
	char pausa[2];
	int lenCad;
	int i=11;	//19^
	int j,k;
	int y;
	
	scanf("%s",cadena);
	lenCad = strlen(cadena);
	
	for(j=0;j<lenCad;j++)
		{
		cadena[j] = (cadena[j] & 0x1f)-1;
		}
	
	for(i=1;i<26 && i!= 13;i++)
		{
		for(j=0;j<26;j++)
			{
//			j=4;
			printf("[%02i,%02i]",i,j);
			for(k=0;k<lenCad;k++)
				{
				y = ((cadena[k]-j+26)*i) % 26;
				printf("%c",(y+1) | 64 | 32);
				}
			puts("");
			}
//		scanf("%s",pausa);
		}
	
	return(0);
	}
