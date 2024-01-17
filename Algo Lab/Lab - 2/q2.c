#include <stdio.h>
#include <math.h>

int isPrime(int n, int *opCount) {
    for (int i = 2; i <= sqrt(n); i++) {
        (*opCount)++;
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int gcd = 1, a, b, i = 2, small, large, opCount = 0;
    printf("Enter the 2 numbers :");
    scanf("%d %d", &a, &b);
    small = a < b ? a : b;
    large = a > b ? a : b;
    do {
        opCount++;
        if (small % i == 0 && large % i == 0 && isPrime(i, &opCount)) {
            small /= i;
            large /= i;
            gcd *= i;
            i--;
        }
        i++;
    } while (i <= small);
    printf("The GCD of %d and %d is : %d\nOperation Count = %d\n", a, b, gcd, opCount);
    return 0;
}
