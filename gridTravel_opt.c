#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

long long int gridTraveler(int m, int n, long long int memo[][MAX_SIZE]) {
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    if (memo[m][n] != -1) return memo[m][n];

    memo[m][n] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);

    return memo[m][n];
}

long long int gridTravelerOptimized(int m, int n) {
    long long int memo[MAX_SIZE][MAX_SIZE];
    memset(memo, -1, sizeof(memo));
    return gridTraveler(m, n, memo);
}

int main() {
    int m, n;
    printf("Enter the values for m and n: ");
    scanf("%d %d", &m, &n);

    long long int result = gridTravelerOptimized(m, n);

    printf("Result: %lld\n", result);

    return 0;
}
