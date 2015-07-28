#include <string>

using namespace std;



class Solution {
public:
    int myAtoi(string::iterator start, string::iterator ends)
{
    int rs = 0;
    while(start != ends)
    {
        rs = rs * 10 + *start - '0';
        start++;
    }
    return rs;
}
    int compareVersion(string version1, string version2) {
         string::iterator ver1 , ver2 , tmp1 , tmp2;
    for(ver1 = version1.begin() , ver2 = version2.begin();
        ver1 != version1.end() && ver2 != version2.end();)
    {
        tmp1 = ver1;
        tmp2 = ver2;
        while(*ver1 != '.' && ver1 != version1.end())
            ver1++;
        while(*ver2 != '.' && ver2 != version2.end())
            ver2++;
        int rs1 = myAtoi(tmp1 , ver1);
        int rs2 = myAtoi(tmp2 , ver2);
        if(rs1 < rs2)
            return -1;
        else if(rs1 > rs2)
            return 1;
        else if(rs1 == rs2 && ver1 == version1.end() && ver2 == version2.end())
            return 0;
        else if(rs1 == rs2)
        {
            if(ver1 != version1.end())
                ver1++;
            if(ver2 != version2.end())
                ver2++;
        }
    }
    if(ver1 == version1.end())
    {
        while(ver2 != version2.end())
        {
            tmp2 = ver2;
            while(*ver2 != '.' && ver2 != version2.end())
                ver2++;
            int rs2 = myAtoi(tmp2 , ver2);
            if(rs2 != 0)
                return -1;
            if(ver2 != version2.end())
                ver2++;
        }
        return 0;
    }
    else if(ver2 == version2.end())
           {
                while(ver1 != version1.end())
                {
                    tmp1 = ver1;
                    while(*ver1 != '.' && ver1 != version1.end())
                        ver1++;
                    int rs1 = myAtoi(tmp1 , ver1);
                    if(rs1 != 0)
                        return 1;
                    if(ver1 != version1.end())
                        ver1++;
                }
                return 0;
            }

    }
};
