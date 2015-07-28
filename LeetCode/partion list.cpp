
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
        return head;
    ListNode *preTail = NULL , *cur = head , *preCur = NULL;
    while(cur != NULL)
    {
        if(cur->val < x)
        {
            if(preTail == NULL)
            {
                if(preCur == NULL)
                {
                    preTail = head;
                    preCur = cur;
                    cur = cur->next;
                }
                else
                {
                    preCur->next = cur->next;
                    cur->next = head;
                    head = cur;
                    preTail = head;
                    cur = preCur->next;
                }
            }
            else
            {
                if(preCur != preTail)
                {
                    preCur->next = cur->next;
                    cur->next = preTail->next;
                    preTail->next = cur;
                    preTail = cur;
                    cur = preCur->next;
                }
                else
                {
                    preTail = cur;
                    preCur = cur;
                    cur = cur->next;
                }
            }
        }
        else
        {
            preCur = cur;
            cur = cur->next;
        }
    }
    return head;
    }
};
