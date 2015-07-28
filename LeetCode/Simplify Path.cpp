#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        string rs;
    stack<string> pathRecord;
    while(path.length() != 0)
    {
        string curPath;
        int  pre = path.find('/');
        int last = path.find('/' , pre + 1);
        if(last == string::npos)
            curPath = path.substr(pre , string::npos);
        curPath = path.substr(pre , last - pre);
        if(curPath == "/..")
        {
            if(!pathRecord.empty())
                pathRecord.pop();
            else
                pathRecord.push("/");
        }
        else if(curPath == "/")
            ;
        else if(curPath != "/.")
        {
            if(!pathRecord.empty() && pathRecord.top() == "/")
                pathRecord.pop();
            pathRecord.push(curPath);
        }
        if(last != string::npos)
            path = path.substr(last , string::npos);
        else
            break;
    }
    if(pathRecord.empty())
        return string("/");
    while(!pathRecord.empty())
    {
        rs.insert(0 , pathRecord.top());
        pathRecord.pop();
    }
    return rs;
    }
};
