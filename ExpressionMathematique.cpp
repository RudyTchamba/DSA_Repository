#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


typedef struct node{
	char c;
	struct node *left;
	struct node *right;
}node;


 node *makeNode(char c)
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
 
 char* prof(char *str , int P[] , int *h)
 {
 
   int f = 0 ;
   int n =strlen(str)+1;
   char *st = (char*)malloc(sizeof(char));
   int k = 0;
   int i = 0;
   
   for(i= 0 ; i< strlen(str); i++)	
   {
   	 if(str[i]=='(')
   	 {
   	 	f++;
	  }
		if(str[i]==')')
   	   {
   	 	f--;
		}
		if(isdigit(str[i])){
			st[k] = str[i];
			P[k++] = f;
		}
		if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
		    	st[k] = str[i];
			P[k++] = f - 1;
			
		}
		
   }
   *h = k;
   
   return st;
 }
 
  void parcour_infixe(node *arbre)
 {
 	if(arbre==NULL)
 	  return;
 	  
 	parcour_infixe(arbre->left);
 	printf("val = %c\n",arbre->c);
 	parcour_infixe(arbre->right);
 
 	
 }
 
 node *f(char *str , int P[] , int lo , int hi)
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
    if (isdigit(root->c))
        return (root->c - '0')*1.0f;
    float left = evaluate(root->left);
    float right = evaluate(root->right);
    if (root->c == '+')
        return left + right;
    if (root->c == '-')
        return left - right;
    if (root->c == '*')
        return left * right;
    if (root->c == '/')
        return left / right;
    return 0.0f;
}
 
int main(){
	int P[5];
	int k = 0 ;
	char t[100];
	printf("Entrer l'expression mathematique parenthese  : ");
	scanf("%s",t);
	
	char *st =  prof(t,P,&k);
	int i = 0;
	
	node *root = f(st,P,0,k-1);
	
	 
	 float v  = evaluate(root);
	 printf("Ans = %.2f\n",v);
	return 0;
	
}

