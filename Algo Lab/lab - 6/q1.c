#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *l, *r;
};
struct node *cn(int key){
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->info = key;
    nn->l = NULL;
    nn->r = NULL;
    return (nn);
}
static int count = 0;
int cntnds(struct node *root){
    if (root != NULL){
        cntnds(root->l);
        count++;
        cntnds(root->r);
    }
    return count;
}
struct node *createTree(){
    int key;
    printf("Enter the root value: ");
    scanf("%d", &key);

    struct node *nn = cn(key);

    printf("Enter the l child value for %d (or -1 for no child): ", key);
    scanf("%d", &key);
    if (key != -1){
        nn->l = createTree();
    }
    printf("Enter the r child value for %d (or -1 for no child): ", key);
    scanf("%d", &key);
    if (key != -1)
    {
        nn->r = createTree();
    }
    return nn;
}
int main(){
    struct node *root = createTree();
    printf("Number of nodes in the tree = %d\n", cntnds(root));
    return 0;
}
