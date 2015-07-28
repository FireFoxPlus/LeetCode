
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

ListNode*  mergeList(ListNode *list1 , ListNode *list2)
{
    if(list2 == NULL && list1 != NULL)
        return list1;
    else if(list2 != NULL && list1 == NULL)
        return list2;
    else if(list1 == NULL && list2 == NULL)
        return NULL;
    ListNode *head , *cur;
    if(list1->val < list2->val)
    {
        head = list1;
        list1 = list1->next;
    }
    else
    {
         head = list2;
         list2 = list2->next;
    }
    cur = head;
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->val < list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
        else
        {
            cur->next =list2;
            list2 = list2->next;
            cur = cur->next;
        }
    }

    if(list2 != NULL)
        cur->next = list2;
    else if(list1 != NULL)
        cur->next = list1;

    return head;
}

ListNode *sortList(ListNode *head)
{
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;
    ListNode *fast = head->next , *slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *head2 = slow->next;
    slow->next = NULL;

    ListNode * rs1 = sortList(head);
    ListNode * rs2 = sortList(head2);

    ListNode * rs = mergeList(rs1 , rs2);
    return rs;
}
};
