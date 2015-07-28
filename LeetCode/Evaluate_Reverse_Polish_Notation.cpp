#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void evalStack(stack<int> &nums , string expre)
{
    for(int i = 0; i < expre.length(); i++)
    {
        if(expre[i] == '+' || expre[i] == '*' || expre[i] == '/' || (
           expre[i] == '-' && expre.length() == 1))
        {
            int num1 = nums.top();
            nums.pop();
            int num2 = nums.top();
            nums.pop();
            if(expre[i] == '+')
                nums.push(num1 + num2);
            else if(expre[i] == '-')
                nums.push(num2 - num1);
            else if(expre[i] == '*')
                nums.push(num1 * num2);
            else if(expre[i] == '/')
                nums.push(num2 / num1);
        }
        else
        {
            int sign = 1;
            if(expre[i] == '-')
            {
                sign = -1;
                i++;
            }
            int tmp = 0;
            while(isdigit(expre[i]))
            {
                tmp = tmp * 10 + expre[i] - '0';
                i++;
            }
            nums.push(tmp * sign);
        }
    }
}


    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0)
        return 0;
    stack<int> nums;
    for(int i = 0; i < tokens.size(); i++)
    {
        evalStack(nums , tokens[i]);
    }
    return nums.top();

    }
};
