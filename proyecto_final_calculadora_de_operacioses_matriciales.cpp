#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void pedir_datos_suma();
void mostrar_matrices_suma(float**,float**,int,int,int,int);
void operacion_suma_de_matrices(float**,float**,float**,int,int,int,int);

void pedir_datos_resta();
void mostrar_matrices_resta(float**,float**,int,int,int,int);
void operacion_resta_de_matrices(float**,float**,float**,int,int,int,int);

void pedir_datos_transpuesta();
void mostrar_matriz_transpuesta(float**,int,int);

void pedir_datos_matriz_por_escalar();
void mostrar_matriz_por_escalar(float**,int,int);

void pedir_datos__multiplicacion_matrices();
void mostrar_matriz_por_matriz(float**,float**,int,int,int,int);
void operacion_multiplicacion_de_matrices(float**,float**,float**,int,int,int,int);

void pedir_datos_determinante();
void mostrar_matriz_original_determinante(float**,int);
float calculo_determinante(float**,int);
float calculo_cofactor(float**,int,int,int);

void pedir_datos_inverza();
void mostrar_matriz_original_inversa(float**,int);
void operacion_inversa_de_una_matriz(float**,float**,int);
void mostrar_matriz_inversa(float**,int);

int f,c,f2,c2;
float **mat,**mat2,**mat3,aux,pivote,esc,opc;

int main(){
	
	cout<<"\n\t\t\t\tPor favor elija una de las operaciones a calcular"<<endl;
	cout<<"\n\n\t\t\t\t\t1. Suma de matrices"<<endl;
	cout<<"\t\t\t\t\t2. Resta de matrices"<<endl;
	cout<<"\t\t\t\t\t3. Transpuesta de una matriz"<<endl;
	cout<<"\t\t\t\t\t4. Multiplicacion por un escalar"<<endl;
	cout<<"\t\t\t\t\t5. Multiplicacion de matrices"<<endl;
	cout<<"\t\t\t\t\t6. Determinante de una matriz"<<endl;
	cout<<"\t\t\t\t\t7. Inversa de una matriz"<<endl;
	cout<<"\n\n\t\t\t\t Que operacion deseas realizar ";cin>>opc;
	
	while( opc<=0 || opc>=8 )
	{
		cout<<"\n\n\t\t\t\tDame un nunmero que coinsida con su operacion respectiva.";cin>>opc;
	}
	
	if(opc==1)
	{
    pedir_datos_suma();
	mostrar_matrices_suma(mat,mat2,f,c,f2,c2);
	operacion_suma_de_matrices(mat,mat2,mat3,f,c,f2,c2);
    }
    
    if(opc==2)
    {
    pedir_datos_resta();
	mostrar_matrices_resta(mat,mat2,f,c,f2,c2);
	operacion_resta_de_matrices(mat,mat2,mat3,f,c,f2,c2);
    }
    
    if(opc==3)
	{
    pedir_datos_transpuesta();
    mostrar_matriz_transpuesta(mat,f,c);
    }
    
    if(opc==4)
    {
    pedir_datos_matriz_por_escalar();
    mostrar_matriz_por_escalar(mat,f,c);
    }
	
	if(opc==5)
	{  
	pedir_datos__multiplicacion_matrices();
	mostrar_matriz_por_matriz(mat,mat2,f,c,f2,c2);
	operacion_multiplicacion_de_matrices(mat,mat2,mat3,f,c,f2,c2);
    }
    
    if(opc==6)
	{  
	pedir_datos_determinante();
	mostrar_matriz_original_determinante(mat,f);
	cout << "\nEl determinante es: " << calculo_determinante(mat,f) << endl;
    }
	
	if(opc==7)
	{  
	pedir_datos_inverza();
	mostrar_matriz_original_inversa(mat,f);
	operacion_inversa_de_una_matriz(mat,mat2,f);
	mostrar_matriz_inversa(mat2,f);
	
    }
	
	  
	for(int i=0;i<f;i++)
	{
		delete[] mat[i];
	}
	
	delete[] mat;
	
	for(int i=0;i<f2;i++)
	{
		delete[] mat2[i];
	}
	
	delete[] mat2;

    for(int i=0;i<f;i++)
	{
		delete[] mat3[i];
	}
	
	delete[] mat3;
		
	getch;
	return 0;
}


