# Recursion

- Function calling itself is called Recursion.
- There must be a "Base Condition" which will terminate the calling of the Recursion otherwise it will be an infinite calling.

## Tracing

Example 1:

```C
#include <stdio.h>

void fun1(int n){
    if(n > 0){
        printf("%d", n);
        fun1(n-1);
    }
}

void main(){
    int x = 3;
    fun1(x);
}

Trace :-

fun1(3)
|     |
3     fun1(2)
      |     |
      2     fun1(1)
            |     |
            1     fun1(0)
                     |
                     X
Output - 3 2 1
```

Example 2:

```C
#include <stdio.h>

void fun2(int n){
    if(n > 0){
        fun2(n-1);
        printf("%d", n);
    }
}

void main(){
    int x = 3;
    fun2(x);
}

Trace :-

                  fun2(3)
                  |     |
            fun2(2)     3
            |     |
      fun2(1)     2
      |     |
fun2(0)     1
  |
  X
Output - 1 2 3
```