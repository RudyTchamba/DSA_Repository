#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int isPalindrome(int l , int h , char *mot){
  
   
   if(mot[l]==mot[h] && l==h){
		return 1;
	}
	else if(mot[l]!=mot[h]){
		return 0;
	}
	else{
		l++;
		h--;
		
		return isPalindrome(l,h,mot);
	}


}
int main(){
	int l=0,h;
	char *mot ="KAYAK";
	h=strlen(mot)-1;
	printf("is palindrome = %d\n",isPalindrome(l,h,mot));
	return 0;
	
}
