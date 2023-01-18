#include <stdio.h>
#define N 26
#define MAX 2048

int main()
	{
	int vector[N];
	int matriz[N][N];
	int cubo[N][N][N];
	char letra;
	char buffer[MAX];
	int i,j,k;
	
	for(i=0; i<N; i++)
		{
		vector[i]=0;
		}
	
	fgets(buffer,MAX,stdin);
	
	puts("");
	puts("Frecuencia por caracteres:");
	
	for(i=0; buffer[i]!=0 ;i++)
		{
		printf("%i ",(buffer[i]-1) & 0x1f);
		vector[(buffer[i]-1) & 0x1f]++;
		}
	puts("");
	
	for(i=0; i<N; i++)
		{
		printf("%2c ", (i+1) | 0x40);
		}
	puts("");

	for(i=0; i<N; i++)
		{
		printf("%2i ",vector[i]);
		}
	puts("");
	
	
	puts("");
	puts("frecuencia por digramas:");
	
	for(i=0; i<N; i++)
		{
		for(j=0; j<N; j++)
			{
			matriz[i][j]=0;
			}
		}
	
	
	for(i=0; buffer[i+1]!=0 ;i++)
		{
//		printf("%i ",buffer[i] & 0x1f);
		matriz[(buffer[i]-1) & 0x1f][((buffer[i+1]-1) & 0x1f)]++;
		}

	
	for(i=0; i<N; i++)
		{
		printf("%c.- ", (i+1) | 0x40);
		for(j=0; j<N; j++)
			{
			if(matriz[i][j]>0)
				{
				printf("%c%c:%i ",(i+1) | 0x40,(j+1) | 0x40,matriz[i][j]);
//				printf("%2i ",matriz[i][j]);
				}
//			else
				{
//				printf("___");
				}
			}
		puts("");
		}
	



	puts("");
	puts("frecuencia por trigramas:");
	
	for(i=0; i<N; i++)
		{
		for(j=0; j<N; j++)
			{
			for(k=0; k<N; k++)
				{
				cubo[i][j][k]=0;
				}
			}
		}
	
	
	for(i=0; buffer[i]!=0 ;i++)
		{
//		printf("%i ",buffer[i] & 0x1f);
		cubo[(buffer[i]-1) & 0x1f][(buffer[i+1]-1) & 0x1f][(buffer[i+2]-1) & 0x1f]++;
		}

	
	for(i=0; i<N; i++)
		{
		printf("%c.- ", (i+1) | 0x40);
		for(j=0; j<N; j++)
			{
			for(k=0; k<N; k++)
				{
				if(cubo[i][j][k]>0)
					{
					printf("%c%c%c:%i ",(i+1) | 0x40,(j+1) | 0x40,(k+1) | 0x40,cubo[i][j][k]);
//					printf("%2i ",matriz[i][j]);
					}
//				else
					{
//					printf("___");
					}
				}
			}
		puts("");
		}
	


		
	return(0);
	}
