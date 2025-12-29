#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101
typedef struct {
    int row, col, value;
} terms;
terms a[MAX_TERMS], b[MAX_TERMS];

void transpose();
void display(terms a[]);
int main() {
    int p, q, i, j, value;
    int n = 0;
    int k = 1;
    printf("Enter the number of rows and columns: ");
    if (scanf("%d %d", &p, &q) != 2) return 1;
    a[0].row = p;
    a[0].col = q;
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("Enter the value for row = %d and column = %d :", i, j);
            scanf("%d", &value);
            if (value != 0) {
                if (k >= MAX_TERMS) {
                    printf("Error: Max terms exceeded.\n");
                    a[0].value = n;
                    goto end_input;
                }
                a[k].row = i;
                a[k].col = j;
                a[k].value = value;
                n++;
                k++;
            }
        }
    }
end_input:
    a[0].value = n;
    printf("\nBefore transpose : \n");
    display(a);

    transpose();

    printf("-----------------------------------------------------------\n");
    printf("After Transpose: \n");
    display(b);

    return 0;
}
void display(terms m[]) {
    int n = m[0].value;
    printf("Row\tColumn\tValue\n");
    for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t%d\n", m[i].row, m[i].col, m[i].value);
    }
}
void transpose() {
    int i, j, n;
    int Currentb = 1;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    n = a[0].value;
    if (n > 0) {
        for (i = 0; i < a[0].col; i++) {
            for (j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[Currentb].row = a[j].col;
                    b[Currentb].col = a[j].row;
                    b[Currentb].value = a[j].value;
                    Currentb++;
                }
            }
        }
    }
}
