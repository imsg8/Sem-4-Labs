/*Write a program to implement brute-force string matching. Analyze its time
efficiency.*/

#include<stdio.h>
#include<string.h>

void main(){
int i, j, n, m, flag=0, count=0;
char string[100], substr[100];
printf("Enter the String: ");
scanf("%s", string);
printf("Enter the Sub-String: ");
scanf("%s", substr);
n = strlen(string);
m = strlen(substr);

for(i = 0 ; i <= n-m ; i++){
    j = 0;
        while(j < m && substr[j] == string[j+i]){
            count++;
            j++;
        }
    if(j == m){
        flag = 1;
        break;
    } 
}

if(flag == 1)
    printf("Sub-String found at position: %d \n",i);
else
    printf("Sub-String not Found!\n");
printf("Count is: %d \n", count);
}
