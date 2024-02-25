#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

void dfs(int n,int mat[][n],bool v[],int *push,int *pop,int* stack,int *pushi,int *popi,int *tops,int a){
	stack[++(*tops)]=a;
	push[++(*pushi)]=a;
	v[a]=true;
	if(v[stack[*tops]])
		printf("%d",stack[*tops]);
	for(int i=0;i<n;i++){
		if(mat[stack[*tops]][i]){
			if(v[i]){
				bool f=false;
				for(int h=0;h<*popi;h++)
					if(pop[h]==i)
						f=true;
				if(!f){
					printf("\rGraph has cycle");
					exit(0);
				}
			}
			else
				dfs(n,mat,v,push,pop,stack,pushi,popi,tops,i);
		}
	}
	pop[(*popi)++]=stack[(*tops)--];
	if(*tops==-1)
		return;
}

int main(){
	int n;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	int mat[n][n];
	memset(mat,0,sizeof(mat));
	int a,b;
	printf("Your edges are : ");
	for(int i=0;i<n;i++)
		printf("%d",i);
	printf("\nEnter the edges a,b such that (a->b), press -1,-1 to stop");
	scanf("%d %d",&a,&b);
	while(a!=-1){
		mat[a][b]=1;
		printf("Enter edge : ");
		scanf("%d %d",&a,&b);
	}
	int *push=(int *)malloc(n*sizeof(int));
	int *pop=(int *)malloc(n*sizeof(int));
	int *stack=(int *)malloc(n*sizeof(int));
	bool v[n];
	memset(v,false,sizeof(v));
	int i=0;int j=0;int tops=0;
	dfs(n,mat,v,push,pop,stack,&i,&j,&tops,0);
	for(int i=0;i<n;i++){
		if(v[i]==false)
			dfs(n,mat,v,push,pop,stack,&i,&j,&tops,i);
	}
	printf("\n");
	for(int i=n-1;i>=0;i--)
		printf("%d",pop[i]);
}
