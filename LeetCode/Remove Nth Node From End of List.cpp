
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n == 0)
        return head;
    if(head == NULL)
        return NULL;
    ListNode *fir = head , *sec = head , *secPre;
    int i;
    for(i = 0; i < n && head != NULL; i++)
        fir = fir->next;
    if(fir == NULL && i < n)
        return NULL;
    if(fir != NULL)
    {
        fir = fir->next;
        secPre = head;
        sec = sec->next;
    }

    while(fir != NULL)
    {
        fir = fir->next;
        sec = sec->next;
        secPre = secPre->next;
    }
    if(sec == head)
    {
        head = head->next;
        free(sec);
    }
    else
    {
        secPre->next = sec->next;
        free(sec);
    }

    return head;
    }
};
