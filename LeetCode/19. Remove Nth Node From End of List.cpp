/*19. Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode *p = head;
		vector<int> temp;
		while (p != NULL)
		{
			temp.push_back(p->val);
			p = p->next;
		}
		temp.erase(temp.end() - n);
		if (temp.empty())   return NULL;
		ListNode *ans = new ListNode(temp[0]);
		ListNode *q = ans;
		for (int i = 1; i < temp.size(); i++)
		{
			q->next = new ListNode(temp[i]);
			q = q->next;
		}
		return ans;
	}
};