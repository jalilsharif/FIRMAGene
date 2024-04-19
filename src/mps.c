#include <stdlib.h>
#include <stdio.h>
#include <math.h>

oid muf(double *v, double *x, long *n_) {
    int i, j, k, n = *n_, count = 0;
    double sum = 0., *cumsum = malloc((n + 1) * sizeof(double));
    cumsum[0] = 0.; // Initialize cumsum

    // Compute cumulative sums
    for (i = 1; i <= n; i++) {
        cumsum[i] = cumsum[i - 1] + v[i - 1];
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            sum = cumsum[j + 1] - cumsum[i];
            x[count++] = sum / sqrt(j - i + 1.);
        }
    }

    free(cumsum); // Clean up the allocated memory
}