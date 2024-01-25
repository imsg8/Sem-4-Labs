#include<stdio.h>
int main()
{
	int n, i, j, t, opc = 0;
    printf("Enter Number of Elements ");
    scanf("%d", &n);
    int array[n];
    printf("Enter Elements\n");
    for(i = 0; i < n; i++)
        scanf("%d", &array[i]);
    for(i = n - 1; i > 0; i--){
        for(j = 0; j < i; j++){
            opc++;
            if(array[j] > array[j+1]){
                t = array[j];
                array[j] = array[j+1];
                array[j+1] = t;
            }
        }
    }
    printf("Sorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d", array[i]);
    printf("\nOpCount is: %d", opc);
}
