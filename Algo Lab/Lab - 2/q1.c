#include<stdio.h>
int smallest(int a,int b){
    return (a>b?a:b);
}
int main(){
    int m, n, t, gcd;
    printf("Enter two numbers: ");
    scanf("%d %d",&m,&n);
    t = smallest(m,n);
    for(int i=t;i>0;i--){
        if(m%i==0 && n%i==0){
            gcd = i;
            break;
        }
    }
    printf("GCD: %d\n",gcd);
}
