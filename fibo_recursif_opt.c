/*#include <stdio.h>

int fib(int n, int* memo) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 2) {
        return 1;
    }
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main() {
    int n; // La valeur de n que vous souhaitez utiliser
    int memo[n + 1];
    printf("Enter the value of n: ");
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    int result = fib(n, memo);
    printf("Le résultat de fib(%d) est %d\n", n, result);
    return 0;
}*/

#include <stdio.h>

#define MAX_SIZE 1000 // Réglez cette valeur selon vos besoins

long long fib(int n, long long* memo) {
    if (memo[n] != 0)
        return memo[n];
    if (n <= 2)
        return 1;
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
    return memo[n];
}

int main() {
    int n; // Remplacez par la valeur souhaitée
    printf("Enter the value of n: ");
    scanf("%d", &n);
    long long memo[MAX_SIZE] = {0}; // Tableau pour stocker les résultats précédents
    long long result = fib(n, memo);
    printf("Le %dème nombre dans la série de Fibonacci est : %lld\n", n, result);
    return 0;
}
