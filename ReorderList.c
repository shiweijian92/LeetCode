/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* listReverse(struct ListNode* head)
{
    struct ListNode *p1 = NULL, *p2 = NULL, *p3 = NULL ;
    if(head == NULL || head->next == NULL)
        return head;
    p1 = head;
    p2 = head->next;
    p3 = head->next->next;
    p1->next = NULL;
    while(p3 != NULL)
    {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    return p2;
}
void reorderList(struct ListNode* head) 
{
    struct ListNode *p = head, *left = NULL, *right = NULL, *temp = NULL;
    int i = 1;
    int half = 0;
    
    if(head == NULL || head->next == NULL)
        return head;
    while(p->next != NULL)
    {
        p = p->next;
        i++;
    }
    half = i / 2;
    i = 1;
    p = head;
    while(i < half)
    {
        p = p->next;
        i++;
    }
    right = p->next;
    p->next = NULL;
    right = listReverse(right);
    left = head;
    while(left->next != NULL)
    {
        temp = left->next;
        left->next = right;
        left = temp;
        temp = right->next;
        right->next = left;
        right = temp;
    }
        left->next = right;
}