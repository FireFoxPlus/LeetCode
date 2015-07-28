
class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
   for(int i = 0; i < 32; i++)
   {
       int mask = 0x00000001 << i;
       int c = 0;
       for(int j = 0; j < n; j++)
       {
            if((A[j] & mask) != 0)
                c++;
       }
        if(c % 3 != 0)
            ret =  ret | mask;
   }
    return ret;

    }
};
