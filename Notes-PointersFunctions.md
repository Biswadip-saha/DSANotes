# Pointers

-   Code can't access HEAP, for that pointer is required. In simple words pointers are used for accessing HEAP, accessing "Resources", and parameter passing.

-   Size of pointer is independent of its data type.

```C
int a = 10; // data variable
int *p; // pointer to integer variable
p = &a; //-> p stores the memory address of a, and *p points toward the value stored at the memory address at 'a'
```

### Pointer to Array

```C
#include <stdio.h>
#include <stdlib.h>

int main(){
    // pointer to array
    int A[5] = {2,4,6,8,10};
    int *p;
    p = A;

    // dynamically allocating space in HEAP
    int *a;
    a = (int*) malloc(sizeof(int) * 5) //-> malloc returns void pointer, therefore it is needed to typecast to integer pointer
    a[0] = 10; a[1] = 20; a[2] = 30; a[3] = 40; a[4] = 50;
    free(a);
}
```

### Pointer to Structure

```C
#include <stdio.h>
#include <stdlib.h>

struct Rectangle{
    int length;
    int breadth;
}

int main(){
    struct Rectangle r = {10,5};
    struct Rectangle *p = &r;

    // ways to access the members of a structure
    (*p).length = 20;
    p -> length = 20;

    // dynamically allocating space in HEAP
    struct Rectangle *a;
    a = (struct Rectangle *) malloc(sizeof(struct Rectangle));
    a -> length = 10;
    a -> breadth = 5;
}
```

# Functions

