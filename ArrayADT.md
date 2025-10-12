# Array ADT (as Abstract Data Type)

## Data

- [Array space](#array-space-size-length)
- [Size](#array-space-size-length)
- [Length (No. of elements)](#array-space-size-length)

## Operation

- [Display(arr)](#displayarr)
- [Add(x) / Append(x)](#addx--appendx)
- [Insert(index, x)](#insertindex-x)
- [Delete(index)]
- [Search(x)]
- [Get(index)]
- [Set(index, x)]
- [Max() / Min()]
- [Reverse()]
- [Shift() / Rotate()]

## Array Space, Size, Length

1. int A[10];
    <br>
    size = 10;
    <br>
    Length = 0;
2. int* A;
    <br>
    A = (int*) malloc(size * sizeof(int)); //input size from user
    <br>
    Length = 0;

## Display(arr)

```C
for(i=0; i<length; i++) printf("%d", A[i]);
```

## Add(x) / Append(x)

```C
A[length] = x;
length++;
```
Time - O(1) 

## Insert(index, x)

```C
for(i=length; i>index; i--) A[i] = A[i-1];
A[index] = x;
length++;
```
Time - max: O(n), min: O(1)















# Code Implementation

```C
#include <stdio.h>
#include <stdlib.h>

struct Array{
    /* Array in HEAP
    int *A; */

    // Array in STACK
    int A[10];
    int size;
    int length;
}

// Diplay function
void Display(struct Array arr){
    int i;
    printf("\nElements are:- \n");
    for(i=0; i<arr.length; i++) printf("%d ", arr.A[i]);
}

// Append function
void Append(struct Array *arr, int x){
    if(arr->length < arr->size) arr->A[arr->length++] = x;
}

// Insert function
void Insert(struct Array *arr, int index, int x){
    int i;
    if(index>=0 && index<=arr->length){
        for(i=arr->length; i>index; i--) arr->A[i] = arr->A[i-1];
        arr->A[index] = x;
        arr->length++;
    }
}

int main(){
    /* Initialise Array in HEAP
    struct Array arr;
    int n, i;

    printf("Enter size of an array:- ");
    scanf("%d", &arr.size);
    
    arr.A = (int*)malloc(arr.size * sizeof(int));
    arr.length = 0;

    printf("Enter number of numbers:- ");
    scanf("%d", &n);
    printf("Enter all the elements:- ");
    for(i=0; i<n; i++) scanf("%d", &arr.A[i]);
    arr.length = n; */

    // Initialise Array in STACK
    struct Array arr = {{2,3,4,5,6}, 10, 5};

    // Append function
    Append(&arr, 10);

    // Insert function
    Insert(&arr, 0, 10);

    // Display operation
    Display(arr);

    return 0;
}
```