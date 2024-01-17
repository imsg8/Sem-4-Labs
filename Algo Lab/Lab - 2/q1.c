#include<stdio.h>
int smallest(int a,int b){
    return (a>b?a:b);
}
int main(){
    int m=0, n=0, t=0, gcd=0, opCount=0;
    printf("Enter two numbers: ");
    scanf("%d %d",&m,&n);
    t = smallest(m,n);
    for(int i=t;i>0;i--){
        opCount++;
        if(m%i==0 && n%i==0){
            gcd = i;
            break;
        }
    }
    printf("GCD of %d and %d is: %d\nOperation count is: %d\n", m, n, gcd, opCount);
}
