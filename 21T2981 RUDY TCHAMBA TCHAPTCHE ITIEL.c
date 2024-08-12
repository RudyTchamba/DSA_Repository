#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX 4
void echello(float A[3][3],int k)
{
	int i , j ;
		int a=0,b=0;
		float pivot;
	float dep;
	pivot=A[0][0];
	while(a<2&&pivot!=0)
	{	
		for (i = a+1; i < k; i++)
		{
			dep=A[i][a]/pivot;
			if (A[i][a]*pivot > 0)
			{
				
				for (j = b; j < k; j++)
				{
					A[i][j] = -(dep) * A[a][j] + A[i][j];		
				}
			}
			else
			{
	 			for (j = b; j < k; j++)
				{
					A[i][j] = -(dep) * A[a][j] + A[i][j];
					
				}
			}
		}
		a++;
		b++;
			pivot = A[a][b];
	}
}

 
float f(float P[MAX],float x){
	float v = 0;
	
	v = P[0]*x*x*x + P[1]*x*x + P[2]*x + P[3];
	
	return v;
}
int mult(float Val[3] , float x){
	int  i , k = 0;
	 
	 for( i = 0 ; i<3 ; i++){
	 	 if(Val[i]==x){
	 	 	k++;
		  }
	 }
	 return k;
	 
}
void valeur_propres(float P[MAX], int k , float Val[MAX-1]){
	

	float abs = 0 , x = 0 , a , b , m,M[3],X[2];
	if(k==2){
		if(P[1]*P[1] - 4*P[0]*P[2] >= 0){
	  	
	  	X[0] = (-P[1]+sqrt(P[1]*P[1] - 4*P[0]*P[2]))/2*P[0];
	  	X[1] = (-P[1]-sqrt(P[1]*P[1] - 4*P[0]*P[2]))/2*P[0];
	  	
	  	
	
	  	Val[0] = X[0];
	  	Val[1] = X[1];
	  }
	  else{
	  	 printf("La matrice n'est pas diagonalisable !!\n");
	  }
	}
	if(k==3){
	
	abs =P[3]<0?-P[3]:P[3];
	
	a = -abs;
	b = abs ;
	
	int it = 0;
	 
	  if(!f(P,a))
	  	m = a;
	  	
	  else{
	  	if(!f(P,b))
	  	m = a;
	    else
	  	m = (a+b)/2;
	  }
	  
	  while(f(P,m) && it<50){
	  	it++;
	  	if(f(P,a)*f(P,m)<0){
	  		b = m;
	  		m = (a+b)/2;
		  }
		  else{
		  	a = m;
	  		m = (a+b)/2;
		  }
	  }
}
	 
	  
	    M[0] = P[0];
	  	M[1] =  m*P[0] + P[1];
	  	M[2] = (P[2] + m*P[1] + m*m*P[0]);
	 
	 
	  if(M[1]*M[1] - 4*M[0]*M[2] >= 0){
	  	
	  	X[0] = (-M[1]+sqrt(M[1]*M[1] - 4*M[0]*M[2]))/2*M[0];
	  	X[1] = (-M[1]-sqrt(M[1]*M[1] - 4*M[0]*M[2]))/2*M[0];
	  	
	  	
	  	Val[0] = m;
	  	Val[1] = X[0];
	  	Val[2] = X[1];
	  }
	  else{
	  	 printf("La matrice n'est pas diagonalisable !!\n");
	  }
}
 char sign(float a){
 	 char c = a<0?' ':'+';
 	 
 	 return c;
 }
 
 void Vecteur_propre2(float M[2][2] , float V[2], float x){
 	int i , j, k =0,l = 0;
 	   for(i = 0 ; i < 2 ; i++){
 	    
 	    	M[i][i] = M[i][i] - x;
		 
		 }
		
 }
 int Vecteur_propre(float M[3][3] , float V[3] , float V1[3], float x){
 	
 	  int i , j, k =0,l = 0;
 	   for(i = 0 ; i < 3 ; i++){
 	    
 	    	M[i][i] = M[i][i] - x;
		 
		 }
		 
	
		 echello(M,3);
	
		 
		  for(i = 0 ; i < 3 ; i++){
 	    	if(M[i][i]!=0){
 	    		k++;
			 }
		 }
		 if( k==3){
		 	printf("\nLa matrice n'est pas diagonalisable1 \n\n");
		 }
		 else{
		 
		 
		 if(k==2 && M[2][2]==0){
		 	V[2] = 1;
		 	V[1] = -M[1][2]/M[1][1];
		 	V[0] = (-M[0][2]*V[2] -M[0][1]*V[1])/M[0][0];
		 	
		 	printf("\n %.2f %.2f %.2f\n",V[0],V[1],V[2]);
		 	l++;
		 }
		 if(k==1 && M[0][0]){
		 	V[2] = 0;
		 	V[1] = 1;
		 	V[0] = -M[0][1]/M[0][0];
		 	
		 	V1[2] = 1;
		 	V1[1] = 0;
		 	V1[0] = -M[0][2]/M[0][0];
		 	
		 	printf("\n %.2f %.2f %.2f\n",V[0],V[1],V[2]);
		 	printf("\n %.2f %.2f %.2f\n",V1[0],V1[1],V1[2]);
		 	l+=2;
		 }
		 
		 if(M[0][0]==0){
		 	
		 	V[0] = M[1][1]*M[2][2]-M[2][1]*M[1][2];
		 	V[1] =-( M[1][0]*M[2][2]-M[2][0]*M[1][2]);
		 	V[2] = M[1][0]*M[2][1]-M[2][0]*M[1][1];
		 	
		 	printf("\n %.2f %.2f %.2f\n",V[0],V[1],V[2]);
		 	l++;
		 }
		 if( k==0){
		 	printf("\nLa matrice n'est pas diagonalisable \n\n");
		 }
     }
     return l;
 }
 
 void copy(float M[3][3], float M1[3][3]){
 	 int i , j ;
 	 
 	  for(i = 0 ; i< 3 ; i++){
 	  	for(j = 0 ; j < 3 ; j++){
 	  		M1[i][j] = M[i][j];
		   }
	   }
 }
 int main(){
 	float M[MAX-1][MAX-1],M1[MAX-1][MAX-1] ,M2[MAX-1][MAX-1] , Pol[MAX], Val[MAX-1] , vect[3],vect1[3];
 	
 	int i ,j , k , r =0;
 	
 	 printf("Entrer l'ordre de la matrice : ");
 	 scanf("%d",&k);
 	  
 	  
 	  printf("Entrer les elements de la matrice : ");
 	    
 	    for(i = 0 ; i < k ; i++){
 	    	for(j = 0 ; j < k ; j++){
 	    	scanf("%f",&M[i][j]);
		 }
		 }
 	 if(k==2){
 	 	for(i = 0 ; i < 3 ; i++){
 	    	for(j = 0 ; j < 3 ; j++){
 	    	M2[i][j] = 0;
		 }
		 }
		 M2[0][0] = M[0][0];
		 M2[0][1] = M[0][1];
		 M2[1][0] = M[1][0];
		 M2[1][1] = M[1][1];
		 
 	 	Pol[0] = 1;
 	 	Pol[1] = -(M[0][0] + M[1][1]);
 	 	Pol[2] =  M[0][0]*M[1][1] - M[0][1]*M[1][0];
 	 	
 	 	printf("Le polynome caracteristique est : \n");
 	printf("%.2fX2 %c %.2fX %c %.2f \n",Pol[0],sign(Pol[1]),Pol[1],sign(Pol[2]),Pol[2]);
 	 	valeur_propres(Pol,3,Val);
 	 	 printf("Les valeurs propres sont : \n");
		   for(r=1;r<3;r++){
	  	 	printf("\nVal%d : %.2f\n",r,Val[r]);
		   }
		   
		   	valeur_propres(Pol,3,Val);
	  	printf("V = %.2f\n",Val[0]);
	  	
	  	 int l = 0,g=0;
	  	 
	  	
	  printf("Les vecteurs propres : \n");
	  copy(M,M1);
	  for(r=1;r<3;r++){
	  	 	printf("Vecteur propre associe a %.2f\n",Val[r]);
	  	 g+=l;
	  	l=Vecteur_propre(M1,vect,vect1,Val[r]);
	  
	  
	  	copy(M2,M1);
	  	
	  }
	   if(g==2 || g==4){
	   	  printf("La Matrice est diagonalisable \n");
	   }
	   else{
	   	printf("La matrice n'est pas diagonalisable\n");
	   }
	  }
	  
	  if(k==3){
	  	
	  	Pol[0] = -1;
		Pol[1] = (M[0][0] + M[1][1] + M[2][2]);
		Pol[2] =(M[0][1]*M[1][0] + M[0][2]*M[2][0] + M[1][2]*M[2][1]) -(M[0][0]*M[1][1] + M[0][0]*M[2][2] + M[1][1]*M[2][2])  ;
		Pol[3] = (M[0][0]*M[1][1]*M[2][2] + M[0][1]*M[1][2]*M[2][0] + M[0][2]*M[1][0]*M[2][1])- (M[0][0]*M[1][2]*M[2][1] + M[0][1]*M[1][0]*M[2][2] + M[0][2]*M[1][1]*M[2][0])
		      ;
		      
		      printf("Le polynome caracteristique est : \n");
 	printf("%.2fX3 %c %.2fX2 %c %.2fX %c %.2f \n",Pol[0],sign(Pol[1]),Pol[1],sign(Pol[2]),Pol[2],sign(Pol[3]),Pol[3]);
	  	
	  	valeur_propres(Pol,3,Val);
	  	printf("V = %.2f\n",Val[0]);
	  	
	  	 int l = 0,g=0;
	  	 printf("Les valeurs propres sont : \n");
		   for(r=0;r<3;r++){
	  	 	printf("\nVal%d : %.2f\n",r,Val[r]);
		   }
		   printf("\n\n");
	  	
	  printf("Les vecteurs propres : \n");
	  copy(M,M1);
	  for(r=0;r<3;r++){
	  	 	printf("Vecteur propre associe a %.2f\n",Val[r]);
	  	 g+=l;
	  	l=Vecteur_propre(M1,vect,vect1,Val[r]);
	  
	  
	  	copy(M,M1);
	  	
	  }
	   if(g==3 || g==5){
	   	  printf("La Matrice est diagonalisable \n");
	   }
	   else{
	   	printf("La matrice n'est pas diagonalisable\n");
	   }
	  }
 	return 0;
 	
 }
