/*
 * Affine Decipher - descifrador de cifrado Afín
 * Copyright (C) 2025 Manuel Rodríguez Camacho
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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
