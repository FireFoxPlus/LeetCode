#include <memory.h>
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int *flag = new int[n];
    memset(flag , 0 , sizeof(int) * n);
    int squez = 0;
    for(int i = 0; i < n;)
    {
        flag[i] = squez;
        int tmp = A[i];
        int counts = 0;
        for(; i < n; i++)
        {
            if(A[i] != tmp)
                break;
            flag[i] = squez;
            counts++;
        }
        if(counts > 2)
            squez += counts - 2;
    }
    for(int i = 0; i < n; i++)
    {
        int moves = flag[i];
        A[i - moves] = A[i];
    }
    return n - squez;
    }
};