void pedir_datos_suma(){
	
	cout<<"\n\n\n\n\n\n\n\n\nEstas realizando la suma de matrices."<<endl;
	cout<<"\n\nDigita el numero de filas de tu primera matriz."<<endl;
	cin>>f;
	cout<<"\nDigita el numero de columnas  de tu primera matriz."<<endl;
	cin>>c;
	
	cout<<"\n\nDigita el numero de filas de tu segunda matriz."<<endl;
	cin>>f2;
	cout<<"\nDigita el numero de columnas  de tu segunda matriz."<<endl;
	cin>>c2;
	
	if(f==f2 && c==c2 )
   {

	mat= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat[i] = new float [c];
	}
	
	cout<<"\n\nRellenando la primera matriz."<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz."<<endl;
			cin>>*(*(mat+i)+j);
			
		}
	}
	
	mat2= new float *[f2];
	for(int i=0;i<f2;i++)
	{
		mat2[i] = new float [c2];
	}
	
	cout<<"\n\nRellenando la segunda matriz."<<endl;
	for(int i=0;i<f2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz."<<endl;
			cin>>*(*(mat2+i)+j);
			
		}
	}
   }
   else
   {
   	cout<<"\n\nNo podemos realizar la suma de matrizes de orden diferente."<<endl;
   }
	
}

void mostrar_matrices_suma(float **mat,float **mat2,int f,int c,int f2,int c2){
	
	if(f==f2 && c==c2 )
   {
   	
	cout<<"\n\n\nMostrando la primera matriz."<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat+i)+j)<<"  ";
		}
		cout<<"\n";
    }
    
    cout<<"\n\n\nMostrando la segunda matriz."<<endl;
	for(int i=0;i<f2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<*(*(mat2+i)+j)<<"  ";
		}
		cout<<"\n";
	}
	
   }
   
}

void operacion_suma_de_matrices(float **mat,float **mat2,float **mat3,int f,int c,int f2,int c2){
	
	if(f==f2 && c==c2 )
   {
	mat3= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat3[i] = new float [c];
	}
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			*(*(mat3+i)+j)=0;
		}
		cout<<"\n";
    }
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			*(*(mat3+i)+j)=(*(*(mat2+i)+j))+(*(*(mat+i)+j));
		}
	}
	
	cout<<"\n\t Resultado de la suma de matrices.\n"<<endl;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat3+i)+j)<<"  ";
		}
		cout<<"\n";
	}
   }
}

void pedir_datos_resta(){
	cout<<"\n\n\n\n\n\n\n\n\nEstas realizando la resta de matrices."<<endl;
	cout<<"\n\nDigita el numero de filas de tu primera matriz."<<endl;
	cin>>f;
	cout<<"\nDigita el numero de columnas  de tu primera matriz."<<endl;
	cin>>c;
	
	cout<<"\n\nDigita el numero de filas de tu segunda matriz."<<endl;
	cin>>f2;
	cout<<"\nDigita el numero de columnas  de tu segunda matriz."<<endl;
	cin>>c2;
	
	if(f==f2 && c==c2 )
   {

	mat= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat[i] = new float [c];
	}
	
	cout<<"\n\nRellenando la primera matriz."<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz."<<endl;
			cin>>*(*(mat+i)+j);
		}
	}
	
	mat2= new float *[f2];
	for(int i=0;i<f2;i++)
	{
		mat2[i] = new float [c2];
	}
	
	cout<<"\n\nRellenando la segunda matriz."<<endl;
	for(int i=0;i<f2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz."<<endl;
			cin>>*(*(mat2+i)+j);
			
		}
	}
   }
   else
   {
   	cout<<"\n\nNo podemos realizar la resta de matrizes de orden diferente."<<endl;
   }
	
}

void mostrar_matrices_resta(float **mat,float **mat2,int f,int c,int f2,int c2){
	
	if(f==f2 && c==c2 )
   {
   	
	cout<<"\n\n\nMostrando la primera matriz."<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat+i)+j)<<"  ";
		}
		cout<<"\n";
    }
    
    cout<<"\n\n\nMostrando la segunda matriz."<<endl;
	for(int i=0;i<f2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<*(*(mat2+i)+j)<<"  ";
		}
		cout<<"\n";
	}
	
   }
   
}

void operacion_resta_de_matrices(float **mat,float **mat2,float **mat3,int f,int c,int f2,int c2){
	
	if(f==f2 && c==c2 )
   {
	mat3= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat3[i] = new float [c];
	}
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			*(*(mat3+i)+j)=0;
		}
		cout<<"\n";
    }
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			*(*(mat3+i)+j)=(*(*(mat+i)+j))-(*(*(mat2+i)+j));
		}
	}
	
	cout<<"\n\t Resultado de la resta de matrices.\n"<<endl;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat3+i)+j)<<"  ";
		}
		cout<<"\n";
	}
   }
}

