# Array ADT (as Abstract Data Type)

## Data

-   [Array space](#array-space-size-length)
-   [Size](#array-space-size-length)
-   [Length (No. of elements)](#array-space-size-length)

## Operation

-   [Display(arr)](#displayarr)
-   [Add(x) / Append(x)](#addx--appendx)
-   [Insert(index, x)](#insertindex-x)
-   [Delete(index)](#deleteindex)
-   [Get(index)](#getindex)
-   [Set(index, x)](#setindex)
-   [Max() / Min()](#max--min)
-   [Avg()](#avg)
-   [Reverse()]
-   [Shift() / Rotate()]

## Searching

-   [Linear Search](#linear-searching)
-   [Binary Search](#binary-searching)

# Data

## Array Space, Size, Length

1. int A[10];
   <br>
   size = 10;
   <br>
   Length = 0;
2. int* A;
   <br>
   A = (int*) malloc(size \* sizeof(int)); //input size from user
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

## Get(index)

```C
if(index>=0 && index<length) return A[index];
```

Time - O(1)

## Set(index)

```C
if(index>=0 && index<length) A[index] = x;
```

Time - O(1)

## Max() / Min()

```C
max = A[0];
min = A[0];
for(i=1; i<length; i++){
    if(A[i]>max) max = A[i];
    if(A[i]<min) min = A[i];
}
return max/min;
```

Time - O(n)

## Avg()

```C
total = 0;
for(i=0; i<length; i++) total = total+A[i];
return total/n;
```

Time - O(n)

# Searching

## Linear Searching

-   Elements must be of unique set.
-   Search linearly by checking elements one by one.

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

1. Transposition :
    - If an element is searched, there is a high possibility that, that element might be searched for again, for that move the element one position closer for reducing the number of searches needed to find that element.

```C
for(i=0; i<length; i++){
    if(key==A[i]) {
        swap(A[i], A[i-1]);
        return i-1;
    }
}
return -1;
```

2. Move to front/head:

```C
for(i=0; i<length; i++){
    if(key==A[i]) {
        swap(A[i], A[0]);
        return 0;
    }
}
return -1;
```

## Binary Searching

-   All elements must be sorted
-   Search in the middle of the array, if not found split the array in half and search in the middle of the half where the element belongs.
-   3 parameters required: l (low), h (high), key

```C
Way 1 (Iterative) :-
while(l<=h){
    mid = [(l+h)/2];
    if(key = A[mid]) return mid;
    else if(key<A[mid]) h = mid-1;
    else l = mid+1;
}
return -1;

Way 2 (Recursive) :-
if(l<=h){
    mid = [(l+h)/2];
    if(key = A[mid]) return mid;
    else if(key<A[mid]) return BinarySearch(l, mid-1, key);
    else return BinarySearch(mid+1, h, key);
}
return -1;
```
`log is of base 2`

1st level of middle element take 1 search = 
<br>
2nd level of middle element take 2\*2 search
<br>
3rd level of middle element take 3\*4 search
<br>
4th level of middle element take 4\*8 search
<br>
.
<br>
.
<br>
.
<br>
ith level of middle element take i\*2^(i-1) search

Total searches required for searching n elements - 1\*2^0 + 2\*2^1 + 3\*2^2 + ... + i\*2^(i-1)
<br>
Avg time for 1 element - (1\*2^0+2\*2^1+3\*2^2+...+i\*2^(i-1))/n 
<br>
= ((i=1Σlogn)i\*2^(i-1))/n 
<br>
= (logn\*2^(logn))/n (approx)
<br>
= (logn\*n^(log2))/n
<br>
= logn
<br>

Time - Max: O(logn), Min: O(1), Avg: O(logn)

# Code Implementation

```C
#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

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

// Get function
int Get(struct Array arr, int index){
    if(index>=0 && index<arr.length) return arr.A[index];
    return -1;
}

// set function
int Get(struct Array *arr, int index, int x){
    if(index>=0 && index<arr->length) arr->A[index] = x;
}

// Max function
int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for(i=1; i<arr.length; i++){
        if(arr.A[i]>max) max = arr.A[i];
    }
    return max;
}

// Min function
int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for(i=1; i<arr.length; i++){
        if(arr.A[i]<min) min = arr.A[i];
    }
    return min;
}

// Avg function
float Avg(struct Array arr){
    int s = 0, i;
    for(i=0; i<arr.length; i++) s+=arr.A[i];
    return (float) s/arr.length;
}

// Linear Search
int LinearSearch(struct Array *arr, int key){
    int i=0;
    for(i=0; i<arr->length; i++){
        if(key==arr->A[i]){
            // return i; Normal
            /* swap(&arr->A[i], &arr->A[0]); // Move to Head
            return 0; */
            swap(&arr->A[i], &arr->A[i-1]); // Transposition
            return i-1;
        }
        return -1;
    }
}

// Binary Search

    // Iterative
    int BinarySearch(struct Array arr, int key){
        int l, mid, h;
        l = 0;
        h = arr.length-1;

        while(l<=h){
            mid = [(l+h)/2];
            if(key == arr.A[mid]) return mid;
            else if(key<arr.A[mid]) h = mid-1;
            else l = mid+1;
        }
        return -1;
    }

    // Recursive
    /* int RecursiveBinarySearch(int a[], int l, int h, int key){
        int mid;
        if(l<=h){
            mid = (l+h)/2;
            if(key == a[mid]) return mid;
            else if(key<a[mid]) return RecursiveBinarySearch(a, l, mid-1, key);
            else return RecursiveBinarySearch(a, mid+1, h, key);
        }
        return -1;
    } */

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

    // Append operation
    Append(&arr, 10);

    // Insert operation
    Insert(&arr, 0, 10);

    // Delete operation
    printf("%d\n", Delete(&arr, 0););
    printf("%d\n", Delete(&arr, 5););

    // Get operation
    printf("%d\n", Get(arr, 2));

    // Set operation
    Set(&arr, 0, 10);

    // Max / Min operation
    printf("%d\n", Max(arr));
    printf("%d\n", Min(arr));

    // Avg operation
    printf("%f\n", Avg(arr));

    // Linear Search
    printf("%d\n", LinearSearch(&arr, 4));

    // Binary Search
    printf("%d\n", BinarySearch(arr, 4));
    // printf("%d\n", RecursiveBinarySearch(arr.A, 0, arr.length, 4));

    // Display operation
    Display(arr);

    return 0;
}
```
