#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int * rs = new int[m + n];
    int startA = 0 , startB = 0 , startRs = 0;
    while(startA < m && startB < n)
    {
        if(A[startA] < B[startB])
        {
            rs[startRs] = A[startA];
            startA++;
        }
        else
        {
            rs[startRs] = B[startB];
            startB++;
        }
        startRs++;
    }
    while(startA < m)
    {
        rs[startRs] = A[startA];
        startA++;
        startRs++;
    }
    while(startB < n)
    {
        rs[startRs] = B[startB];
        startB++;
        startRs++;
    }
    memcpy(A , rs , sizeof(int) * (m + n));
    }
};
