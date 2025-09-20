#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


typedef struct node{
	char *c;
	struct node *left;
	struct node *right;
}node;


 node *makeNode(char *c)
 {
 	node *np = (node*)malloc(sizeof(node));
 	np->c = c;
 	np->left = NULL;
 	np->right = NULL;
 	
 	return np;
 }
 
 int min(int P[] , int lo , int hi)
 {
 	int i = 0 ,  m = P[lo];
 	int k = lo;
 	for(i = lo ; i <hi; i++)
 	{
 		if(P[i]<m){
 			m = P[i];
 				k = i;
		 }
	 }
	 return k;
 }
 
 void trans(char st[][100],char *str, int *h)
 {
 	int f = 0, k = 0 , i = 0 , r= 0;
 	 for(i = 0 ; i < strlen(str) ; i++)
 	 {	
 	 if(isdigit(str[i])||str[i]=='.')
 	 	{
 	 		st[k][r++] = str[i];
		 }
		else{
		 if(r!=0){
		 	 ++k;
		   }	 
		    r = 0;
			st[k][r] = str[i];
		      k++;
		  }	 
	  }

	  *h = k;
 }
 
 void prof(char *str ,char st1[][100] , int P[] , int *h)
 {
 
   int f = 0 , n;
   char st[100][100] ;
   
   int k = 0;
   int i = 0;
   
   trans(st,str,&n);
   
    for( i = 0 ; i < n ; i++)
	  {
	  	printf("st = %s \n",st[i]);
	  	
	  }
	  printf("\n\n");
   for(i= 0 ; i< n; i++)	
   {
   	 if(strcmp(st[i],"(")==0)
   	 {
   	 	f++;
	  }
		if(strcmp(st[i],")")==0)
   	   {
   	 	f--;
		}
		if(atof(st[i])!=0){
		    	strcpy(st1[k],st[i]);
			P[k++] = f;
		}
		if(strcmp(st[i],"+")==0||strcmp(st[i],"-")==0||strcmp(st[i],"*")==0||strcmp(st[i],"/")==0){
		    	strcpy(st1[k],st[i]);
			P[k++] = f - 1;
			
		}	
   }
   *h = k;
 }
 
 node *f(char str[][100] , int P[] , int lo , int hi)
 {
 	int m = min(P,lo,hi);
 	node *root = makeNode(str[m]);
    if(lo<m){
 	root->left = f(str,P,lo,m);
  	root->right = f(str,P,m+1,hi);
  }
 	return root;
 }
 
 float evaluate(struct node* root) {
    if (root == NULL)
        return 0;
    if (atof(root->c))
        return atof(root->c)*1.0f;
    float left = evaluate(root->left);
    float right = evaluate(root->right);
    if (strcmp(root->c,"+")==0)
        return left + right;
    if (strcmp(root->c,"-")==0)
        return left - right;
    if (strcmp(root->c,"*")==0)
        return left * right;
    if (strcmp(root->c,"/")==0)
        return left / right;
    return 0.0f;
}
 
 void parcour_infixe(node *arbre)
 {
 	if(arbre==NULL)
 	  return;
 	  
 	parcour_infixe(arbre->left);
 	printf("val = %s\n",arbre->c);
 	parcour_infixe(arbre->right);
 
 	
 }
 

 
int main(){
	int P[100];
	int k = 0 , h ;
	char t[100];
	printf("Entrer l'expression mathematique parenthese  : ");
	scanf("%s",t);
	
	char str[100][100];
    
	prof(t,str,P,&h);
	  
	  node *root = f(str,P,0,h-1);
	
   parcour_infixe(root);
	float v  = evaluate(root);
	 printf("Ans = %.2f\n",v);

	return 0;
	
}

