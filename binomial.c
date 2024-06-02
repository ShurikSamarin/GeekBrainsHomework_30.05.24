#include <stdio.h>

int binomial_coefficient(int n, int k) {
    if (k > n - k) k = n - k;
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main() {
    int n, m;
    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter M: ");
    scanf("%d", &m);
    printf("Number of combinations: %d\n", binomial_coefficient(n, m));
    return 0;
}
