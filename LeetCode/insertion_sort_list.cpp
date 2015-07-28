
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
    ListNode *insertionSortList(ListNode *head) {
         if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    ListNode *tmp = head->next , *preTmp = head;
    while(tmp != NULL)
    {
        ListNode *loop = head , *loopPre = NULL;
        while(loop != tmp)
        {
            if(tmp->val < loop->val)
                break;
            loopPre = loop;
            loop = loop->next;
        }
        if(loop != tmp)
        {
            preTmp->next = tmp->next;
            tmp->next = loop;
            if(loopPre != NULL)
                loopPre->next = tmp;
            else
                head = tmp;
            tmp = preTmp->next;
        }
        else
        {
            preTmp = tmp;
            tmp = tmp->next;
        }
    }
    return head;
    }
};
