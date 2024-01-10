#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

int main(){
	int n;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	int a[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=0;
	printf("Your nodes are : ");
	for(int i=0;i<n;i++)
		printf("%d\t",i);
	printf("\n");
	printf("Enter all the edges and -1 if all edges are done\n");
	printf("Enter edge : ");
	int n1;
	int n2;
	scanf("%d %d",&n1,&n2);
	while(n1!=-1){
		a[n1][n2]=1;
		a[n2][n1]=1;
		printf("Enter edge : ");
		scanf("%d %d",&n1,&n2);
	}
	printf("Adjacency matrix : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	Node** al=(Node**)malloc(n*sizeof(Node *));
	for(int i=0;i<n;i++){
		al[i]=(Node*)malloc(sizeof(Node));
		al[i]->data=i;
		al[i]->next=NULL;
		Node* temp=al[i];
		for(int j=0;j<n;j++){
			if(a[i][j]){
				Node* t=(Node*)malloc(sizeof(Node));
				t->data=j; t->next=NULL;
				temp->next=t;
				temp=t;
			}
		}
	}
	printf("Adjacency list : \n");
	for(int i=0;i<n;i++){
		Node* temp=al[i];
		while(temp){
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}
}
