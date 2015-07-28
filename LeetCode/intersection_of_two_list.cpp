
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        return NULL;
    int len1 = 0 , len2 = 0;
    ListNode *tmpA  = headA , *tmpB = headB , *pre , *after;
    while(tmpA != NULL)
    {
        len1++;
        tmpA = tmpA->next;
    }
    while(tmpB != NULL)
    {
        len2++;
        tmpB = tmpB->next;
    }
    int toSame = abs(len1 - len2);
    if(len1 > len2)
    {
        pre = headA;
        after = headB;
    }
    else
    {
        pre = headB;
        after = headA;
    }
    for(int i = 0; i < toSame; i++)
        pre = pre->next;

    while(pre != NULL && after != NULL)
    {
        if(pre == after)
            return pre;
        pre = pre->next;
        after = after->next;
    }
    return NULL;
    }
};
