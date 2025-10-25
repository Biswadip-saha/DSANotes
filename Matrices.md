# Matrices

-   Special matrices are essentially square matrix, with number of 0's > actual elements

## Types

-   [Diagonal Matrix](#diagonal-matrix)

## Code

-   [Implementation](#implementation)
-   [Menu Driven Programme](#menu-driven-programme)

# Types

## Diagonal Matrix

-   For Diagonal Matrix, M[i, j] = 0 for i!=j
-   Since, most of the elements are 0, store the actual elements in a 1D array rather than 2D array

```C
Diagonal Matrix, M, with elements: 3, 7, 4, 9, 6

int A[5]; // matrix of 5x5

void set(int A[], int i, int j, int x){
    if(i == j) A[i-1] = x;
}

int get(int A[], int i, int j){
    if(i == j) return A[i-1];
    else return 0;
}
```

[`Code:`](#diagonal-matrix-1)

# Code

## Implementation

### Initialisation

```C
#include <stdio.h>

struct Matrix{
    int A[10]; // length of 1D array
    int n; // dimension of matrix
}
```

### Diagonal Matrix

```C
void DiagonalSet(struct Matrix *m, int i, int j, int x){
    if(i == j) m->A[i-1] = x;
}

int DiagonalGet(struct Matrix m, int i, int j){
    if(i == j) return m.A[i-1];
    else return 0;
}

void DiagonalDisplay(struct Matrix m){
    int i, int j;
    for(i=0; i<m.n; i++){
        for(j=0; j<m.n; j++){
            if(i==j) printf("%d ", m.A[i-1]);
            else printf("0 ");
        }
        printf("\n");
    }
}
```

### Body

```C
int main(){
    struct Matrix m;
    m.n = 4;

    // Diagonal Matrix
    DiagonalSet(&m, 1, 1, 3); DiagonalSet(&m, 2, 2, 7); DiagonalSet(&m, 3, 3, 4); DiagonalSet(&m, 4, 4, 9);

    DiagonalDisplay(m);

    printf("%d\n", DiagonalGet(m, 2, 2));

    return 0;
}
```
