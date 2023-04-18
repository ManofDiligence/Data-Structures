#include <iostream>
#include <vector>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* mergedTwoSortedLinkedList(ListNode* list1, ListNode* list2)
{
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    while(list1!=NULL&&list2)
}