#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(const char *s) {
     if(s == NULL)
        return 0;
    if(*s == '\0')
        return 0;

    int len = strlen(s);
    char *tail = (char*)(s) + len - 1;
    int counts = 0;
    while(*tail == ' ')
        tail--;

    while(tail >= s)
    {
        if(*tail == ' ')
            break;
        counts++;
        tail--;
    }

    return counts;

    }
};
