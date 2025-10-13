# Array ADT (as Abstract Data Type)

## Data

- [Array space](#array-space-size-length)
- [Size](#array-space-size-length)
- [Length (No. of elements)](#array-space-size-length)

## Operation

- [Display(arr)](#displayarr)
- [Add(x) / Append(x)](#addx--appendx)
- [Insert(index, x)](#insertindex-x)
- [Delete(index)](#deleteindex)
- [Get(index)]
- [Set(index, x)]
- [Max() / Min()]
- [Reverse()]
- [Shift() / Rotate()]

## Searching

- [Linear Search]
- [Binary Search]

# Data

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

# Operartions

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

## Delete(index)

```C
x = A[index];
for(i=index; i<length; i++){
    A[i] = A[i+1];
}
length--;
```
Time - max: O(n), min: O(1)

# Searching

## Linear Searching

- Elements must be of unique set.
- Search linearly by checking elements one by one.

```C
for(i=0; i<length; i++){
    if(key==A[i]) return i; 
}
return -1;
```
1st element take 1 case
<br>
2nd element take 2 case
<br>
3rd element take 3 case
<br>
.
<br>
.
<br>
.
<br>
nth element take n case

Total cases required for searching n elements - 1+2+3+...+n
<br>
Avg time for 1 element - (1+2+3+...+n)/n = (n+1)/2 -> O(n)

Time - max: O(n), min: O(1), avg: O(n)

### Improving Linear Search



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

// Deletefunction
int Delete(struct Array *arr, int index){
    int x = 0;
    if(index>=0 && index<arr->length){
        x = arr->A[index];
        for(i=index; i<arr->length-1; i++) arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }

    return 0;
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

    // Delete operation
    printf("%d\n", Delete(&arr, 0);)
    printf("%d\n", Delete(&arr, 5);)

    // Display operation
    Display(arr);

    return 0;
}
```