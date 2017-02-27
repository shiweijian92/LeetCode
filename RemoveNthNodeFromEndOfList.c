/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode** head, int position)
{
    struct ListNode* current = *(head);
    struct ListNode* next = NULL;
    int i = 0;
    
    if(position == 0)
    {
        (*head) = (*head)->next;
        free(current);
        return;
    }
    while(i < position - 1)
    {
        current = current->next;
        i++;
    }
    next = current->next->next;
    free(current->next);
    current->next = next;
    return;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
    int total = 1;
    int position = 0;
    struct ListNode *current = head;
    while(current->next != NULL)
    {
        current = current->next;
        total++;
    }
    position = total - n;
    deleteNode(&head, position);
    return head;
}