
class Solution {
public:
     int partion(int *arr, int start, int end, int pivot)
{
    while(start <= end){
        while(start <= end && arr[start] <= pivot)  start ++;
        while(start <= end && arr[end] > pivot)   end --;
        if(start < end){
            int t = arr[start];
            arr[start] = arr[end];
            arr[end] = t;

            start ++;
            end --;
        }
    }

    return start;
}

void sortColors(int A[], int n)
{
    int mid = 0;

    if(n <= 0)  return ;

    mid = partion(A, 0, n - 1, 0);
    mid = partion(A, mid, n - 1, 1);

    return ;
}
};
