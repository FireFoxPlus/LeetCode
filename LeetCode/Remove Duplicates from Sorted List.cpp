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
    ListNode *deleteDuplicates(ListNode *head) {
          ListNode *rs = head;
    while(head != NULL)
    {
        int tmp = head->val;
        ListNode *nextNode = head->next;
        while(nextNode != NULL && nextNode->val == tmp)
        {
            ListNode *beDel = nextNode;
            nextNode = nextNode->next;
            free(beDel);
        }
        head->next = nextNode;
        head = nextNode;
    }
    return rs;
    }
};
