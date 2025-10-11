# Array

- Collection of similar data elements grouped under one name.
- Supports only homogeneous data type.
- Stores data in contiguous memory location.
- int A[5];

## Ways to declaration and initialise array

- int A[5]; *: initialise array with garbage values;*
- int A[5] = {2, 4, 6, 8, 10}; *: initialise array with the mentioned values;*
- int A[5] = {2, 4}; *: initialise 1st 2 values with the mentioned values;*
- int A[5] = {0}; *: initialise the full array with the mentioned values;*
- int A[ ] = {2, 4, 6, 8, 10}; *: initialise the array with as much required size needed for the required values;*

## Ways to access array elements

- printf("%d", A[2]);
- printf("%d", 2[A]);
- printf("%d", *(A+2));
- for(i=0; i<5; i++){
    printf( "%d", A[i]) ;
}

## Static array v/s Dynamic array

```C
void main(){
    int A[5]; // static array in stack because the size was defined at the compilation time

    int *p;
    p = (int) malloc(5 * sizeof(int)); // dynamic allocation of array in heap
    free(p);
}
```