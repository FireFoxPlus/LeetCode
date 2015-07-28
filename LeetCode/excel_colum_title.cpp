#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int n) {
         char buf[] = {' ' , 'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' ,
                'I' , 'J' , 'K' , 'L' , 'M' , 'N' , 'O' , 'P' ,
                'Q' , 'R' , 'S' , 'T' , 'U' , 'V' , 'W' , 'X' , 'Y' , 'Z'};
    string rs;

    while(n != 0)
    {
        int tail = n % 26;
        if(tail == 0)
        {
            tail = 26;
            rs.insert(0 , "Z" , 1);
        }
        else
            rs.insert(0 , buf + tail , 1);

        n = n - tail;
        n = n / 26;
    }

    return rs;
    }
};
