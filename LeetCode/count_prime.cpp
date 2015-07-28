
class Solution {
public:
    int countPrimes(int n) {
        int* vals = new int[n];
    for(int i = 0; i < n ; i++)
        vals[i] = i;

    for(int i = 2; i < n; i++)
    {
        if(vals[i] == 0)
            continue;
        for(int j = 2; j < n; j++)
        {
            if(i * j >= n)
                break;
            vals[i * j] = 0;
        }
    }
    int counts = 0;
    for(int i = 2; i < n; i++)
    {
        if(vals[i] != 0)
            counts++;
    }
    delete [] vals;
    return counts;
    }
};
