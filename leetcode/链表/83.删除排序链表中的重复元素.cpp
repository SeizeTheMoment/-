/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL)
        return NULL;
    struct ListNode* p = head;
    struct ListNode* q = head;
    struct ListNode* prev = head;
    struct ListNode* h = head;
    p = p->next;
    while(p!=NULL)
    {
        if(prev->val == p->val)
        {
            q = p;
            prev->next = p->next;
            p = p->next;
            free(q);
        }
        else {
            prev = p;
            p = p->next;
        }
    }
    return h;
}