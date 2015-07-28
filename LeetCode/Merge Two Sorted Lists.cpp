/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
     if(l1 == NULL && l2 == NULL)
        return NULL;
    else if(l1 == NULL && l2 != NULL)
        return l2;
    else if(l1 != NULL && l2 == NULL)
        return l1;

    ListNode *rs , *cur;
    if(l1->val < l2->val)
    {
        rs = l1;
        l1 = l1->next;
    }
    else
    {
        rs = l2;
        l2 = l2->next;
    }
    cur = rs;
    while(l1 != NULL && l2 != NULL)
    {
        ListNode *tmp;
        if(l1->val < l2->val)
        {
            tmp = l1;
            l1 = l1->next;
            cur->next = tmp;
            cur = tmp;
        }
        else
        {
            tmp = l2;
            l2 = l2->next;
            cur->next = tmp;
            cur = tmp;
        }
    }


    if(l2 != NULL)
        cur->next = l2;
    if(l1 != NULL)
        cur->next = l1;

    return rs;

    }
};
