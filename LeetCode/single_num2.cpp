//这是single_num1
class Solution {
public:
    int singleNumber(int A[], int n) {
           int rs = 0;
      for(int i = 0; i < n; i++)
        rs = rs ^ A[i];
      return rs;

    }
};
