// Find a pair of elements such that the sum of those elements are equal to the given sum in both sorted and unsorted array consisting of unique elements

// Type 1: 6,3,8,10,16,7,5,2,9,14

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int reqSum = 10;
    int i;

    // Unsorted Array
    int A[10] = {6, 3, 8, 10, 16, 7, 5, 2, 9, 14};

    // Way 1:
    int j;

    for (i = 0; i < (10 - 1); i++)
    {
        if (A[i] != -1)
        {
            for (j = i + 1; j < 10; j++)
            {
                if ((A[i] + A[j]) == reqSum)
                {
                    printf("The pair of element which equal to the required sum %d is: %d at index %d and %d at index %d\n", reqSum, A[i], i, A[j], j);
                    A[j] = -1;
                }
            }
        }
    }

    // Way 2 (using Hashing):
    int max = A[0];

    for (i = 1; i < 10; i++)
        if (max < A[i])
            max = A[i];

    int *B = (int *)malloc((max + 1) * sizeof(int));
    for (i = 0; i < (max + 1); i++)
        B[i] = 0;

    for (i = 0; i < 10; i++)
    {
        if ((B[reqSum - A[i]] != 0) && (reqSum - A[i] >= 0))
            printf("The pair of element which equal to the required sum %d is: %d and %d\n", reqSum, A[i], reqSum - A[i]);
        B[A[i]]++;
    }

    free(B);

    // Sorted Array

    return 0;
}