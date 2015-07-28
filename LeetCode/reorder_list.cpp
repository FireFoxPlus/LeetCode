
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

bool DFS(ListNode *head , ListNode **inPoi , bool *first)
{
    if(head->next == NULL)
    {
        head->next = (*inPoi)->next;
        (*inPoi)->next = head;
        *inPoi = head->next;
        return false;
    }
    bool rs = DFS(head->next , inPoi , first);
    if((*inPoi)->next == head || (*inPoi) == head || rs)
    {
        if(*first)
        {
            head->next = NULL;
            *first = false;
        }
        return true;
    }
    head->next = (*inPoi)->next;
    (*inPoi)->next = head;
    *inPoi = head->next;
    return false;
}

void reorderList(ListNode *head)
{
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    ListNode *tmp = head;
    bool first = true;
    DFS(head , &tmp , &first);
}

};
