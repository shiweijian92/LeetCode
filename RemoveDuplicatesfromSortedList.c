/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) 
{
    struct ListNode *p1 = NULL;
    struct ListNode *p2 = NULL;
    if(head == NULL || head->next ==NULL)
        return head;
    p1 = head;
    p2 = p1->next;
    while(p2 != NULL)
    {
        if(p2->val == p1->val)
        {
            p1->next = p2->next;
            free(p2);
            p2 = p1->next;
        }
        else
        {
            p1 = p2;
            p2 = p1->next;
        }
    }
    return head;
}