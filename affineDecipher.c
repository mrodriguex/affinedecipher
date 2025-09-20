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
