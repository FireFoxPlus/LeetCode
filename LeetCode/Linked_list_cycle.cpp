
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
    ListNode *detectCycle(ListNode *head) {
         if(head == NULL || head->next == NULL)
        return NULL;
    ListNode *fast = head , *slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            break;
    }
    if(fast == NULL || fast->next == NULL)
        return NULL;
    ListNode *cycle = head;
    while(true)
    {
        if(cycle == fast)
            return fast;
        cycle = cycle->next;
        fast = fast->next;
    }
    return NULL;
    }
};
