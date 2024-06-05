#include <stdio.h>
#include <stdlib.h>

void merge(int V[], int A[], int i, int m, int f) {
    int l = i;
    int r = m + 1;
    for (int k = i; k <= f; k++) {
        if (l > m) {
            A[k] = V[r];
            r++;
        } else if (r > f) {
            A[k] = V[l];
            l++;
        } else if (V[l] <= V[r]) {
            A[k] = V[l];
            l++;
        } else {
            A[k] = V[r];
            r++;
        }
    }
    for (int k = i; k <= f; k++) {
        V[k] = A[k];
    }
}

void msort(int V[], int A[], int i, int f) {
    if (i >= f) {
        return;
    }
    int m = (i + f) / 2;
    msort(V, A, i, m);
    msort(V, A, m + 1, f);
    merge(V, A, i, m, f);
}

void mergesort(int V[], int n) {
    int* A = (int*)malloc(n * sizeof(int));
    if (A == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    msort(V, A, 0, n - 1);
    free(A);
}

void printArray(int V[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }
    printf("\n");
}

int main() {


    return 0;
}
