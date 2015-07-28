#include <stack>
using namespace std;
class MinStack {
public:
    void push(int x) {
        if( mins.empty()|| x <= mins.top())
            mins.push(x);
        vals.push(x);
    }

    void pop() {
        if(vals.top() == mins.top())
        {
            mins.pop();
        }
        vals.pop();
    }

    int top() {
        return vals.top();
    }

    int getMin() {
        return mins.top();
    }
private :
    stack<int> vals;
    stack<int> mins;
};
