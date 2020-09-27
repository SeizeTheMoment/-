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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* L = new ListNode();
        L->next = head;
        ListNode* p = head->next;
        ListNode* q, *prev, *temp;
        head->next = NULL;
        while(p!=NULL)
        {
            q = L->next;
            prev = L;
            while(q!=NULL && q->val<p->val)
            {
                prev = q;
                q = q->next;
            }
            temp = p->next;
            p->next = q;
            prev->next = p;
            p = temp;
        }
        return L->next;
    }
};