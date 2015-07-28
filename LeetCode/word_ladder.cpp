#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    bool onceChange(string fir , string sec)
{
    int counts = 0;
    if(fir.length() != sec.length())
        return false;

    for(int i = 0; i < fir.length(); i++)
    {
        if(fir[i] != sec[i])
            counts++;
    }
    if(counts != 1)
        return false;
    return true;
}
int BFS(string endWord , unordered_set<string> &wordDict ,
        queue<string> que , int dep)
{

    if(que.empty())
        return 0;
    queue<string> val[2];
    val[0] = que;
    int i = 0;
    while(!val[i].empty())
    {
        dep++;
        while(!val[i].empty())
        {
            string tmp = val[i].front();

            val[i].pop();
            if(onceChange(tmp , endWord))
                return dep;

            for(int j = 0; j < tmp.length(); j++)
            {
                string copys = tmp;
                for(char a = 'a'; a <= 'z'; a++)
                {
                    copys[j] = a;
                    if(wordDict.count(copys) != 0)
                    {
                        val[!i].push(copys);
                        wordDict.erase(copys);
                    }
                }
            }
        }
        i = !i;
    }
    return 0;
}

int ladderLength(string beginWord, string endWord,
                 unordered_set<string>& wordDict)
{
    int pace = 1;
    queue<string> que;
    que.push(beginWord);
    return BFS(endWord , wordDict , que , pace);
}
};
