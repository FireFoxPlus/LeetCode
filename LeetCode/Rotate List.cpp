
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
    ListNode* rotateRight(ListNode* head, int k) {
      if(head == NULL)
        return NULL;
        int len = 0;
    ListNode *tmp = head , *copys = head;
    while(tmp != NULL)
    {
        len++;
        tmp = tmp->next;
    }
    k = k % len;
    if(k == 0)
        return head;
    ListNode *fast = head , *slow = head;
    for(int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    head = slow->next;
    slow->next = NULL;
    fast->next = copys;
    return head;
    }
};
