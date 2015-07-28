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
 using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
         if(head == NULL)
        return NULL;
    if(head->next == NULL && head->val == val)
        return NULL;

    //去头
    while(head != NULL && head->val == val)
    {
        ListNode *tmp = head;
        head = head->next;
        free(tmp);
    }
    ListNode *cur = head , *pre;

    while(cur != NULL)
    {
        if(cur->val == val)
        {
            pre->next = cur->next;
            free(cur);
            cur = pre->next;
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
