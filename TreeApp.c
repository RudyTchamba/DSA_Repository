#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEM 10
#define max(a,b,c) (a>=b?(a>=c?a:c):(b>=c?b:c))
#define min(a,b,c) (a<=b?(a<=c?a:c):(b<=c?b:c))
#define sum(a,b,c) (a+b+c)

int* readInput(int numberOfItems){
	int* input;
	if(numberOfItems <= 0){
		printf("%d is not a valid numberOfItems\n",numberOfItems);
		return input;
	}

	input = (int*) malloc(numberOfItems * sizeof(int));
	printf("Enter %d items:",numberOfItems);
	for(int i=0; i<numberOfItems; i++){
		scanf("%d",&input[i]);
	}
	return input;
}

void printData(int* data, int length){
	printf("[ ");
	for(int i=0; i<length; i++){
		printf("%d, ",data[i]);
	}
	printf("\b\b ]\n");
}

void convertToBst(int *data, int length){
	if(length <= 0){
		printf("invalid length %d\n", length);
	}

	//start from i=1 and arrange items at index i-1,i,i+1
	int a,b,c;
	int dn,dl,dr;
	int parent,rchild,lchild;
	int k;
	for(int i=0; i<length/2; i++){
		//decide the order in which the nodes should be synced to create bst
		int nodeOrder[i+1];
		char nodesAligned[i+1];
		for(k=0;k<=i;k++)
			nodesAligned[k]='n';
		nodeOrder[0]=i;
		nodesAligned[i]='y';
		k=1;
		int node=i;
		// printf("\nnode %d\n",node);
		for(int j=0;j<=k && j<=i;j++){
			node=nodeOrder[j]; //for next node in order
			parent = node%2==0? node/2-1 :node/2;
			lchild = 2*node+1;
			rchild = 2*node+2;
			// printf("\tfor:%d => parent:%d rchild:%d lchild:%d\n",node,parent,rchild,lchild);
			if(lchild < i && nodesAligned[lchild]=='n'){
				// printf("\t\tlchild:%d\n",lchild);
				nodeOrder[k++] = lchild;
				nodesAligned[lchild]='y';
			}
			// else printf("\t\t%d not added\n",lchild);
			if(rchild < i && nodesAligned[rchild]=='n'){
				// printf("\t\trchild:%d\n",rchild);
				nodeOrder[k++] = rchild;
				nodesAligned[rchild]='y';
			}
			// else printf("\t\t%d not added\n",rchild);
			if(parent < i && nodesAligned[parent]=='n'){
				// printf("\t\tparent:%d\n",parent);
				nodeOrder[k++] = parent;
				nodesAligned[parent]='y';
			}
			// else printf("\t\t%d not added\n",parent);
		}

		for(int j=0;j<i+1;j++){
			node = nodeOrder[j];
			lchild = node*2 + 1;
			rchild = node*2 + 2;

			dn=data[node];
			dl=data[lchild];
			dr=data[rchild];

			data[lchild] = min(dn,dl,dr);
			data[rchild] = max(dn,dl,dr);
			data[node] = sum(dn,dl,dr) - min(dn,dl,dr) - max(dn,dl,dr);
		}
		printData(data, length);
	}
}

int test(int a,int b,int c){
	printf("min(%d, %d, %d) => %d\n", a,b,c,min(a,b,c));
	printf("max(%d, %d, %d) => %d\n", a,b,c,max(a,b,c));
}

int main(){
	int numberOfItems = MAX_ITEM;
	printf("Enter numberOfItems: ");
	scanf("%d",&numberOfItems);
	int *input = readInput(numberOfItems);
	convertToBst(input, numberOfItems);
	return 0;
}