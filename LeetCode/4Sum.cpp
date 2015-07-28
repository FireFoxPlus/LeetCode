#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> >  result;

        if(num.size() < 4) return result;

        sort(num.begin(), num.end());

        for(int i = 0; i < num.size(); i++){
            if(i > 0 && num[i] == num[i-1]) continue;
            for(int j = i+1; j < num.size(); j++){
                if(j > i+1 && num[j] == num[j-1]) continue;
                twoSum(num, result, i, j, target);
            }
        }
        return result;

    }

    void twoSum(vector<int> &num, vector<vector<int>> &res, int targetIndex, int targetIndex2, int target) {
            int i = targetIndex2 + 1;
            int j = num.size()-1;

            while(i < j){
                if(num[targetIndex] + num[targetIndex2] + num[i] + num[j] < target)   i++;
                else if(num[targetIndex] + num[targetIndex2] + num[i] + num[j] > target)   j--;
                else{
                    vector<int> v;
                    v.push_back(num[targetIndex]);
                    v.push_back(num[targetIndex2]);
                    v.push_back(num[i]);
                    v.push_back(num[j]);
                    res.push_back(v);
                    i++; j--;
                    while(i < num.size() && num[i]==num[i - 1]) i++;
                    while(j >= 0 && num[j] == num[j + 1]) j--;
                }
            }

    }

};
