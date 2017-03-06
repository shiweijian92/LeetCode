/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) 
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    if(head == NULL || head->next == NULL)
        return NULL;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            break;
    }
    if(fast == NULL || fast->next == NULL)
        return NULL;
    slow = head;
    while(fast != slow)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}