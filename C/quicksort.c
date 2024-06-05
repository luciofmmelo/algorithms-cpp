#include <stdio.h>
#include <stdlib.h>

void permute(int V[], int a, int b) {
    int aux = V[a];
    V[a] = V[b];
    V[b] = aux;
}

int partition(int V[], int i, int f) {
    int q = (i + f) / 2;
    permute(V, i, q);
    int l = i + 1;
    int r = f;
    while (l <= r) {
        while (l <= f && V[l] <= V[i]) {
            l++;
        }
        while (r >= i && V[r] > V[i]) {
            r--;
        }
        if (l < r) {
            permute(V, l, r);
        }
    }
    permute(V, r, i);
    return r;
}

void qsort(int V[], int i, int f) {
    if (f <= i) {
        return;
    }
    int p = partition(V, i, f);
    qsort(V, i, p - 1);
    qsort(V, p + 1, f);
}

void quicksort(int V[], int n) {
    qsort(V, 0, n - 1);
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
