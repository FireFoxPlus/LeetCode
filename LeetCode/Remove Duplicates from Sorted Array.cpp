
class Solution {
public:
    int removeDuplicates(int A[], int n) {
     int counts = 0;
    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            continue;
        if(A[i] == A[i - 1])
        {
            while(A[i] == A[i - 1] && i < n)
            {
                counts++;
                i++;
            }
            i--;
            continue;
        }
        A[i - counts] = A[i];
    }
    return n - counts;

    }
};
