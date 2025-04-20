#include<stdio.h>

int w[10][10];

void transitiveClosure(int mat[10][10], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
            }
        }
    }
}

void print(int mat[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    // taking input adjacency matrix
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter input adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &w[i][j]);
        }
    }

    printf("Input adjacency matrix:\n");
    print(w, n);

    transitiveClosure(w, n);

    printf("Transitive closure matrix:\n");
    print(w, n);

    return 0;
}