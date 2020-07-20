//Laboratorio cuadro mágico
/*
Plantear un programa que permita GENERAR un cuadrado magico de 3*3 con los datos numericos enteros del 1 al 9 donde la suma por filas columnas o diagonales sea = 15.
El programa debe mostrar el cuadrado magico generado teniendo en cuenta todas las posibilidades.
Se debe generar en forma aleatoria.
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//DECLARA VARIABLES
int i=0,j=0,A[3][3];

//DECLARA PROTOTIPO
int rand_even();

int main()
{
	//DIAGONAL \    ***
	A[1][1]=5;//ASIGNA EL CENTRO
	A[0][0]=rand_even();//NUMERO PAR ALEATORIO en esquina superior izquierda (LLAMADO A LA FUNCION AUXILIAR)
	A[2][2]=15-A[1][1]-A[0][0];//DIFERENCIA PARA HALLAR EL NUMERO RESTANTE en esquina inferior derecha
	
	//DIAGONAL /    ***
	do{
		A[0][2]=rand_even();
	}while(A[0][2]==A[0][0] || A[0][2]==A[2][2]);//NUMERO PAR ALEATORIO DIFERENTE A LOS ESPACIOS YA ASIGNADOS en esquina superior derecha
	A[2][0]=15-A[1][1]-A[0][2];//DIFERENCIA PARA HALLAR EL NUMERO RESTANTE en esquina inferior izquierda
	
	//HORIZONTAL UP
	A[0][1]=15-A[0][0]-A[0][2];//DIFERENCIA PARA HALLAR EL NUMERO RESTANTE en centro superior
	
	//HORIZONTAL DOWN
	A[2][1]=15-A[2][0]-A[2][2];//DIFERENCIA PARA HALLAR EL NUMERO RESTANTE en centro inferior
	
	//VERTICAL LEFT
	A[1][0]=15-A[0][0]-A[2][0];//DIFERENCIA PARA HALLAR EL NUMERO RESTANTE en centro izquierdo
	
	//VERTICAL RIGHT
	A[1][2]=15-A[0][2]-A[2][2];//DIFERENCIA PARA HALLAR EL NUMERO RESTANTE en centro derecho
	
	//OUT
	cout<<"CUADRO MAGICO 3X3"<<endl<<endl;
	//Recorremos la matriz...
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{cout<<A[i][j]<<"  ";}//y la vamos imprimiendo
		cout<<endl<<endl;
	}
	cout<<endl;
	
	system("pause");
	return 0;
}

//FUNCIONES AUXILIARES
int rand_even()
{
	int r;
	
	do{
		srand (time(NULL));
		r=rand() % 9+ 1;//generar un aleaqtorio entre 1 y 9
	}while(r%2==1);//hasta que el numero sea par
	
	return r;
}


