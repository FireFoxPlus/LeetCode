/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <stdlib.h>
#include <memory.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return head;
    ListNode *cur = head , *pre = NULL;
    bool hasDel = false;
    while(cur != NULL && cur->next != NULL && cur->val == cur->next->val)
    {
        head = cur->next;
        pre = NULL;
        ListNode *tmp = cur;
        cur = cur->next;
        hasDel = true;
        free(tmp);
    }
    if(hasDel)
    {
        head = cur->next;
        pre = NULL;
        ListNode *tmp = cur;
        cur = cur->next;
        free(tmp);
    }

    while(cur != NULL)
    {
        hasDel = false;
        while(cur != NULL && cur->next != NULL && cur->val == cur->next->val)
        {
            hasDel = true;
            if(pre != NULL)
                pre->next = cur->next;
            ListNode *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        if(hasDel)
        {
            if(pre != NULL)
            {
                ListNode *tmp = pre->next;
                pre->next = cur->next;
                cur = cur->next;
                free(tmp);
            }
            else
            {
                head = cur->next;
                ListNode *tmp = cur;
                cur = cur->next;
                free(tmp);
            }
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }
    }
    return head;
    }
};
