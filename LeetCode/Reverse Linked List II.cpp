
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

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if(head == NULL)
        return head;
    ListNode *startPre = NULL , *fast = head , *fir;
    int counts = 1;
    while(head != NULL)
    {
        if(counts == m)
            break;
        startPre = fast;
        fast = fast->next;
        counts++;
    }
    fir = fast->next;
    counts++;
    while(counts <= n)
    {
        if(startPre != NULL)
        {
            ListNode *tmp = startPre->next;
            startPre->next = fir;
            fast->next = fir->next;
            fir->next = tmp;
            fir = fast->next;
        }
        else
        {
            head->next = fir->next;
            fir->next = fast;
            ListNode *tmp = fir;
            fir = head->next;
            fast = tmp;
        }
        counts++;
    }
    if(m == 1)
        return fast;
    return head;
}
};