void pedir_datos_transpuesta(){
	cout<<"\n\n\n\n\n\n\n\n\nEstas realizando la transpuesta de una matriz."<<endl;
	cout<<"\n\nDigita el numero de filas de tu  matriz."<<endl;
	cin>>f;
	cout<<"\nDigita el numero de columnas  de tu matriz."<<endl;
	cin>>c;

	mat= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat[i] = new float [c];
	}
	
	cout<<"\n\nRellenando la matriz."<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz"<<endl;
			cin>>*(*(mat+i)+j);
			
		}
	}
	
}

void mostrar_matriz_transpuesta(float **mat,int f,int c){
	
	cout<<"\n\n\nMostrando la matriz original."<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat+i)+j)<<"  ";
		}
		cout<<"\n";
    }
    
    if(f==c)
   {
    cout<<"\n\n\nMostrando la matriz transpuesta."<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat+j)+i)<<"  ";
		}
		cout<<"\n";
    }  
   }
   else
   {
   	cout<<"\n\n\nMostrando la matriz transpuesta."<<endl;
   	for(int i=0;i<c;i++)
	{
		for(int j=0;j<f;j++)
		{
			cout<<*(*(mat+j)+i)<<"  ";
		}
		cout<<"\n";
    }  
   }
}

void pedir_datos_matriz_por_escalar(){
	cout<<"\n\n\n\n\n\n\n\n\nEstas realizando la multiplicacion  de una matriz por un escalar."<<endl;
	cout<<"\n\nDigita el numero de filas de tu primera matriz."<<endl;
	cin>>f;
	cout<<"\nDigita el numero de columnas  de tu primera matriz."<<endl;
	cin>>c;
	
	cout<<"Dame un escalar por el cual mulktiplicaras la mariz."<<endl;
    cin>>esc;
	
	mat= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat[i] = new float [c];
	}
	
	cout<<"\n\nRellenando la matriz"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz"<<endl;
			cin>>*(*(mat+i)+j);
		}
	}
	
}

void mostrar_matriz_por_escalar(float ** mat,int f,int c){
	
	cout<<"\n\n La matriz resultante es:"<<endl;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
		    cout<<(*(*(mat+i)+j))*(esc)<<"  ";
		}
		cout<<"\n";
	}
	
}

void pedir_datos__multiplicacion_matrices(){
	
	cout<<"\n\n\n\n\n\n\n\n\nEstas realizando la multiplicacion de matrices"<<endl;
	cout<<"\n\nDigita el numero de filas de tu primera matriz"<<endl;
	cin>>f;
	cout<<"\nDigita el numero de columnas  de tu primera matriz"<<endl;
	cin>>c;
	
	cout<<"\n\nDigita el numero de filas de tu segunda matriz"<<endl;
	cin>>f2;
	cout<<"\nDigita el numero de columnas  de tu segunda matriz"<<endl;
	cin>>c2;
	
	mat= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat[i] = new float [c];
	}
	
	cout<<"\n\nRellenando la primera matriz"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz"<<endl;
			cin>>*(*(mat+i)+j);
			
		}
	}
	
	mat2= new float *[f2];
	for(int i=0;i<f2;i++)
	{
		mat2[i] = new float [c2];
	}
	
	cout<<"\n\nRellenando la segunda matriz"<<endl;
	for(int i=0;i<f2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz"<<endl;
			cin>>*(*(mat2+i)+j);
			
		}
	}
   
}

void mostrar_matriz_por_matriz(float **mat,float **mat2,int f,int c,int f2,int c2){
	
	cout<<"\n\n\nMostrando la primera matriz"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat+i)+j)<<"  ";
		}
		cout<<"\n";
    }
    
    cout<<"\n\n\nMostrando la segunda matriz"<<endl;
	for(int i=0;i<f2;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<*(*(mat2+i)+j)<<"  ";
		}
		cout<<"\n";
	}
	
}

void operacion_multiplicacion_de_matrices(float **mat,float **mat2,float **mat3,int f,int c,int f2,int c2){
	
	if(f==f2 && c==c2)
   {
	
	mat3= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat3[i] = new float [c];
	}
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			*(*(mat3+i)+j)=0;
			for(int k=0;k<f;k++)
			{
				*(*(mat3+i)+j)=(*(*(mat+k)+j)) * (*(*(mat2+i)+k)) + (*(*(mat3+i)+j));
			}
		}
	}
	
	cout<<"\n Resultado de la multiplicacion de matrices\n"<<endl;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<*(*(mat3+i)+j)<<"  ";
		}
		cout<<"\n";
	}
   }
   
   if(c==f2)
   {
   	mat3= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat3[i] = new float [c2];
	}
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c2;j++)
		{
			*(*(mat3+i)+j)=0;
			for(int k=0;k<c;k++)
			{
				*(*(mat3+i)+j)=(*(*(mat+i)+k)) * (*(*(mat2+k)+j)) + (*(*(mat3+i)+j));
			}
		}
	}
	
	cout<<"\n Resultado de la multiplicacion de matrices\n"<<endl;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c2;j++)
		{
			cout<<*(*(mat3+i)+j)<<"  ";
		}
		cout<<"\n";
	}
   }
   
}

