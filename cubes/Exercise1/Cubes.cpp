#include <stdio.h>
/*
Addiert sämtliche Zahlen auf, die in der 2.Spalte stehen. Nutzt dafür Zeigerarithmetik.
@param *cube Der Pointer zum Anfang des Würfels.
@param sizeX Länge in "X"-Richtung
@param sizeY Länge in "Y"-Richtung
@param sizeZ Länge in "Z"-Richtung
@return Die Summe aller Zahlen aus der zweiten Spalte aller Matrixen.
*/
int sum2nd(int *cube,const int sizeX,const int sizeY,const int sizeZ) {
	int ret = 0;
	cube += 1;//Der Pointer muss auf dem zweiten Element der ersten Reihe der ersten Matrix stehen.
	for (int i = 0;i<sizeX*sizeY;i++,cube+=sizeZ) {
		ret += *cube;
	}
	return ret;
}
int main(void) {
	int cube1[3][2][4]={{{1,2,3,4}},{{2,3},{4,6,8,10}},{{3,4,5,6},{6,8,10}}};
	int cube2[2][3][3]={{{9,8,7},{6},{5,4}},{{3,2},{1,2,3},{4}}};
	/*for(char i=0;i<3;i++) {
		for (char j=0;j<2;j++) {
			for (char k=0;k<4;k++) {
				printf("Adresse=%X,i=%d,j=%d,k=%d,Wert=%d\n",&cube1[i][j][k],i,j,k,cube1[i][j][k]);
				//Der komplette Würfel ist in einem Block: Keine freien Plätze zwischen den Elementen.
			}
		}
	}*/
	printf("%d\n",sum2nd(&cube1[0][0][0],3,2,4));
	printf("%d\n",sum2nd(&cube2[0][0][0],2,2,3));
	return 0;
}