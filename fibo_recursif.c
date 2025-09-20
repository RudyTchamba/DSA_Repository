#include <stdio.h>

int fibo(int n) {
    if (n <= 1)
        return n;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n, x;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    x = fibo(n);
    printf("The Fibonacci number at position %d is: %d\n", n, x);
    return 0;
}