void pedir_datos_determinante(){
	cout<<"\n\n\n\n\n\n\n\n\nEstas realizando el determinante de una matriz"<<endl;
	cout<<"\n\nLa matriz puede tener un orden max de 8"<<endl;
	cout<<"\nDigita el orden matriz"<<endl;
	cin>>f;
	
	while( f<=0 || f>=9 )
	{
		cout<<"\n\nIngresa otro orden.";cin>>f;
		
	}
	
	mat= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat[i] = new float [f];
	}
	
	if(f>0 && f<8)
   {	
	cout<<"\n\nRellenando la matriz"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<f;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz"<<endl;
			cin>>*(*(mat+i)+j);
		}
	}
   }
   else
   {
   	   cout<<"\n\nnNo podemos obtener el determinante de esta matriz"<<endl;
   }
   
}

void mostrar_matriz_original_determinante(float **mat,int f){
	
	if(f>0 && f<8)
   {	
	cout<<"\n\n\nMostrando la matriz"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<f;j++)
		{
			cout<<*(*(mat+i)+j)<<"  ";
		}
		cout<<"\n";
    }
   }
    
}

float calculo_determinante(float **mat,int f){
	
	int det = 0;
	
	if (f == 1)
	{
      det = (*(*(mat+0)+0));
    } 
    else 
	{
      for (int j = 0; j < f; j++) 
	  {
         det += (*(*(mat+0)+j)) * calculo_cofactor(mat, f, 0, j);
      }
   }
   
   return det;
	
}

float calculo_cofactor(float **mat,int f,int f2,int c2){
	
   float **mat2;
   int n = f - 1;
   
   mat2= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat2[i] = new float [f];
	}
   
   int x = 0;
   int y = 0;
   
   for (int i = 0; i < f; i++)
    {
      for (int j = 0; j < f; j++) 
	  {
         if (i != f2 && j != c2) 
		 {
            *(*(mat2+x)+y) = *(*(mat+i)+j);
            y++;
            if (y >= n) 
		   {
               x++;
               y = 0;
           }
         }
      }
   }
   
   return pow(-1, f2 + c2) * calculo_determinante(mat2,n);
}


void pedir_datos_inverza(){
	cout<<"\n\n\n\n\n\n\n\n\nEstas realizando la inverza de matrices"<<endl;
	cout<<"\n\nDigita el tamaño de tu  matriz"<<endl;
	cin>>f;

	mat= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat[i] = new float [f];
	}
	
	mat2= new float *[f];
	for(int i=0;i<f;i++)
	{
		mat2[i] = new float [f];
	}
	
	cout<<"\n\nRellenando la matriz"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<f;j++)
		{
			cout<<"Dijite el elemento ["<<i<<"] ["<<j<<"] de la matriz"<<endl;
			cin>>*(*(mat+i)+j);
			if(i==j)
			{
				(*(*(mat2+i)+j))=1;
			}
			else
			{
				(*(*(mat2+i)+j))=0;
			}
		}
	}
	
}

void mostrar_matriz_original_inversa(float **mat,int f){
    
    cout<<"\n\n\nMostrando la matriz original"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<f;j++)
		{
			cout<<(*(*(mat+i)+j))<<"  ";
		}
		cout<<"\n";
    }

}

void operacion_inversa_de_una_matriz(float **mat,float **mat2,int f){
	
	for(int i=0;i<f;i++)
	{
		pivote=(*(*(mat+i)+i));                                                             
		for(int j=0;j<f;j++)
		{
			(*(*(mat+i)+j))=(*(*(mat+i)+j))/pivote;
			(*(*(mat2+i)+j))=(*(*(mat2+i)+j))/pivote;
		}
		for(int k=0;k<f;k++)
		{
			if(i!=k)
			{
				aux=(*(*(mat+k)+i));
				for(int w=0;w<f;w++)
				{
					(*(*(mat+k)+w))=(*(*(mat+k)+w))-aux*(*(*(mat+i)+w));
					(*(*(mat2+k)+w))=(*(*(mat2+k)+w))-aux*(*(*(mat2+i)+w));;
				}
			}
		}
	}
	
}

void mostrar_matriz_inversa(float **mat2,int f){
	
    cout<<"\n\n\nMostrando la matriz inversa"<<endl;
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<f;j++)
		{
			cout<<(*(*(mat2+i)+j))<<"  ";
		}
		cout<<"\n";
    }

}
