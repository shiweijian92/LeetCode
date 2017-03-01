/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) 
{
    struct ListNode* p1 = head;
    struct ListNode* p2 = head;
    struct ListNode* temp = NULL;
    if(p1 == NULL || p1->next == NULL)
        return head;
    head = head->next;
    while(p2->next->next != NULL)
    {
        p1 = p2;
        p2 = p1->next->next;
        p1->next->next = p1;
        if(p2->next ==NULL)
        {
            p1->next = p2;
            return head;
        }
        else
            p1->next = p2->next;
    }
    p1 = p2;
    p1->next->next = p1;
    p1->next = NULL;
    return head;
}