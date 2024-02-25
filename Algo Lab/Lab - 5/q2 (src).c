#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	int mat[n][n];
	memset(mat,0,sizeof(mat));
	int a,b;
	printf("Your edges are : ");
	for(int i=0;i<n;i++)
		printf("%d",i);
	printf("\nEnter the edges a,b such that (a->b), press -1,-1 to stop");
	scanf("%d %d",&a,&b);
	int in[n];
	memset(in,0,sizeof(in));
	while(a!=-1){
		mat[a][b]=1;
		in[b]++;
		printf("Enter edge : ");
		scanf("%d %d",&a,&b);
	}
	int c=0;
	while(c!=n){
		int src;
		for(src=0;src<n;src++)
			if(in[src]==0)
				break;
		if(src==n){
			printf("\rThere is cycle in the graph");
			break;
		}
		printf("%d\t",src);
		in[src]=-1;
		c++;
		for(int i=0;i<n;i++){
			if(mat[src][i])
				in[i]--;
		}
	}
	printf("\n");
}
