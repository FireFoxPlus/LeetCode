
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
    ListNode* swapPairs(ListNode* head) {
          if(head == NULL || head->next == NULL)
        return head;
    ListNode *cur = head , *pre = NULL;
    while(cur != NULL)
    {
        if(pre == NULL)
        {
            ListNode *next = cur->next;
            if(next == NULL)
                break;
            cur->next = next->next;
            next->next = cur;
            head = next;
            pre = cur;
            cur = cur->next;
        }
        else
        {
            ListNode *next = cur->next;
            if(next == NULL)
                break;
            cur->next = next->next;
            next->next = cur;
            pre->next = next;
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
    }
};
